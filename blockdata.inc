<?php

/**
 * @file
 * Create Feedback page.
 */

/**
 * Implements hook_block_view().
 */
function sp_learningmod_block_view($delta = '') {
  // Access user variable.
  global $user;
  // Set variable for current user.
  $account = user_load($user->uid);
  $uid = $account->uid;
  // Load user_plan_choices
  // dpm($account, 'account');.
  $user_plan_choices = field_get_items('user', $account, 'field_learnsp_plan_choices');
  // dpm($account);
  $risk_avg = NULL;
  $success_avg = NULL;
  $impactterm_avg = NULL;
  $lawenforce_avg = NULL;
  $crimeprevent_avg = NULL;
  $score_avg = NULL;
  $implementationcost_avg = NULL;
  $implementationsupport_avg = NULL;
  $isideal_avg = NULL;
  $cad1_avg = NULL;
  $cad6_avg = NULL;
  $cad12_avg = NULL;
  $serious1_avg = NULL;
  $serious6_avg = NULL;
  $serious12_avg = NULL;
  $visp12am1_avg = NULL;
  $visp12am6_avg = NULL;
  $visp12am12_avg = NULL;
  $visj12amv1_avg = NULL;
  $visj12amv6_avg = NULL;
  $visj12amv12_avg = NULL;
  $visj12amf1_avg = NULL;
  $visj12amf6_avg = NULL;
  $visj12amf12_avg = NULL;
  $volparap1_avg = NULL;
  $volparap6_avg = NULL;
  $volparap12_avg = NULL;
  $robbery1_avg = NULL;
  $robbery6_avg = NULL;
  $robbery6_avg = NULL;
  $robbery12_avg = NULL;
  $assaults1_avg = NULL;
  $assaults6_avg = NULL;
  $assaults12_avg = NULL;
  $planbudget = NULL;
  $risk_arr = array();
  $success_arr = array();
  $impactterm_arr = array();
  $impact_arr = array();
  $lawenforce_arr = array();
  $crimeprevent_arr = array();
  $score_arr = array();
  $resptext_arr = array();
  $implementationcost_arr = array();
  $implementationsupport_arr = array();
  $pros_arr = array();
  $cons_arr = array();
  $anticipatedoutcome_arr = array();
  $feedback_arr = array();
  $isideal_arr = array();
  $cad1_arr = array();
  $cad6_arr = array();
  $cad12_arr = array();
  $serious1_arr = array();
  $serious6_arr = array();
  $serious12_arr = array();
  $visp12am1_arr = array();
  $visp12am6_arr = array();
  $visp12am12_arr = array();
  $visj12amv1_arr = array();
  $visj12amv6_arr = array();
  $visj12amv12_arr = array();
  $visj12amf1_arr = array();
  $visj12amf6_arr = array();
  $visj12amf12_arr = array();
  $volparap1_arr = array();
  $volparap6_arr = array();
  $volparap12_arr = array();
  $robbery1_arr = array();
  $robbery6_arr = array();
  $robbery12_arr = array();
  $assaults1_arr = array();
  $assaults6_arr = array();
  $assaults12_arr = array();

  if ($user_plan_choices == FALSE) {
    $form['markup'] = array(
      '#type' => 'markup',
      '#markup' => '<p>Your plan is empty.</p><p>Please return to the <a class="btn btn-primary" href="/learning/prostitution/analyze-problem">Problem Analysis</a> page and make your selections.</p>',
    );
  }
  // If user_responses_list is populated.
  else {
    if (!empty($account->field_learnsp_plan_choices)) {
      for ($i = 0; $i < count($user_plan_choices); $i++) {
        ${'choice_nid_' . $i} = $user_plan_choices[$i]['target_id'];
        ${'node_' . $i} = node_load(${'choice_nid_' . $i});
        ${'node_' . $i . '_title'} = ${'node_' . $i}->title;
        ${'node_' . $i . '_body'} = ${'node_' . $i}->body[LANGUAGE_NONE][0]['safe_value'];
        ${'node' . $i . 'cost'} = ${'node_' . $i}->field_cost[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'risk'} = ${'node_' . $i}->field_risk[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'success'} = ${'node_' . $i}->field_success[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'impactterm'} = ${'node_' . $i}->field_impactterm[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'impact'} = ${'node_' . $i}->field_impact[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'lawenforce'} = ${'node_' . $i}->field_lawenforce[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'crimeprevent'} = ${'node_' . $i}->field_crimeprevent[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'score'} = ${'node_' . $i}->field_score[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'resptext'} = ${'node_' . $i}->field_resptext[LANGUAGE_NONE][0]['safe_value'];
        ${'node' . $i . 'implementationcost'} = ${'node_' . $i}->field_implementationcost[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'implementationsupport'} = ${'node_' . $i}->field_implementationsupport[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'pros'} = ${'node_' . $i}->field_pros[LANGUAGE_NONE][0]['safe_value'];
        ${'node' . $i . 'cons'} = ${'node_' . $i}->field_cons[LANGUAGE_NONE][0]['safe_value'];
        ${'node' . $i . 'anticipatedoutcome'} = ${'node_' . $i}->field_anticipatedoutcome[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'feedback'} = ${'node_' . $i}->field_feedback[LANGUAGE_NONE][0]['safe_value'];
        ${'node' . $i . 'isideal'} = ${'node_' . $i}->field_isideal[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'cad1'} = ${'node_' . $i}->field_cad1[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'cad6'} = ${'node_' . $i}->field_cad6[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'cad12'} = ${'node_' . $i}->field_cad12[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'serious1'} = ${'node_' . $i}->field_serious1[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'serious6'} = ${'node_' . $i}->field_serious6[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'serious12'} = ${'node_' . $i}->field_serious12[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'visp12am1'} = ${'node_' . $i}->field_visp12am1[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'visp12am6'} = ${'node_' . $i}->field_visp12am6[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'visp12am12'} = ${'node_' . $i}->field_visp12am12[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'visj12amv1'} = ${'node_' . $i}->field_visj12amv1[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'visj12amv6'} = ${'node_' . $i}->field_visj12amv6[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'visj12amv12'} = ${'node_' . $i}->field_visj12amv12[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'visj12amf1'} = ${'node_' . $i}->field_visj12amf1[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'visj12amf6'} = ${'node_' . $i}->field_visj12amf6[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'visj12amf12'} = ${'node_' . $i}->field_visj12amf12[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'volparap1'} = ${'node_' . $i}->field_volparap1[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'volparap6'} = ${'node_' . $i}->field_volparap6[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'volparap12'} = ${'node_' . $i}->field_volparap12[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'robbery1'} = ${'node_' . $i}->field_robbery1[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'robbery6'} = ${'node_' . $i}->field_robbery6[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'robbery12'} = ${'node_' . $i}->field_robbery12[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'assaults1'} = ${'node_' . $i}->field_assaults1[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'assaults6'} = ${'node_' . $i}->field_assaults6[LANGUAGE_NONE][0]['value'];
        ${'node' . $i . 'assaults12'} = ${'node_' . $i}->field_assaults12[LANGUAGE_NONE][0]['value'];

        array_push($risk_arr, ${'node' . $i . 'risk'});
        array_push($success_arr, ${'node' . $i . 'success'});
        array_push($impactterm_arr, ${'node' . $i . 'impactterm'});
        array_push($impact_arr, ${'node' . $i . 'impact'});
        array_push($lawenforce_arr, ${'node' . $i . 'lawenforce'});
        array_push($crimeprevent_arr, ${'node' . $i . 'crimeprevent'});
        array_push($score_arr, ${'node' . $i . 'score'});
        array_push($resptext_arr, ${'node' . $i . 'resptext'});
        array_push($implementationcost_arr, ${'node' . $i . 'implementationcost'});
        array_push($implementationsupport_arr, ${'node' . $i . 'implementationsupport'});
        array_push($pros_arr, ${'node' . $i . 'pros'});
        array_push($cons_arr, ${'node' . $i . 'cons'});
        array_push($anticipatedoutcome_arr, ${'node' . $i . 'anticipatedoutcome'});
        array_push($feedback_arr, ${'node' . $i . 'feedback'});
        array_push($isideal_arr, ${'node' . $i . 'isideal'});
        array_push($cad1_arr, ${'node' . $i . 'cad1'});
        array_push($cad6_arr, ${'node' . $i . 'cad6'});
        array_push($cad12_arr, ${'node' . $i . 'cad12'});
        array_push($serious1_arr, ${'node' . $i . 'serious1'});
        array_push($serious6_arr, ${'node' . $i . 'serious6'});
        array_push($serious12_arr, ${'node' . $i . 'serious12'});
        array_push($visp12am1_arr, ${'node' . $i . 'visp12am1'});
        array_push($visp12am6_arr, ${'node' . $i . 'visp12am6'});
        array_push($visp12am12_arr, ${'node' . $i . 'visp12am12'});
        array_push($visj12amv1_arr, ${'node' . $i . 'visj12amv1'});
        array_push($visj12amv6_arr, ${'node' . $i . 'visj12amv6'});
        array_push($visj12amv12_arr, ${'node' . $i . 'visj12amv12'});
        array_push($visj12amf1_arr, ${'node' . $i . 'visj12amf1'});
        array_push($visj12amf6_arr, ${'node' . $i . 'visj12amf6'});
        array_push($visj12amf12_arr, ${'node' . $i . 'visj12amf12'});
        array_push($volparap1_arr, ${'node' . $i . 'volparap1'});
        array_push($volparap6_arr, ${'node' . $i . 'volparap6'});
        array_push($volparap12_arr, ${'node' . $i . 'volparap12'});
        array_push($robbery1_arr, ${'node' . $i . 'robbery1'});
        array_push($robbery6_arr, ${'node' . $i . 'robbery6'});
        array_push($robbery12_arr, ${'node' . $i . 'robbery12'});
        array_push($assaults1_arr, ${'node' . $i . 'assaults1'});
        array_push($assaults6_arr, ${'node' . $i . 'assaults6'});
        array_push($assaults12_arr, ${'node' . $i . 'assaults12'});
      }
    }
  }

  $risk_avg = !empty($risk_arr) ? round(array_sum($risk_arr) / count($risk_arr), 2) : NULL;
  $success_avg = !empty($success_arr) ? round(array_sum($success_arr) / count($success_arr), 2) : NULL;
  $impactterm_avg = !empty($impactterm_arr) ? round(array_sum($impactterm_arr) / count($impactterm_arr), 2) : NULL;
  $lawenforce_avg = !empty($lawenforce_arr) ? round(array_sum($lawenforce_arr) / count($lawenforce_arr), 2) : NULL;
  $crimeprevent_avg = !empty($crimeprevent_arr) ? round(array_sum($crimeprevent_arr) / count($crimeprevent_arr), 2) : NULL;
  $score_avg = !empty($score_arr) ? round(array_sum($score_arr) / count($score_arr), 2) : NULL;
  $implementationcost_avg = !empty($implementationcost_arr) ? round(array_sum($implementationcost_arr) / count($implementationcost_arr), 2) : NULL;
  $implementationsupport_avg = !empty($implementationsupport_arr) ? round(array_sum($implementationsupport_arr) / count($implementationsupport_arr), 2) : NULL;
  $isideal_avg = !empty($isideal_arr) ? round(array_sum($isideal_arr) / count($isideal_arr), 2) : NULL;
  $cad1_avg = !empty($cad1_arr) ? round(array_sum($cad1_arr) / count($cad1_arr), 2) : NULL;
  $cad6_avg = !empty($cad6_arr) ? round(array_sum($cad6_arr) / count($cad6_arr), 2) : NULL;
  $cad12_avg = !empty($cad12_arr) ? round(array_sum($cad12_arr) / count($cad12_arr), 2) : NULL;
  $serious1_avg = !empty($serious1_arr) ? round(array_sum($serious1_arr) / count($serious1_arr), 2) : NULL;
  $serious6_avg = !empty($serious6_arr) ? round(array_sum($serious6_arr) / count($serious6_arr), 2) : NULL;
  $serious12_avg = !empty($serious12_arr) ? round(array_sum($serious12_arr) / count($serious12_arr), 2) : NULL;
  $visp12am1_avg = !empty($visp12am1_arr) ? round(array_sum($visp12am1_arr) / count($visp12am1_arr), 2) : NULL;
  $visp12am6_avg = !empty($visp12am6_arr) ? round(array_sum($visp12am6_arr) / count($visp12am6_arr), 2) : NULL;
  $visp12am12_avg = !empty($visp12am12_arr) ? round(array_sum($visp12am12_arr) / count($visp12am12_arr), 2) : NULL;
  $visj12amv1_avg = !empty($visj12amv1_arr) ? round(array_sum($visj12amv1_arr) / count($visj12amv1_arr), 2) : NULL;
  $visj12amv6_avg = !empty($visj12amv6_arr) ? round(array_sum($visj12amv6_arr) / count($visj12amv6_arr), 2) : NULL;
  $visj12amv12_avg = !empty($visj12amv12_arr) ? round(array_sum($visj12amv12_arr) / count($visj12amv12_arr), 2) : NULL;
  $visj12amf1_avg = !empty($visj12amf1_arr) ? round(array_sum($visj12amf1_arr) / count($visj12amf1_arr), 2) : NULL;
  $visj12amf6_avg = !empty($visj12amf6_arr) ? round(array_sum($visj12amf6_arr) / count($visj12amf6_arr), 2) : NULL;
  $visj12amf12_avg = !empty($visj12amf12_arr) ? round(array_sum($visj12amf12_arr) / count($visj12amf12_arr), 2) : NULL;
  $volparap1_avg = !empty($volparap1_arr) ? round(array_sum($volparap1_arr) / count($volparap1_arr), 2) : NULL;
  $volparap6_avg = !empty($volparap6_arr) ? round(array_sum($volparap6_arr) / count($volparap6_arr), 2) : NULL;
  $volparap12_avg = !empty($volparap12_arr) ? round(array_sum($volparap12_arr) / count($volparap12_arr), 2) : NULL;
  $robbery1_avg = !empty($robbery1_arr) ? round(array_sum($robbery1_arr) / count($robbery1_arr), 2) : NULL;
  $robbery6_avg = !empty($robbery6_arr) ? round(array_sum($robbery6_arr) / count($robbery6_arr), 2) : NULL;
  $robbery6_avg = !empty($robbery6_arr) ? round(array_sum($robbery6_arr) / count($robbery6_arr), 2) : NULL;
  $robbery12_avg = !empty($robbery12_arr) ? round(array_sum($robbery12_arr) / count($robbery12_arr), 2) : NULL;
  $assaults1_avg = !empty($assaults1_arr) ? round(array_sum($assaults1_arr) / count($assaults1_arr), 2) : NULL;
  $assaults6_avg = !empty($assaults6_arr) ? round(array_sum($assaults6_arr) / count($assaults6_arr), 2) : NULL;
  $assaults12_avg = !empty($assaults12_arr) ? round(array_sum($assaults12_arr) / count($assaults12_arr), 2) : NULL;
  $planbudget = isset($account->field_learnsp_plan_budget[LANGUAGE_NONE][0]['value']) ? $account->field_learnsp_plan_budget[LANGUAGE_NONE][0]['value'] : NULL;

  /* Create table items for overall feedback block */
  $header0 = array(
    'blank' => array(
      'data' => '',
      'type' => 'property',
      'specifier' => 'blank',
    ),
    'initval' => array(
      'data' => t('At the time <br>responses&nbsp;were<br> implemented'),
      'type' => 'property',
      'specifier' => 'initval',
    ),
    'onemo' => array(
      'data' => t('1 month after'),
      'type' => 'property',
      'specifier' => 'onemo',
    ),
    'sixmo' => array(
      'data' => t('6 months after'),
      'type' => 'property',
      'specifier' => 'sixmo',
    ),
    'year' => array(
      'data' => t('1 year after'),
      'type' => 'property',
      'specifier' => 'year',
    ),
  );

  $rows0 = array(
    'row1' => array(
      'group' => array(
        'data' => t('Complaints'),
        'colspan' => 5,
      ),
    ),
    'row2' => array(
      'description' => array(
        'data' => t('Calls for police service related to prostitution in target area (CAD records)'),
      ),
      'initval' => array(
        'data' => 141,
      ),
      'onemo' => array(
        'data' => $cad1_avg,
      ),
      'sixmo' => array(
        'data' => $cad6_avg,
      ),
      'year' => array(
        'data' => $cad12_avg,
      ),
    ),
    'row3' => array(
      'group' => array(
        'data' => t('Citizen Survey Data'),
        'colspan' => 5,
      ),
    ),
    'row4' => array(
      'description' => array(
        'data' => t('Seriousness of problem (0-10 scale with 0 not a problem and 10 most serious)'),
      ),
      'initval' => array(
        'data' => 8.3,
      ),
      'onemo' => array(
        'data' => $serious1_avg,
      ),
      'sixmo' => array(
        'data' => $serious6_avg,
      ),
      'year' => array(
        'data' => $serious12_avg,
      ),
    ),
    'row5' => array(
      'group' => array(
        'data' => t('Visibility'),
        'colspan' => 5,
      ),
    ),
    'row6' => array(
      'description' => array(
        'data' => t('Visibility of prostitutes 12am'),
      ),
      'initval' => array(
        'data' => 16,
      ),
      'onemo' => array(
        'data' => $visp12am1_avg,
      ),
      'sixmo' => array(
        'data' => $visp12am6_avg,
      ),
      'year' => array(
        'data' => $visp12am12_avg,
      ),
    ),
    'row7' => array(
      'description' => array(
        'data' => t('Visibility of johns in vehicle 12am'),
      ),
      'initval' => array(
        'data' => 14,
      ),
      'onemo' => array(
        'data' => $visj12amv1_avg,
      ),
      'sixmo' => array(
        'data' => $visj12amv6_avg,
      ),
      'year' => array(
        'data' => $visj12amv12_avg,
      ),
    ),
    'row8' => array(
      'description' => array(
        'data' => t('Visibility of johns on foot 12am'),
      ),
      'initval' => array(
        'data' => 11,
      ),
      'onemo' => array(
        'data' => $visj12amf1_avg,
      ),
      'sixmo' => array(
        'data' => $visj12amf6_avg,
      ),
      'year' => array(
        'data' => $visj12amf12_avg,
      ),
    ),
    'row9' => array(
      'group' => array(
        'data' => t('Paraphernalia'),
        'colspan' => 5,
      ),
    ),
    'row10' => array(
      'description' => array(
        'data' => t('Volume of discarded drug/prostitution paraphernalia'),
      ),
      'initval' => array(
        'data' => 394,
      ),
      'onemo' => array(
        'data' => $volparap1_avg,
      ),
      'sixmo' => array(
        'data' => $volparap6_avg,
      ),
      'year' => array(
        'data' => $volparap12_avg,
      ),
    ),
    'row11' => array(
      'group' => array(
        'data' => t('Crimes'),
        'colspan' => 5,
      ),
    ),
    'row12' => array(
      'description' => array(
        'data' => t('Number of robberies'),
      ),
      'initval' => array(
        'data' => 14,
      ),
      'onemo' => array(
        'data' => $robbery1_avg,
      ),
      'sixmo' => array(
        'data' => $robbery6_avg,
      ),
      'year' => array(
        'data' => $robbery12_avg,
      ),
    ),
    'row13' => array(
      'description' => array(
        'data' => t('Number of assaults'),
      ),
      'initval' => array(
        'data' => 26,
      ),
      'onemo' => array(
        'data' => $assaults1_avg,
      ),
      'sixmo' => array(
        'data' => $assaults6_avg,
      ),
      'year' => array(
        'data' => $assaults12_avg,
      ),
    ),
  );

  $output0 = array(
    'table' => array(
      '#theme' => 'table',
      '#header' => $header0,
      '#rows' => $rows0,
    ),
  );

  /* Create table items for detailed feedback block */
  $header1 = array(
    'yourresp' => array(
      'data' => 'Your responses',
      'type' => 'property',
      'specifier' => 'yourresp',
    ),
    'risk' => array(
      'data' => 'Risk',
      'type' => 'property',
      'specifier' => 'risk',
    ),
    'probs' => array(
      'data' => 'Probability of success',
      'type' => 'property',
      'specifier' => 'probs',
    ),
    'impact' => array(
      'data' => 'Impact',
      'type' => 'property',
      'specifier' => 'impact',
    ),
    'impactlen' => array(
      'data' => 'Impact length',
      'type' => 'property',
      'specifier' => 'impactlen',
    ),
    'lep' => array(
      'data' => 'Law enforcement preference',
      'type' => 'property',
      'specifier' => 'lep',
    ),
    'cpp' => array(
      'data' => 'Crime prevention preference',
      'type' => 'property',
      'specifier' => 'cpp',
    ),
  );
  $rows1 = array();
  if (!empty($account->field_learnsp_plan_choices)) {
    for ($i = 0; $i < count($user_plan_choices); $i++) {
      switch (${'node' . $i . 'risk'}) {
        case 4:
          $riskrate = 'High';
          break;

        case 3:
          $riskrate = 'Moderate';
          break;

        case 2:
          $riskrate = 'Low';
          break;

        case 1:
          $riskrate = 'None';
          break;

        default:
          $riskrate = 'Error';
          break;
      }
      switch (${'node' . $i . 'success'}) {
        case 4:
          $successrate = 'High';
          break;

        case 3:
          $successrate = 'Moderate';
          break;

        case 2:
          $successrate = 'Low';
          break;

        case 1:
          $successrate = 'None';
          break;

        default:
          $successrate = 'Error';
          break;
      }
      switch (${'node' . $i . 'impact'}) {
        case 4:
          $impactrate = 'High';
          break;

        case 3:
          $impactrate = 'Moderate';
          break;

        case 2:
          $impactrate = 'Limited';
          break;

        case 1:
          $impactrate = 'None';
          break;

        default:
          $impactrate = 'Error';
          break;
      }
      switch (${'node' . $i . 'impactterm'}) {
        case 4:
          $impacttermrate = 'Long-term';
          break;

        case 3:
          $impacttermrate = 'Moderate';
          break;

        case 2:
          $impacttermrate = 'Short-term';
          break;

        case 1:
          $impacttermrate = 'None';
          break;

        default:
          $impacttermrate = 'Error';
          break;
      }
      switch (${'node' . $i . 'lawenforce'}) {
        case 4:
          $lawenforcerate = 'High';
          break;

        case 3:
          $lawenforcerate = 'Moderate';
          break;

        case 2:
          $lawenforcerate = 'Low';
          break;

        case 1:
          $lawenforcerate = 'Irresponsible';
          break;

        default:
          $lawenforcerate = 'Error';
          break;
      }
      switch (${'node' . $i . 'crimeprevent'}) {
        case 4:
          $crimepreventrate = 'High';
          break;

        case 3:
          $crimepreventrate = 'Moderate';
          break;

        case 2:
          $crimepreventrate = 'Low';
          break;

        case 1:
          $crimepreventrate = 'Derelict';
          break;

        default:
          $crimepreventrate = 'Error';
          break;
      }
      $rows1[${'choice_nid_' . $i}] = array(
        'title' => ${'node_' . $i . '_title'},
        'riskdat' => $riskrate,
        'probsdat' => $successrate,
        'impactdat' => $impactrate,
        'impactlendat' => $impacttermrate,
        'lepdat' => $lawenforcerate,
        'cppdat' => $crimepreventrate,
      );
    }
  }

  $output1 = array(
    'table' => array(
      '#theme' => 'table',
      '#header' => $header1,
      '#rows' => $rows1,
    ),
  );

  /* Create paragraph items for memo feedback block */

  // p1 (Budget Logic)
  if ($planbudget <= 100) {
    $p1 = array(
      '#markup' => '<div class="underbudget"><p>Thank you for submitting your plan. You have chosen an interesting variety of possible responses and have kept within your budget allocation. Although I have some concerns as noted below, <strong>I am prepared to push ahead and get council approval to implement all your recommendations</strong>.</p></div>',
    );
  }
  else {
    $p1 = array(
      '#markup' => '<div class="overbudget"><p> Thank you for submitting your plan. You have chosen an interesting variety of possible responses, but <strong>unfortunately have gone over budget</strong>. This means that I will have to be very sure that your recommendations are solid before I attempt to get the council&rsquo;s approval.</p></div>',
    );
  }

  // p2_3.
  $p2_3 = array(
    '#markup' => '<p>As I mentioned earlier, I (and the council) would prefer solutions that are long term, and that get at the underlying causes of the problem.</p><p>You recommended the following responses:</p>',
  );

  // p4 List.
  if (!empty($user_plan_choices)) {
    for ($i = 0; $i < count($user_plan_choices); $i++) {
      ${'choice_nid_' . $i} = $user_plan_choices[$i]['target_id'];
      ${'node_' . $i} = node_load(${'choice_nid_' . $i});
      ${'node_' . $i . '_title'} = ${'node_' . $i}->title;
      $items[${'choice_nid_' . $i}] = array(
        'data' => ${'node_' . $i . '_title'},
      );
    }
  }

  $p4 = array(
    '#theme' => 'item_list',
    '#items' => !empty($items) ? $items : NULL,
  );

  // p5.
  $p5 = array(
    '#markup' => '<p>Here are my reactions to your plan:</p>',
  );

  // p6 Risk Average.
  switch (TRUE) {
    case $risk_avg <= 2.5:
      $p6 = array(
        '#markup' => '<p>Your overall plan is <strong>low-risk</strong>. By not recommending any drastic changes, you have avoided the possibility of bad publicity or lawsuits. <strong>Community support for your plan should be high</strong>. However, it may be difficult to effect real change in the current situation without taking some risks.</p>',
      );
      break;

    case $risk_avg > 2.5 && $risk_avg < 3.3:
      $p6 = array(
        '#markup' => '<p>Your overall plan is of <strong>moderate risk</strong>. Although the possibility for conflict, bad publicity, and lawsuits exists, it would be difficult to effect any real change without taking some risks. <strong>Community support for your plan should be good</strong>.</p>',
      );
      break;

    case $risk_avg >= 3.3:
      $p6 = array(
        '#markup' => '<p><strong>You chose a number of high-risk responses</strong> that could result in loss of community support or even unrest, not to mention bad publicity, and the possibility of lawsuits. Some of the changes you have recommended may be too drastic in this situation.</p>',
      );
  }

  // p7 Crime Prevention.
  switch (TRUE) {
    case $crimeprevent_avg <= 2.5:
      $p7 = array(
        '#markup' => '<p>Your overall plan seems <strong>biased against environmental changes</strong>. You have chosen a number of <strong>short-term solutions</strong> which do not address the underlying causes of the problem.</p>',
      );
      break;

    case $crimeprevent_avg > 2.5 && $crimeprevent_avg < 3.3:
      $p7 = array(
        '#markup' => '<p>Your overall plan is <strong>moderately biased towards environmental changes</strong>, which will have <strong>long-term, permanent effects</strong>. Many of your responses get at the underlying cause of the problem.</p>',
      );
      break;

    case $crimeprevent_avg >= 3.3:
      $p7 = array(
        '#markup' => '<p>Your overall plan is <strong>strongly biased towards environmental changes</strong>, which will have <strong>long-term, permanent effects</strong>. Most of your responses get at the underlying causes of the problem.</p>',
      );
  }

  // p8 Law Enforcement.
  switch (TRUE) {
    case $lawenforce_avg <= 2.5:
      $p8 = array(
        '#markup' => '<p>Your overall plan seems <strong>biased against extensive involvement of the criminal justice system</strong>.</p>',
      );
      break;

    case $lawenforce_avg > 2.5 && $lawenforce_avg < 3.3:
      $p8 = array(
        '#markup' => '<p>Your overall plan is <strong>moderate</strong> in terms of the <strong>involvement of the criminal justice and legal systems</strong>.</p>',
      );
      break;

    case $lawenforce_avg >= 3.3:
      $p8 = array(
        '#markup' => '<p>Your overall plan is <strong>biased strongly towards extensive involvement of the criminal justice system</strong>.</p>',
      );
  }

  // p9 Probability of success.
  switch (TRUE) {
    case $success_avg <= 3:
      $p9success = '<strong>low</strong>';
      break;

    case $success_avg > 3 && $success_avg < 4:
      $p9success = '<strong>moderate</strong>';
      break;

    case $success_avg >= 4:
      $p9success = '<strong>high</strong>';
  }

  switch (TRUE) {
    case $impactterm_avg <= 2.5:
      $p9impact = '<strong>short-term</strong>';
      break;

    case $impactterm_avg > 2.5:
      $p9impact = '<strong>long-term</strong>';
      break;
  }

  $p9 = array(
    '#markup' => '<p>From my experience, the probability of the success of your plan is ' . $p9success . '. Your overall plan seems to favor ' . $p9impact . ' <strong>solutions</strong>, <strong><a href="/learning/prostitution/feedback/year-later">but only time will tell</a></strong>.',
  );

  $paragraphs = array(
    'content' => array($p1, $p2_3, $p4, $p5, $p6, $p7, $p8, $p9),
  );

  $output2 = array(
    'content' => array(
      $paragraphs,
    ),
  );

  /* create begin button form that grants "sp_learningmod user" role */

  /**
   * Create simple role granting form
   */
  function sp_learningmod_beginmodule($form, &$form_state) {
    // Access user variable.
    global $user;
    // Set variable for current user.
    $account = user_load($user->uid);

    $sp_role = user_role_load_by_name("sp_learningmod user");

    if (user_is_logged_in()) {
      $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Begin Learning Module'),
        '#attributes' => array('class' => array('btn-lg')),
      );
      $form['actions']['submit']['#submit'][] = 'sp_learningmod_beginmodule_submit';

      return $form;
    }
  }

  /**
   * Role granting form submission callback
   */
  function sp_learningmod_beginmodule_submit($form, $form_state) {
    // Access user variable.
    global $user;
    // Set variable for current user.
    $account = user_load($user->uid);

    $sp_role = user_role_load_by_name("sp_learningmod user");

    if (user_is_logged_in() && !user_has_role($sp_role->rid)) {
      user_multiple_role_edit(array($user->uid), 'add_role', $sp_role->rid);
      // Save user account.
      $account = user_save($account);
      // Set redirect location.
      $_GET['destination'] = '/learning/prostitution/welcome';
    }
    elseif (user_is_logged_in() && user_has_role($sp_role->rid)) {
      $_GET['destination'] = '/learning/prostitution/welcome';
    }
  }

  /* Ideal Plan block data */

  if (!empty($account->field_learnsp_plan_choices)) {
    $idealheader = array(
      'yourresp' => array(
        'data' => 'Your Responses',
        'type' => 'property',
        'specifier' => 'yourresp',
      ),
      'cost' => array(
        'data' => 'Cost',
        'type' => 'property',
        'specifier' => 'cost',
      ),
      'match' => array(
        'data' => 'Match to Ideal?',
        'type' => 'property',
        'specifier' => 'match',
      ),
    );

    $idealp1 = array(
      '#markup' => '<h1>&ldquo;Ideal&rdquo; Plan </h1><p><strong style="text-decoration:underline">There is really no "perfect" plan for the situation in Central City.</strong> We have estimated what the best responses might be, but acknowledge that a combination of alternative responses could yield comparable results. We don\'t want to give the game away by telling you what our ideal plan is, so we have compared your plan to ours, and the table below shows which of your responses matched ours.</p><p class="instructions">Click on a response title to see detailed feedback for that response.</p>',
    );

    for ($i = 0; $i < count($user_plan_choices); $i++) {
      ${'choice_nid_' . $i} = $user_plan_choices[$i]['target_id'];
      ${'node_' . $i} = node_load(${'choice_nid_' . $i});
      ${'node_' . $i . '_title'} = ${'node_' . $i}->title;

      if (${'node' . $i . 'isideal'} == 1) {
        $match = '<span class="text-center idealyes">Yes</span>';
      }
      else {
        $match = '<span class="text-center idealno">No</span>';
      }

      $idealrows[${'choice_nid_' . $i}] = array(
        'title' => '<a class="colorbox-node" href="/node/' . ${'choice_nid_' . $i} . '">' . ${'node_' . $i . '_title'} . '</a>',
        'cost' => ${'node' . $i . 'implementationcost'},
        'match' => $match,
      );
    }

    $idealtable = array(
      'table' => array(
        '#theme' => 'table',
        '#header' => $idealheader,
        '#rows' => $idealrows,
      ),
    );

    $idealp2 = array(
      '#markup' => '<p>Click the links above to see detailed feedback for each response. When you are finished, you may go back to <a href="/learning/prostitution/plan/buildmyplan">re-work your plan</a>, or <a href="/learning/prostitution/evaluation">complete the evaluation</a> to tell us about your experience with this module.</p>',
    );

    $output3 = array(
      'text1' => $idealp1,
      'table' => $idealtable,
      'text2' => $idealp2,
    );
  }

  /* Critical Questions buttons block */
  if ($delta === 'critqbuttons') {
    $origlinks = array(
      'pol_comm_nid' => '/node/add/sp-cq-police-community-members',
      'streetp_nid' => '/node/add/sp-cq-street-prostitutes',
      'clients_nid' => '/node/add/sp-cq-clients-johns',
      'pimps_nid' => '/node/add/sp-cq-pimps',
      'transact_nid' => '/node/add/sp-cq-sexual-transactions',
      'env_nid' => '/node/add/sp-cq-environment',
      'drugs_nid' => '/node/add/sp-cq-drugs',
      'curr_resp_nid' => '/node/add/sp-cq-current-response',
    );

    $query_array = array(
      'uid',
      'pol_comm_nid',
      'streetp_nid',
      'clients_nid',
      'pimps_nid',
      'transact_nid',
      'env_nid',
      'drugs_nid',
      'curr_resp_nid',
    );
    $btn_array = array_slice($query_array, 1);
    $name_array = array(
      'Police and Community Members',
      'Street Prostitutes',
      'Clients / ("Johns")',
      'Pimps',
      'Sexual Transactions',
      'Environment',
      'Drugs',
      'Current Response',
    );

    /**
     * Helper function to create a new array from the keys of two other arrays
     * where the first array becomes the key and the second becomes the value.
     */
    function __array_fill_with_keys($keyArray, $valueArray) {
      if (is_array($keyArray)) {
        foreach ($keyArray as $key => $value) {
          $filledArray[$value] = $valueArray[$key];
        }
      }
      return $filledArray;
    }

    $link_array = __array_fill_with_keys($btn_array, $name_array);
    $query = db_select('sp_critq_visited', 's')
      ->fields('s', $query_array)
      ->condition('uid', $uid);
    $records = $query->execute()->fetchAssoc();
    $get_orig_links = array_intersect_key($origlinks, $link_array);
    $link_name = __array_fill_with_keys($get_orig_links, $link_array);
    $final_array = [];

    foreach ($link_array as $key => $value) {
      if ($records[$key] > 0) {
        // Create link to edit the previously created node.
        $newlink = '<a class="btn btn-secondary" href="/node/' . $records[$key] . '/edit">[Edit] ' . $value . '</a> ';
        ${'render' . $key} = array(
          '#markup' => $newlink,
        );
        array_push($final_array, ${'render' . $key});
      }
      else {
        $cqid = array($key => NULL);
        $matchlink = array_values(array_intersect_key($get_orig_links, $cqid));
        // Create link to the node creation form.
        $origlink = '<a class="btn btn-primary" href="' . $matchlink[0] . '">' . $value . '</a> ';
        ${'render' . $key} = array(
          '#markup' => $origlink,
        );
        array_push($final_array, ${'render' . $key});
      }
    }

    $output4 = array(
      '#prefix' => '<h2>Categories</h2>',
      'final' => $final_array,
    );
  }

  $block = array();
  switch ($delta) {
    case 'yearlater':
      $block['content'] = $output0;
      break;

    case 'analysis':
      $block['content'] = $output1;
      break;

    case 'respmemo':
      $block['content'] = $output2;
      break;

    case 'beginmodule':
      $block['content'] = drupal_get_form('sp_learningmod_beginmodule');
      break;

    case 'idealplan':
      $block['content'] = $output3;
      break;

    case 'critqbuttons':
      $block['content'] = $output4;
  }
  return $block;
}
