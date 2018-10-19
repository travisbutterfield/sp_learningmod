<?php

/**
 * Create My Resources form
 */


function sp_learningmod_myplan() {
  $output = array();
  //access user variable
  global $user;
  //set variable for current user
  $account = user_load($user->uid);
  //load user_plan_choices
  //dpm($account, 'account');
  $user_plan_choices = field_get_items('user', $account, 'field_learnsp_plan_choices');
  //dpm($user_plan_choices, 'user_plan_choices');


  $header = array(
    //'cost' => t('Cost'),
    'res_body' => t('Selected Responses'),
  );
  $rows = array();
    for ($i = 0; $i < sizeof($user_plan_choices); $i++) {
      ${'choice_nid_' . $i} = $user_plan_choices[$i]['nid'];
      ${'node_' . $i} = node_load(${'choice_nid_' . $i});
      ${'node_' . $i . '_body'} = ${'node_' . $i}->body['und'][0]['safe_value'];
      ${'node' . $i . 'cost'} = ${'node_' . $i}->field_cost['und'][0]['value'];
      $rows[${'choice_nid_' . $i}] = array(
        //'cost' => '<strong>' . ${'node' . $i . 'cost'} . '%</strong>',
        'res_body' => ${'node_' . $i . '_body'},
      );
    }

  $table_attributes = array('id' => 'selected-responses', 'align' => 'center');

  return theme('table', array('header' => $header, 'rows' => $rows));

}

