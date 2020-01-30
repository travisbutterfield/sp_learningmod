<?php

/**
 * @file
 * Generate the Admin form.
 */

/**
 * Function to add multiple forms to the same page.
 */
function sp_learningmod_admin() {
  $page['form1'] = drupal_get_form('sp_learningmod_cqreset');
  $page['form2'] = drupal_get_form('sp_learningmod_fullreset');
  return $page;
}

/**
 * Create Critical Questions Reset form.
 */
function sp_learningmod_cqreset($form, &$form_state) {
  global $user;
  $account = user_load($user->uid);

  $form['intro'] = array(
    '#markup' => '<h3>Reset visited critical questions buttons</h3><p>Please enter the Username of the user whose Critical Questions buttons you would like to reset.</p>',
  );

  $form['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;

}

/**
 * Submit function for the Critical Questions Reset form.
 */
function sp_learningmod_cqreset_submit($form, $form_state) {
  /*dpm($form_state, 'form_state');*/
  $username = $form_state['values']['username'];
  $user = user_load_by_name($username);
  $userid = $user->uid;

  // Delete entry from {'sp_critq_visited'} table for selected user.
  try {
    $querys = db_select('sp_critq_visited', 's')->fields('s')->condition('uid', $userid)->execute();
    /*drupal_set_message(t('You have successfully reset uid @userid', array('@userid' => $userid)));*/
    if (!$querys->rowCount()) {
      drupal_set_message("No results");
    }
    else {
      $queryd = db_delete('sp_critq_visited')->condition('uid', $userid)->execute();
      drupal_set_message(t('You have successfully reset user @user', array('@user' => $username)));
    }
  }
  catch (Exception $e) {
    watchdog('sp_learningmod', 'db_delete failed. Message = %message, query= %query',
      array('%message' => $e->getMessage(), '%query' => $e->query_string), WATCHDOG_ERROR);
  }

}

/**
 * Create Full Reset form.
 */
function sp_learningmod_fullreset($form, &$form_state) {
  global $user;
  $account = user_load($user->uid);

  $form['intro'] = array(
    '#markup' => '<h3>Perform full reset of user data</h3><p>Please enter the Username of the user you would like to reset.</p>',
  );

  $form['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;

}

/**
 * Submit function for the Full Reset form.
 */
function sp_learningmod_fullreset_submit($form, $form_state) {
  $username = $form_state['values']['username'];
  $account = user_load_by_name($username);
  $userid = $account->uid;
  $cq_types = array(
    'sp_cq_police_community_members',
    'sp_cq_street_prostitutes',
    'sp_cq_clients_johns',
    'sp_cq_pimps',
    'sp_cq_sexual_transactions',
    'sp_cq_environment',
    'sp_cq_drugs',
    'sp_cq_current_response',
  );
  // Query database table for critical question button entries.
  try {
    $querys = db_select('sp_critq_visited', 's')
      ->fields('s')
      ->condition('uid', $userid)
      ->execute();

    if ($querys->rowCount()) {
      // Delete entry from {'sp_critq_visited'} table for selected user.
      $queryd = db_delete('sp_critq_visited')->condition('uid', $userid)->execute();
      // Query database for all Critical Questions nodes created by user.
      try {
        $results = db_select('node', 'n')
          ->fields('n')
          ->condition('n.type', $cq_types, 'IN')
          ->condition('uid', $userid)
          ->execute();
        foreach ($results as $result) {
          $nids[] = $result->nid;
        }
        if (!empty($nids)) {
          // Delete all Critical Questions nodes created by the user.
          node_delete_multiple($nids);
        }
      }
      catch (Exception $e) {
        watchdog('sp_learningmod', 'node_delete_multiple failed. Message = %message, query= %query',
          array('%message' => $e->getMessage(), '%query' => $e->query_string), WATCHDOG_ERROR);
      }
    }
  }
  catch (Exception $e) {
    watchdog('sp_learningmod', 'db_delete failed on "sp_critq_visited." Message = %message, query= %query',
      array('%message' => $e->getMessage(), '%query' => $e->query_string), WATCHDOG_ERROR);
  }

  // Reset learnSP_analyze_budget.
  $account->field_learnsp_budget[LANGUAGE_NONE][0]['value'] = 0;
  // Reset learnsp_quiz_status.
  $account->field_learnsp_quiz_status[LANGUAGE_NONE][0]['value'] = NULL;
  // Reset learnsp_quiz_score.
  $account->field_learnsp_quiz_score[LANGUAGE_NONE][0]['value'] = 0;
  // Reset learnsp_submitted.
  $account->field_learnsp_submitted[LANGUAGE_NONE][0]['value'] = 'no';
  // Reset learnsp_pages_analyze.
  $account->field_learnsp_pages_analyze[LANGUAGE_NONE] = array();
  // Reset learnsp_responses_revealed.
  $account->field_learnsp_responses_revealed[LANGUAGE_NONE] = array();
  // Reset learnsp_plan_resp_plan_choices.
  $account->field_learnsp_plan_choices[LANGUAGE_NONE] = array();
  // Reset first warning.
  $account->field_learnsp_firstwarn[LANGUAGE_NONE][0]['value'] = 0;
  // Reset final warning.
  $account->field_learnsp_finalwarn[LANGUAGE_NONE][0]['value'] = 0;

  // Save user account.
  $account = user_save($account);
  drupal_set_message(t("You have successfully reset @user's Street Prostitution Learning Module account.", array('@user' => $username)));
}
