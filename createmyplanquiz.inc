<?php

/**
 * Create My Plan quiz form
 */
function sp_learningmod_quiz($form, &$form_state) {
  //create global variable for total number of correct answers
  $total = 0;
  //access user variable
  global $user;
  $account = user_load($user->uid);
  $budget = field_get_items('user', $account, 'field_learnsp_budget');
  // set budget value as integer variable
  $budgetval = (int)$budget[0]['value'];

  // If $form_state['step'] is not set, we set it to 1
  $form_state['step'] = isset($form_state['step']) ? $form_state['step'] : 1;

  // Keep Question number the same for both Question and Answer
  $number = $form_state['step'];
  if ($number == 1) {
    $number;
  }
  else {
    if($number % 2 == 0) {
      $number = $number / 2;
    }
    else {
      $number = ($number + 1) / 2;
    }
  }

  // Add a wrapper div that will be used by the Form API to update the form using AJAX
  if($form_state['step'] < 21) {
    $form['#prefix'] = '<div id="sp_learningmod_quiz"><h2>Question ' . $number . ' of 10</h2>';
  }
  else {
    $form['#prefix'] = '<div id="sp_learningmod_quiz">';
  }

  if($form_state['step'] <= 21) {
  $form['#suffix'] = '<div style="margin: 20px 0;"><a href="/learning/prostitution/analyze-problem">Exit the meeting and return to analysis</a></div></div>';
  }
  else {
    $form['#suffix'] = '</div>';
  }



  // Depending on which step of the form we are on, we output different form fields
  switch($form_state['step'])
  {
    // Question 1
    case 1:
      $default_value = null;
      if(isset($form_state['values']['step_1'])) {
        $default_value = $form_state['values']['step_1'];
      }
      elseif(isset($form_state['storage']['step_1'])) {
        $default_value = $form_state['storage']['step_1'];
      }
      $step_1 = array(
        0 => t('A. Middle-age women seeking male prostitutes.'),
        1 => t('B. Homosexual men seeking male prostitutes.'),
        2 => t('C. Middle-age men seeking teenage and middle-age female prostitutes.'),
        3 => t('D. College-age men seeking college-aged female prostitutes.'),
        4 => t('E. Men of all ages seeking transvestite prostitutes.'),
      );
      $form['step_1'] = array(
        '#title' => t('1. The prostitution problem along Scott Avenue MAINLY involves which of the following?'),
        '#type' => 'radios',
        '#options' => $step_1,
        '#required' => TRUE,
        '#default_value' => $default_value,
      );
    break;

        // Answer 1
    case 2:
      $value = null;
      if(isset($form_state['values']['step_1'])) {
        $value = $form_state['values']['step_1'];
      }
      elseif(isset($form_state['storage']['step_1'])) {
        $value = $form_state['storage']['step_1'];
      }
      $step_1 = array(
        'A. Middle-age women seeking male prostitutes.',
        'B. Homosexual men seeking male prostitutes.',
        'C. Middle-age men seeking teenage and middle-age female prostitutes.',
        'D. College-age men seeking college-aged female prostitutes.',
        'E. Men of all ages seeking transvestite prostitutes.',
      );
      $result = null;
      if($form_state['storage']['step_1'] == 2) {
        $result = t('<h3>Correct</h3><p><strong>You answered: C. Middle-age men seeking teenage and middle-age female prostitutes.</strong></p><p>You are correct.</p><p>This was established in the university research report and supported in many interviews in which the prostitutes are described as female and the clients male.</p>');
      }
      else {
        $result = t('<h3>Incorrect</h3><p><strong>You answered: ' . $step_1[$value] . '</strong></p><p>The correct answer was: C. Middle-age men seeking teenage and middle-age female prostitutes.</p><p>This was established in the university research report and supported in many interviews in which the prostitutes are described as female and the clients male.</p>');
      };
      $form['step_2'] = array(
        '#type' => 'markup',
        '#markup' => $result,
      );
    break;

    //Question 2
    case 3:
      $default_value = null;
      if(isset($form_state['values']['step_3'])) {
        $default_value = $form_state['values']['step_3'];
      }
      elseif(isset($form_state['storage']['step_3'])) {
        $default_value = $form_state['storage']['step_3'];
      }
      $step_3 = array(
        0 => t('A. In nearby motels.'),
        1 => t('B. In clients\' cars.'),
        2 => t('C. Over cellular telephones.'),
        3 => t('D. On the street and at curbside in front of bars.'),
        4 => t('E. In bars with the bartenders serving as the brokers.'),
      );
      $form['step_3'] = array(
        '#title' => t('2. Where do MOST of the negotiations for prostitution take place?'),
        '#type' => 'radios',
        '#options' => $step_3,
        '#required' => TRUE,
        '#default_value' => $default_value,
      );
    break;

    // Answer 2
    case 4:
      $value = null;
      if(isset($form_state['values']['step_3'])) {
        $value = $form_state['values']['step_3'];
      }
      elseif(isset($form_state['storage']['step_3'])) {
        $value = $form_state['storage']['step_3'];
      }
      $step_3 = array(
        'A. In nearby motels.',
        'B. In clients\' cars.',
        'C. Over cellular telephones.',
        'D. On the street and at curbside in front of bars.',
        'E. In bars with the bartenders serving as the brokers.',
      );
      $result = null;
      if($form_state['storage']['step_3'] == 3) {
        $result = t('<h3>Correct</h3><p><strong>You answered: D. On the street and at curbside in front of bars.</strong></p><p>You are correct.</p><p>This was established in the university research report; the electronic surveillance report; and the interviews with the prostitute, Tammy Faith, and client, David Mallard. Negotiations do occur in motels, clients\' cars, over cell phones, and in bars, but not as commonly as on the street.</p>');
      }
      else {
        $result = t('<h3>Incorrect</h3><p><strong>You answered: ' . $step_3[$value] . '</strong></p><p>The correct answer was: D. On the street and at curbside in front of bars.</p><p>This was established in the university research report; the electronic surveillance report; and the interviews with the prostitute, Tammy Faith, and client, David Mallard. Negotiations do occur in motels, clients\' cars, over cell phones, and in bars, but not as commonly as on the street.</p>');
      };
      $form['step_4'] = array(
        '#type' => 'markup',
        '#markup' => $result,
      );
    break;

    //Question 3
    case 5:
      $default_value = null;
      if(isset($form_state['values']['step_5'])) {
        $default_value = $form_state['values']['step_5'];
      }
      elseif(isset($form_state['storage']['step_5'])) {
        $default_value = $form_state['storage']['step_5'];
      }
      $step_5 = array(
        0 => t('A. Bar owners, managers, and staff tolerate and at times facilitate the prostitution trade.'),
        1 => t('B. Police corruptly ignore the prostitution problem by accepting payoffs from prostitutes, pimps and bar owners.'),
        2 => t('C. The owner, manager, and staff of the Secrete Inn tolerate and facilitate the prostitution trade.'),
        3 => t('D. The street drug market\'s clients often are also prostitution clients.'),
        4 => t('E. Many prostitutes are drug-addicted and prostitute themselves to pay for their drug habit.'),
      );
      $form['step_5'] = array(
        '#title' => t('3. Which of the following is NOT a contributing factor to the prostitution problem on Scott Avenue?'),
        '#type' => 'radios',
        '#options' => $step_5,
        '#required' => TRUE,
        '#default_value' => $default_value,
      );
    break;

    // Answer 3
    case 6:
      $value = null;
      if(isset($form_state['values']['step_5'])) {
        $value = $form_state['values']['step_5'];
      }
      elseif(isset($form_state['storage']['step_5'])) {
        $value = $form_state['storage']['step_5'];
      }
      $step_5 = array(
        'A. Bar owners, managers, and staff tolerate and at times facilitate the prostitution trade.',
        'B. Police corruptly ignore the prostitution problem by accepting payoffs from prostitutes, pimps and bar owners.',
        'C. The owner, manager, and staff of the Secrete Inn tolerate and facilitate the prostitution trade.',
        'D. The street drug market\'s clients often are also prostitution clients.',
        'E. Many prostitutes are drug-addicted and prostitute themselves to pay for their drug habit.',
      );
      $result = null;
      if($form_state['storage']['step_5'] == 1) {
        $result = t('<h3>Correct</h3><p><strong>You answered: B. Police corruptly ignore the prostitution problem by accepting payoffs from prostitutes, pimps and bar owners.</strong></p><p>You are correct.</p><p>Although the current police response might be ineffective, there is no evidence that police corruption is a contributing factor.</p>
          <p>The bar owners\' and staffs\' tolerance and facilitation was established in the interviews with Detective Allen; the prostitute, Amy; bar owners, Don Karner and Lucky Petersen; bartender, Rex Blue; student Pete Flash; and the letter to the editor.</p>
          <p>The contribution of sporting events and conventions was established in the interview with the prostitute, Tammy Faith and Officer Ryan.</p>
          <p>The Secrete Inn\'s tolerance was established in the interviews of Detective Wilson; former undercover officer Geoff Tomson; Secrete Inn manager, Bill Webster; and supported by the interview of maid, Mimi Rodriguez, and by the commerce report.</p>
          <p>The link between the drug market and the prostitution trade was established in the interviews with Detective Wright; Officer Fabel; the prostitute, Betty; the client, Jim Paxton; and the police reports on prostitution and cocaine, and narcotics.</p>
          <p>The drug addiction of prostitutes was established in the interviews with the prostitute, Princess; Rev. Francis Powell; and social workers Claire Lambert, Linda Loftin, Kathy Wilkes, and Cathy Lask.</p>');
      }
      else {
        $result = t('<h3>Incorrect</h3><p><strong>You answered: ' . $step_5[$value] . '</strong></p><p>The correct answer was: B. Police corruptly ignore the prostitution problem by accepting payoffs from prostitutes, pimps and bar owners.</p><p>Although the current police response might be ineffective, there is no evidence that police corruption is a contributing factor.</p>
          <p>The bar owners\' and staffs\' tolerance and facilitation was established in the interviews with Detective Allen; the prostitute, Amy; bar owners, Don Karner and Lucky Petersen; bartender, Rex Blue; student Pete Flash; and the letter to the editor.</p>
          <p>The contribution of sporting events and conventions was established in the interview with the prostitute, Tammy Faith and Officer Ryan.</p>
          <p>The Secrete Inn\'s tolerance was established in the interviews of Detective Wilson; former undercover officer Geoff Tomson; Secrete Inn manager, Bill Webster; and supported by the interview of maid, Mimi Rodriguez, and by the commerce report.</p>
          <p>The link between the drug market and the prostitution trade was established in the interviews with Detective Wright; Officer Fabel; the prostitute, Betty; the client, Jim Paxton; and the police reports on prostitution and cocaine, and narcotics.</p>
          <p>The drug addiction of prostitutes was established in the interviews with the prostitute, Princess; Rev. Francis Powell; and social workers Claire Lambert, Linda Loftin, Kathy Wilkes, and Cathy Lask.</p>');
      };
      $form['step_6'] = array(
        '#type' => 'markup',
        '#markup' => $result,
      );
    break;

    //Question 4
    case 7:
      $default_value = null;
      if(isset($form_state['values']['step_7'])) {
        $default_value = $form_state['values']['step_7'];
      }
      elseif(isset($form_state['storage']['step_7'])) {
        $default_value = $form_state['storage']['step_4'];
      }
      $step_7 = array(
        0 => t('A. In clients\' cars.'),
        1 => t('B. In the bars\' bathrooms.'),
        2 => t('C. In nearby hotels.'),
        3 => t('D. In the alleys behind the businesses.'),
        4 => t('E. In the bushes in adjacent residential neighborhoods.'),
      );
      $form['step_7'] = array(
        '#title' => t('4. Where do the sex acts MAINLY take place?'),
        '#type' => 'radios',
        '#options' => $step_7,
        '#required' => TRUE,
        '#default_value' => $default_value,
      );
    break;

    // Answer 4
    case 8:
      $value = null;
      if(isset($form_state['values']['step_7'])) {
        $value = $form_state['values']['step_7'];
      }
      elseif(isset($form_state['storage']['step_7'])) {
        $value = $form_state['storage']['step_7'];
      }
      $step_7 = array(
        'A. In clients\' cars.',
        'B. In the bars\' bathrooms.',
        'C. In nearby hotels.',
        'D. In the alleys behind the businesses.',
        'E. In the bushes in adjacent residential neighborhoods.',
      );
      $result = null;
      if($form_state['storage']['step_7'] == 0) {
        $result = t('<h3>Correct</h3><p><strong>You answered: A. In clients\' cars.</strong></p><p>You are correct.</p><p>The sex acts mainly occur in the clients\' cars. This was established in the interviews of Officer Nelson; the prostitute, Vee Lox; and client, David Mallard. Sex acts do occur in these other locations, but not as commonly as in clients\' cars.</p>');
      }
      else {
        $result = t('<h3>Incorrect</h3><p><strong>You answered: ' . $step_7[$value] . '</strong></p><p>The correct answer was: A. In clients\' cars.</p><p>The sex acts mainly occur in the clients\' cars. This was established in the interviews of Officer Nelson; the prostitute, Vee Lox; and client, David Mallard. Sex acts do occur in these other locations, but not as commonly as in clients\' cars.</p>');
      };
      $form['step_8'] = array(
        '#type' => 'markup',
        '#markup' => $result,
      );
    break;

    //Question 5
    case 9:
      $default_value = null;
      if(isset($form_state['values']['step_9'])) {
        $default_value = $form_state['values']['step_9'];
      }
      elseif(isset($form_state['storage']['step_9'])) {
        $default_value = $form_state['storage']['step_9'];
      }
      $step_9 = array(
        0 => t('A. Some of the clients are in town attending a convention or sporting event.'),
        1 => t('B. Some of the clients are men who live in the community and surrounding areas.'),
        2 => t('C. Some of the clients are married.'),
        3 => t('D. Some clients are local college and high school students looking for fun.'),
        4 => t('E. Many of the clients are very concerned about getting caught.'),
        5 => t('F. All of the above.'),
        6 => t('G. None of the above.'),
      );
      $form['step_9'] = array(
        '#title' => t('5. Which of the following is true?'),
        '#type' => 'radios',
        '#options' => $step_9,
        '#required' => TRUE,
        '#default_value' => $default_value,
      );
    break;

    // Answer 5
    case 10:
      $value = null;
      if(isset($form_state['values']['step_9'])) {
        $value = $form_state['values']['step_9'];
      }
      elseif(isset($form_state['storage']['step_9'])) {
        $value = $form_state['storage']['step_9'];
      }
      $step_9 = array(
        'A. Some of the clients are in town attending a convention or sporting event.',
        'B. Some of the clients are men who live in the community and surrounding areas.',
        'C. Some of the clients are married.',
        'D. Some clients are local college and high school students looking for fun.',
        'E. Many of the clients are very concerned about getting caught.',
        'F. All of the above.',
        'G. None of the above.',
      );
      $result = null;
      if($form_state['storage']['step_9'] == 5) {
        $result = t('<h3>Correct</h3><p><strong>You answered: F. All of the above.</strong></p><p>You are correct.</p><p>The diverse backgrounds of the clients was established in interviews of them; interviews of Officers Fabel and Mosby; and the prostitute, Amy.</p><p>Clients\' concern about getting caught was established in the interviews of Officer Mosby; and clients, Stanley Wiltern and Richard Meyer.</p><p>Clients are from many different walks of life and are not from any particular social of cultural background in Central City. Most of them are very cautious which is why they prefer to make their deals away from the public, preferably in their cars.</p>');
      }
      else {
        $result = t('<h3>Incorrect</h3><p><strong>You answered: ' . $step_9[$value] . '</strong></p><p>The correct answer was: F. All of the above.</p><p>The diverse backgrounds of the clients was established in interviews of them; interviews of Officers Fabel and Mosby; and the prostitute, Amy.</p><p>Clients\' concern about getting caught was established in the interviews of Officer Mosby; and clients, Stanley Wiltern and Richard Meyer.</p><p>Clients are from many different walks of life and are not from any particular social of cultural background in Central City. Most of them are very cautious which is why they prefer to make their deals away from the public, preferably in their cars.</p>');
      };
      $form['step_10'] = array(
        '#type' => 'markup',
        '#markup' => $result,
      );
    break;

    //Question 6
    case 11:
      $default_value = null;
      if(isset($form_state['values']['step_11'])) {
        $default_value = $form_state['values']['step_11'];
      }
      elseif(isset($form_state['storage']['step_11'])) {
        $default_value = $form_state['storage']['step_11'];
      }
      $step_11 = array(
        0 => t('A. Closure of streets to change traffic patterns.'),
        1 => t('B. Arrests of prostitutes and clients and police patrol in the area.'),
        2 => t('C. Relaxation of the regulation of indoor prostitution.'),
        3 => t('D. Redevelopment of the area.'),
        4 => t('E. Diversion of prostitutes into drug rehabilitation.'),
      );
      $form['step_11'] = array(
        '#title' => t('6. What is the CURRENT main police department response to street prostitution in Central City?'),
        '#type' => 'radios',
        '#options' => $step_11,
        '#required' => TRUE,
        '#default_value' => $default_value,
      );
    break;

    // Answer 6
    case 12:
      $value = null;
      if(isset($form_state['values']['step_11'])) {
        $value = $form_state['values']['step_11'];
      }
      elseif(isset($form_state['storage']['step_11'])) {
        $value = $form_state['storage']['step_11'];
      }
      $step_11 = array(
        'A. Closure of streets to change traffic patterns.',
        'B. Arrests of prostitutes and clients and police patrol in the area.',
        'C. Relaxation of the regulation of indoor prostitution.',
        'D. Redevelopment of the area.',
        'E. Diversion of prostitutes into drug rehabilitation.',
      );
      $result = null;
      if($form_state['storage']['step_11'] == 1) {
        $result = t('<h3>Correct</h3><p><strong>You answered: B. Arrests of prostitutes and clients and police patrol in the area.</strong></p><p>You are right. The primary responses of the Central City police have been to patrol the area, move prostitutes along, and send in the vice squad to make arrests. This was established in the interviews of Officer Jordan, Detective Allen, Officer Ryan, Detective Wilson, Officer Rickels, and Commander Rule, and the police report on sex offenses.</p><p>Although some prostitutes end up in drug rehab in Central City it is not the primary police response and there is no reported attempt to divert them away from the criminal justice system. Relaxing the regulation of indoor prostitution (in massage parlors, brothels, or strip clubs), redeveloping the area or changing traffic patterns have to date not been considered.</p>');
      }
      else {
        $result = t('<h3>Incorrect</h3><p><strong>You answered: ' . $step_11[$value] . '</strong></p><p>The correct answer was: B. Arrests of prostitutes and clients and police patrol in the area.</p><p>The primary responses of the Central City police have been to patrol the area, move prostitutes along, and send in the vice squad to make arrests. This was established in the interviews of Officer Jordan, Detective Allen, Officer Ryan, Detective Wilson, Officer Rickels, and Commander Rule, and the police report on sex offenses.</p><p>Although some prostitutes end up in drug rehab in Central City it is not the primary police response and there is no reported attempt to divert them away from the criminal justice system. Relaxing the regulation of indoor prostitution (in massage parlors, brothels, or strip clubs), redeveloping the area or changing traffic patterns have to date not been considered.</p>');
      };
      $form['step_12'] = array(
        '#type' => 'markup',
        '#markup' => $result,
      );
    break;

    //Question 7
    case 13:
      $default_value = null;
      if(isset($form_state['values']['step_13'])) {
        $default_value = $form_state['values']['step_13'];
      }
      elseif(isset($form_state['storage']['step_13'])) {
        $default_value = $form_state['storage']['step_13'];
      }
      $step_13 = array(
        0 => t('A. They cruise the area looking for prostitutes they know.'),
        1 => t('B. A pimp acts as the middle-man.'),
        2 => t('C. They call prostitutes on their cell phones and arrange to meet in Lucky\'s Bar.'),
        3 => t('D. They answer advertisements in local newspapers.'),
        4 => t('E. They call numbers written on toilet walls.'),
      );
      $form['step_13'] = array(
        '#title' => t('7. How do clients find prostitutes?'),
        '#type' => 'radios',
        '#options' => $step_13,
        '#required' => TRUE,
        '#default_value' => $default_value,
      );
    break;

    // Answer 7
    case 14:
      $value = null;
      if(isset($form_state['values']['step_13'])) {
        $value = $form_state['values']['step_13'];
      }
      elseif(isset($form_state['storage']['step_13'])) {
        $value = $form_state['storage']['step_13'];
      }
      $step_13 = array(
        'A. They cruise the area looking for prostitutes they know.',
        'B. A pimp acts as the middle-man.',
        'C. They call prostitutes on their cell phones and arrange to meet in Lucky\'s Bar.',
        'D. They answer advertisements in local newspapers.',
        'E. They call numbers written on toilet walls.',
      );
      $result = null;
      if($form_state['storage']['step_13'] == 0) {
        $result = t('<h3>Correct</h3><p><strong>You answered: A. They cruise the area looking for prostitutes they know.</strong></p><p>You are correct.</p><p>This is established by the electronic surveillance report; and in interviews with clients, Rick Sampier, Richard Meyer, and Stanley Wiltern. It is well known that driving down Scott Avenue clients will find prostitutes in certain areas, usually around Lucky\'s Bar, or other areas that are run down or near abandoned buildings. Investigators do not report that pimps are operating on Scott Avenue.</p>');
      }
      else {
        $result = t('<h3>Incorrect</h3><p><strong>You answered: ' . $step_13[$value] . '</strong></p><p>The correct answer was: A. They cruise the area looking for prostitutes they know.</p><p>This is established by the electronic surveillance report; and in interviews with clients, Rick Sampier, Richard Meyer, and Stanley Wiltern. It is well known that driving down Scott Avenue clients will find prostitutes in certain areas, usually around Lucky\'s Bar, or other areas that are run down or near abandoned buildings. Investigators do not report that pimps are operating on Scott Avenue.</p>');
      };
      $form['step_14'] = array(
        '#type' => 'markup',
        '#markup' => $result,
      );
    break;

    //Question 8
    case 15:
      $default_value = null;
      if(isset($form_state['values']['step_15'])) {
        $default_value = $form_state['values']['step_15'];
      }
      elseif(isset($form_state['storage']['step_15'])) {
        $default_value = $form_state['storage']['step_15'];
      }
      $step_15 = array(
        0 => t('A. Decreased citizen complaints about street prostitution.'),
        1 => t('B. Increased arrests of clients and prostitutes.'),
        2 => t('C. Decreased number of prostitutes visible on the streets at particular times.'),
        3 => t('D. Decreased calls for service from Scott Avenue area.'),
        4 => t('E. All of the above are reliable measures.'),
        5 => t('F. None of the above are reliable measures.'),
      );
      $form['step_15'] = array(
        '#title' => t('8. Which is NOT a reliable measure of success after plan implementation?'),
        '#type' => 'radios',
        '#options' => $step_15,
        '#required' => TRUE,
        '#default_value' => $default_value,
      );
    break;

    // Answer 8
    case 16:
      $value = null;
      if(isset($form_state['values']['step_15'])) {
        $value = $form_state['values']['step_15'];
      }
      elseif(isset($form_state['storage']['step_15'])) {
        $value = $form_state['storage']['step_15'];
      }
      $step_15 = array(
        'A. Decreased citizen complaints about street prostitution.',
        'B. Increased arrests of clients and prostitutes.',
        'C. Decreased number of prostitutes visible on the streets at particular times.',
        'D. Decreased calls for service from Scott Avenue area.',
        'E. All of the above are reliable measures.',
        'F. None of the above are reliable measures.',
      );
      $result = null;
      if($form_state['storage']['step_15'] == 1) {
        $result = t('<h3>Correct</h3><p><strong>You answered: B. Increased arrests of clients and prostitutes.</strong></p><p>You are correct.</p><p>The volume of arrests (whether an increase or decrease) is not necessarily a valid indicator of success; it might merely reflect the level of police activity in dealing with the problem. Measuring the number of arrests may be important, but only in the proper context (for example, if the level of police effort to make arrests could be controlled for, then the number of arrests made might be a valid measure of the level of prostitution activity). Ultimately, police want prostitution in the area to cease, and constantly increasing arrest rates would suggest that is not occurring. The mayor acknowledged in the news article that a doubling of prostitution arrests has not solved the problem and the police report on sex offenses confirms this.</p>');
      }
      else {
        $result = t('<h3>Incorrect</h3><p><strong>You answered: ' . $step_15[$value] . '</strong></p><p>The correct answer was: B. Increased arrests of clients and prostitutes.</p><p>The volume of arrests (whether an increase or decrease) is not necessarily a valid indicator of success; it might merely reflect the level of police activity in dealing with the problem. Measuring the number of arrests may be important, but only in the proper context (for example, if the level of police effort to make arrests could be controlled for, then the number of arrests made might be a valid measure of the level of prostitution activity). Ultimately, police want prostitution in the area to cease, and constantly increasing arrest rates would suggest that is not occurring. The mayor acknowledged in the news article that a doubling of prostitution arrests has not solved the problem and the police report on sex offenses confirms this.</p>');
      };
      $form['step_16'] = array(
        '#type' => 'markup',
        '#markup' => $result,
      );
    break;

    //Question 9
    case 17:
      $default_value = null;
      if(isset($form_state['values']['step_17'])) {
        $default_value = $form_state['values']['step_17'];
      }
      elseif(isset($form_state['storage']['step_17'])) {
        $default_value = $form_state['storage']['step_17'];
      }
      $step_17 = array(
        0 => t('A. In the upper end of Scott Avenue (the 1200-1400 blocks).'),
        1 => t('B. There is no concentration; reported crimes and arrests are evenly distributed throughout the area.'),
        2 => t('C. In the residential neighborhoods south of Scott Avenue.'),
        3 => t('D. In the lower end of Scott Avenue (the 200-300 blocks).'),
        4 => t('E. None of the above.'),
      );
      $form['step_17'] = array(
        '#title' => t('9. Where are reported crimes and arrests of all types most heavily concentrated?'),
        '#type' => 'radios',
        '#options' => $step_17,
        '#required' => TRUE,
        '#default_value' => $default_value,
      );
    break;

    // Answer 9
    case 18:
      $value = null;
      if(isset($form_state['values']['step_17'])) {
        $value = $form_state['values']['step_17'];
      }
      elseif(isset($form_state['storage']['step_17'])) {
        $value = $form_state['storage']['step_17'];
      }
      $step_17 = array(
        'A. In the upper end of Scott Avenue (the 1200-1400 blocks).',
        'B. There is no concentration; reported crimes and arrests are evenly distributed throughout the area.',
        'C. In the residential neighborhoods south of Scott Avenue.',
        'D. In the lower end of Scott Avenue (the 200-300 blocks).',
        'E. None of the above.',
      );
      $result = null;
      if($form_state['storage']['step_17'] == 3) {
        $result = t('<h3>Correct</h3><p><strong>You answered: D. In the lower end of Scott Avenue (the 200-300 blocks)</strong>.</p><p>You are correct.</p><p>This is clearly established on the crime and arrest maps; in the interviews with Detectives Wright and Allen, and Officer Fabel; and in the electronic surveillance report.</p>');
      }
      else {
        $result = t('<h3>Incorrect</h3><p><strong>You answered: ' . $step_17[$value] . '</strong></p><p>The correct answer was: D. In the lower end of Scott Avenue (the 200-300 blocks).</p><p>This is clearly established on the crime and arrest maps; in the interviews with Detectives Wright and Allen, and Officer Fabel; and in the electronic surveillance report.</p>');
      };
      $form['step_18'] = array(
        '#type' => 'markup',
        '#markup' => $result,
      );
    break;

    //Question 10
    case 19:
      $default_value = null;
      if(isset($form_state['values']['step_19'])) {
        $default_value = $form_state['values']['step_19'];
      }
      elseif(isset($form_state['storage']['step_19'])) {
        $default_value = $form_state['storage']['step_19'];
      }
      $step_19 = array(
        0 => t('A. Discarded waste (condoms and syringes) is unsightly and hazardous.'),
        1 => t('B. Prostitutes are commonly injured in assaults by clients.'),
        2 => t('C. Legitimate business is being disrupted by prostitution.'),
        3 => t('D. Citizen confidence in the police is being eroded.'),
        4 => t('E. Girls as young as 12 are being kidnapped and trafficked to other cities to work as prostitutes.'),
      );
      $form['step_19'] = array(
        '#title' => t('10. Which of the following is NOT among the specific harms being caused by street prostitution in Central City?'),
        '#type' => 'radios',
        '#options' => $step_19,
        '#required' => TRUE,
        '#default_value' => $default_value,
      );
    break;

    // Answer 10
    case 20:
      $value = null;
      if(isset($form_state['values']['step_19'])) {
        $value = $form_state['values']['step_19'];
      }
      elseif(isset($form_state['storage']['step_19'])) {
        $value = $form_state['storage']['step_19'];
      }
      $step_19 = array(
        'A. Discarded waste (condoms and syringes) is unsightly and hazardous.',
        'B. Prostitutes are commonly injured in assaults by clients.',
        'C. Legitimate business is being disrupted by prostitution.',
        'D. Citizen confidence in the police is being eroded.',
        'E. Girls as young as 12 are being kidnapped and trafficked to other cities to work as prostitutes.',
      );
      $result = null;
      if($form_state['storage']['step_19'] == 4) {
        $result = t('<h3>Correct</h3><p><strong>You answered: E. Girls as young as 12 are being kidnapped and trafficked to other cities to work as prostitutes.</strong></p><p>You are correct.</p><p>There is no evidence of kidnapping and trafficking of young girls.</p><p>Concerns about discarded waste (condoms and used syringes) was established in the interview of resident, Chris Glatz; the public health article; and the police discarded articles report.</p><p>Prostitutes\' injuries from assaults by clients was established in the interviews of nurse, Shari Williams; social workers, Linda Loftin and Cathy Lask; and supported (although not established) by the EMS run sheet report and the police crime statistics report.</p><p>The disruption to legitimate business was established in the letter to the editor; the interviews with Theodore Howell, Alderperson Stephen Bets, residents Wanda Fops and Randy Bright, senior home director, Melvin Goodrich; the citizen survey; and the commerce report.</p>');
      }
      else {
        $result = t('<h3>Incorrect</h3><p><strong>You answered: ' . $step_19[$value] . '</strong></p><p>The correct answer was: E. Girls as young as 12 are being kidnapped and trafficked to other cities to work as prostitutes.</p><p>There is no evidence of kidnapping and trafficking of young girls.</p><p>Concerns about discarded waste (condoms and used syringes) was established in the interview of resident, Chris Glatz; the public health article; and the police discarded articles report.</p><p>Prostitutes\' injuries from assaults by clients was established in the interviews of nurse, Shari Williams; social workers, Linda Loftin and Cathy Lask; and supported (although not established) by the EMS run sheet report and the police crime statistics report.</p><p>The disruption to legitimate business was established in the letter to the editor; the interviews with Theodore Howell, Alderperson Stephen Bets, residents Wanda Fops and Randy Bright, senior home director, Melvin Goodrich; the citizen survey; and the commerce report.</p>');
      };
      $form['step_20'] = array(
        '#type' => 'markup',
        '#markup' => $result,
      );
    break;

    // Failed page
    case 21:
      global $total;
      if($budgetval <= 100) {
        $spending = 'However, you have only spent <strong>' . $budgetval . '%</strong> of the budget. So, you have some room in the budget for more in-depth analysis. I suggest you <a href="/learning/prostitution/analyze-problem">continue your investigation</a> so you can better answer the city council’s questions.</p><p>Please note that I will only allow a 20% overage of the analysis budget, but I strongly recommend you try to stay within the limit already set.</p>';
      }
      elseif($budgetval > 100 && $budgetval < 120) {
        $spending = 'Also, in spending <strong>' . $budgetval . '%</strong> of the budget, you have not been very efficient. I hope the results of your investigation prove to be worth the investment. I suggest you <a href="/learning/prostitution/analyze-problem">review the results of your investigation</a> and then try to answer the city council’s questions again.</p><p>Please note that I will only allow a 20% overage of the analysis budget, so, make sure to keep an eye on your budget. If you overspend, you will be summarily fired and have to start over from scratch.</p>';
      }
      $form['step_21'] = array(
      '#type' => 'markup',
      '#markup' => '<div id="paper"> <img src="/sites/default/files/cc-logo.gif" alt="Central City logo" class="floatright" width="108" height="76">
  <img src="/sites/default/files/cc-lh-coleman.gif" alt="Mark L. Coleman, Office of the Mayor " width="165" height="85"><h3>Memorandum</h3><h2>You need to do more research!</h2><p><strong>You scored ' . $total . '/10.</strong></p><p class="warn">You have failed to answer at least 80% of the City Council’s questions correctly!</p><p>I am extremely disappointed! Your analysis revealed inaccurate information. ' . $spending . '<p>You may also forge ahead to <a href="/learning/prostitution/my-plan">create your plan</a>, but be warned that choosing responses based on incomplete information could be disastrous. If you decide to move ahead with creating your plan, you will receive a new budget, which I hope you will spend wisely.</p><p><img src="/sites/default/files/memo_r3_c1.gif" alt="" width="152" height="48"></p><p>M.L. Coleman</p></div>'
      );
      $total = 0;
    break;

    // Success page
    case 22:
      global $total;
       if($budgetval <= 100) {
        $spending = 'However, you have only spent <strong>' . $budgetval . '%</strong> of the budget. So, you have some room in the budget for more in-depth analysis. I suggest you <a href="/learning/prostitution/analyze-problem">continue your investigation</a> so you can better answer the city council’s questions.</p><p>Please note that I will only allow a 20% overage of the analysis budget, but I strongly recommend you try to stay within the limit already set.</p>';
      }
      elseif($budgetval > 100 && $budgetval < 120) {
        $spending = 'However, in spending <strong>' . $budgetval . '%</strong> of the budget, you have not been very efficient. I hope the results of your investigation prove to be worth the investment.</p>';
      }
      $form['step_22'] = array(
      '#type' => 'markup',
      '#markup' => '<div id="paper"> <img src="/sites/default/files/cc-logo.gif" alt="Central City logo" class="floatright" width="108" height="76">
  <img src="/sites/default/files/cc-lh-coleman.gif" alt="Mark L. Coleman, Office of the Mayor " width="165" height="85"><h3>Memorandum</h3><h2>Excellent!</h2><p><strong>You scored ' . $total . '/10.</strong></p>Since your score meets the required 80% and you completed your analysis within the budget constraints I provided, you may now proceed to build your plan. ' . $spending . ' <p>As you begin the plan-building process, please evaluate the revealed responses and decide which ones are best suited for your response plan.</p><p>I am giving you a new budget for creating your plan, which I hope you will spend wisely.</p>
        <p><img src="/sites/default/files/memo_r3_c1.gif" alt="" width="152" height="48"></p><p>M.L. Coleman</p><p class="txtcenter"><a class="btn btn-primary btn-lg" href="/learning/prostitution/my-plan">Start my plan</a></p></div>'
      );
      $total = 0;
    break;
  }

    // Create a container for our buttons
    $form['buttons'] = array(
      '#type' => 'container',
    );
    // We only want a forward button if we are not on the last step of the form
    if($form_state['step'] < 20)
    {
      $form['buttons']['forward'] = array(
        '#type' => 'submit',
        '#value' => t('Continue'),
        '#ajax' => array(
          // We pass in the wrapper we created at the start of the form
          'wrapper' => 'sp_learningmod_quiz',
          // We pass a callback function we will use later to render the form for the user
          'callback' => 'sp_learningmod_quiz_ajax_callback',
        ),
      );
    }
    // We only want a submit button if we are on the last step of the form
    elseif($form_state['step'] == 20)
    {
      $form['buttons']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Continue'),
        '#ajax' => array(
          // We pass in the wrapper we created at the start of the form
          'wrapper' => 'sp_learningmod_quiz',
          // We pass a callback function we will use later to render the form for the user
          'callback' => 'sp_learningmod_quiz_ajax_callback',
        ),
      );
    };

    // We always need to return the form
    return $form;
}

function sp_learningmod_quiz_submit($form, &$form_state) {
  // First we determine which step we are on, and save the
  // submitted values to $form_state['storage']. This will
  // allow our submitted values to persist.
  $step = $form_state['step'];
  $form_state['storage']['step_' . $step] = $form_state['values']['step_' . $step];

  // Check to see if the next/forward button was clicked
  if(isset($form_state['values']['forward']) && $form_state['values']['op'] == $form_state['values']['forward']) {
    // Increase the step by one, to move on to the next step
    $form_state['step']++;
  }
  // Check to see if the final step has been submitted
  elseif(isset($form_state['values']['submit']) && $form_state['values']['op'] == $form_state['values']['submit']) {

    $items = array(
      $form_state['storage']['step_1'],
      $form_state['storage']['step_3'],
      $form_state['storage']['step_5'],
      $form_state['storage']['step_7'],
      $form_state['storage']['step_9'],
      $form_state['storage']['step_11'],
      $form_state['storage']['step_13'],
      $form_state['storage']['step_15'],
      $form_state['storage']['step_17'],
      $form_state['storage']['step_19'],
    );
    //create an array of the correct answer rubric
    $correct = array(2, 3, 1, 0, 5, 1, 0, 1, 3, 4,);
    //create an array that compares the user's score against rubric
    $score = array(
      $score1 = $items[0] == $correct[0] ? '1' : '0',
      $score2 = $items[1] == $correct[1] ? '1' : '0',
      $score3 = $items[2] == $correct[2] ? '1' : '0',
      $score4 = $items[3] == $correct[3] ? '1' : '0',
      $score5 = $items[4] == $correct[4] ? '1' : '0',
      $score6 = $items[5] == $correct[5] ? '1' : '0',
      $score7 = $items[6] == $correct[6] ? '1' : '0',
      $score8 = $items[7] == $correct[7] ? '1' : '0',
      $score9 = $items[8] == $correct[8] ? '1' : '0',
      $score10 = $items[9] == $correct[9] ? '1' : '0',
    );

    //Loop through user's scores to tally number of correct answers
    global $total;
    foreach ($score as $val) {
      if($val == '1' ) {
        $total++;
      }
    }

    if($total < 8){
      $form_state['step'] = 21;
    }
    else {
      $form_state['step'] = 22;
    }
    //clear any saved values.
    $form_state['storage'] = array();
  }

  // As in ajax_form_multistep_form_back_submit(), we need to set
  // $form_state['rebuild'] to TRUE, in able to ensure that our
  // our form is rebuilt, allowing for the multi-step process
  $form_state['rebuild'] = TRUE;
}

function sp_learningmod_quiz_ajax_callback($form, &$form_state) {
  return $form;
}
