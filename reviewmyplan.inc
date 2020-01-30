<?php

/**
 * @file
 * Create My Plan form.
 */

/**
 * Review My Plan page.
 */
function sp_learningmod_reviewmyplan() {
  $output = array();
  // Access user variable.
  global $user;
  // Set variable for current user.
  $account = user_load($user->uid);
  // Load user_plan_choices
  // dpm($account, 'account');.
  $user_plan_choices = field_get_items('user', $account, 'field_learnsp_plan_choices');
  // dpm($user_plan_choices, 'user_plan_choices');.
  if ($user_plan_choices == FALSE) {
    $form['markup'] = array(
      '#type' => 'markup',
      '#markup' => '<p>Your plan is empty.</p><p>Please return to the <a class="btn btn-primary" href="/learning/prostitution/analyze-problem">Problem Analysis</a> page and make your selections.</p>',
    );
  }
  // If user_responses_list is populated.
  else {

    $header = array(
      'cost' => t('Cost'),
      'res_body' => t('Selected Responses'),
    );
    $rows = array();
    $total = NULL;
    for ($i = 0; $i < count($user_plan_choices); $i++) {
      ${'choice_nid_' . $i} = $user_plan_choices[$i]['target_id'];
      ${'node_' . $i} = node_load(${'choice_nid_' . $i});
      ${'node_' . $i . '_body'} = ${'node_' . $i}->body['und'][0]['safe_value'];
      ${'node' . $i . 'cost'} = ${'node_' . $i}->field_cost['und'][0]['value'];
      $rows[${'choice_nid_' . $i}] = array(
        'cost' => '<strong>' . (int) ${'node' . $i . 'cost'} . '%</strong>',
        'res_body' => ${'node_' . $i . '_body'},
      );
      $subtotal = (int) ${'node' . $i . 'cost'};
      $total += $subtotal;
    }

    $table_attributes = array('id' => 'selected-responses', 'align' => 'center');
    $totaltext = '<h3 class="totalbudget">Total amount of budget being allocated: <strong>' . $total . '%</strong></h3>';
    $table = theme('table', array('header' => $header, 'rows' => $rows));

    $goback = '<div><span style="margin-right: 1em;"><a class="plancontinue btn btn-secondary" href="/learning/prostitution/plan/buildmyplan">Go back to Build My Plan</a></span></div>';

    $submitbutton = drupal_get_form('sp_learningmod_submitplan');

    return $table . $totaltext . $goback . drupal_render($submitbutton);

  }

}

/* Build My Plan Submit Button mini-form */

/**
 * Create simple form for submit button.
 */
function sp_learningmod_submitplan($form, &$form_state) {
  // Access user variable.
  global $user;
  // Set variable for current user.
  $account = user_load($user->uid);
  $sp_role = user_role_load_by_name("sp_learningmod user");
  $sp_submitted = isset($account->field_learnsp_submitted[LANGUAGE_NONE][0]['value']) ? $account->field_learnsp_submitted[LANGUAGE_NONE][0]['value'] : 'no';

  if ($sp_submitted !== 'yes') {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit My Plan'),
      '#attributes' => array('class' => array('btn-lg')),
    );
  }
  else {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Re-Submit My Plan'),
      '#attributes' => array('class' => array('btn-lg')),
    );
  }

  return $form;
}

/**
 * My Plan Submission Callback.
 */
function sp_learningmod_submitplan_submit($form, $form_state) {
  // Access user variable.
  global $user;
  // Set variable for current user.
  $account = user_load($user->uid);
  $accountid = $account->uid;

  $account->field_learnsp_submitted[LANGUAGE_NONE][0]['value'] = 'yes';
  // Save user account.
  $account = user_save($account);
  // Set redirect location.
  $sp_js = array(
    'spSubmitted' . $accountid => 'yes',
  );

  drupal_add_js(array('sp_learningmod' => $sp_js), 'setting');

  $_GET['destination'] = '/learning/prostitution/feedback/mayors-response';

}
