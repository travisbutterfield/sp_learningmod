<?php

/**
 * @file
 * My Responses page.
 */

/**
 * Create My Responses form.
 */
function sp_learningmod_myresponses($form, &$form_state) {
  // Access user variable.
  global $user;
  // Set variable for current user.
  $account = user_load($user->uid);
  // Load user responses list.
  $user_responses_list = field_get_items('user', $account, 'field_learnsp_responses_revealed');
  // dpm($user_responses_list);
  $planbudget = 0;
  // If the user_responses_list is blank
  // When the user scrolls the page, execute myFunction.
  if ($user_responses_list == FALSE) {
    $form['markup'] = array(
      '#type' => 'markup',
      '#markup' => '<p>You don\'t have any revealed responses. You need to do more research.</p><p><a class="btn btn-primary" href="/learning/prostitution/analyze-problem">Return to Problem Analysis</a></p>',
    );
  }
  // If user_respnoses_list is populated.
  else {
    $options = array();
    for ($i = 0; $i < count($user_responses_list); $i++) {
      ${'res_nid_' . $i} = $user_responses_list[$i]['target_id'];
      ${'node_' . $i} = node_load(${'res_nid_' . $i});
      ${'node_' . $i . '_body'} = ${'node_' . $i}->body['und'][0]['safe_value'];
      ${'node' . $i . 'cost'} = ${'node_' . $i}->field_cost['und'][0]['value'];
      $options[${'res_nid_' . $i}] = array(
        'cost' => '<strong>' . ${'node' . $i . 'cost'} . '%</strong>',
        'res_body' => ${'node_' . $i . '_body'},
      );
    }
    $header = array(
      'cost' => t('Cost'),
      'res_body' => t('Response'),
    );

    $form['markup'] = array(
      '#type' => 'markup',
      '#markup' => '<p>Listed below are ' . /*counted responses*/' responses which have been revealed through your analysis but have not been added to your plan. Select which responses you would like to add to your plan by checking the boxes to the left.</p><p>When you have finished selecting all of the responses you would like to add to your plan, click the "Add to Plan" button at the bottom.</p>',
    );
    // Load user choices list.
    $user_choices_list = field_get_items('user', $account, 'field_learnsp_plan_choices');

    $default_nids = array();
    if ($user_choices_list !== FALSE) {
      // Isolate nid column of $user_choices_list multidimensional array.
      $choices_nids = array_column($user_choices_list, 'target_id');
      // Populate array for default value.
      foreach ($choices_nids as $nid) {
        $default_nids[$nid] = TRUE;
      }
    }
    // dpm($default_nids);
    $form['table'] = array(
      '#type' => 'tableselect',
      '#header' => $header,
      '#options' => $options,
      '#multiple' => TRUE,
      '#access' => TRUE,
      // '#js_select' => FALSE,
      '#default_value' => $default_nids,
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Add to Plan'),
    );
    $form['actions']['submit']['#submit'][] = 'sp_learningmod_myresponses_submit';
  }
  // Show a message with updated budget value.
  drupal_set_message(
    t('
      <div class="budgetbar">Create My Plan</div>
      <div><span><strong>Budget spent:</strong></span><span style="display: inline-block; width: 85%; margin-left: 8px;" class="field field-name-field-basic-text-text field-type-text-long field-label-hidden">
        <div class="field-items">
            <div class="field-item even">
                <div class="w3-light-grey">
                    <div id="myBar" class="w3-container w3-green w3-center" style="width:0%">0%
                    </div>
                </div>
            </div>
            <script>
            //create sticky messagebox function
            window.onscroll = function() {stickIt()};
            // Get the messagebox
            var messagebox = document.getElementById("messages");
            // Get the offset position of the messagebox
            var sticky = messagebox.offsetTop;
            // Add the sticky class to the messagebox when you reach its scroll position. Remove "sticky" when you leave the scroll position
            function stickIt() {
              if (window.pageYOffset >= sticky) {
                jQuery("#messages .budgetbar").closest(".alert").addClass("myplan_sticky");
              } else {
                jQuery("#messages .budgetbar").closest(".alert").removeClass("myplan_sticky")
              }
              //get width of the content area
              var contentwidth = jQuery("#content").css("width");
              //set messagebox to match content area width
              jQuery(".myplan_sticky").css("width", contentwidth);
              //get admin-menu element
              var adminmenu = document.getElementById("admin-menu");
              //if admin-menu does not exist, change the top margin accordingly
              if(adminmenu === null) {
                jQuery(".myplan_sticky").css("margin-top", "56px");
              }
            }
            jQuery(document).ready(function move($) {
                 $(".form-checkbox:checked").prev("label").addClass("checked");
                //declare array
                var selected = [];
                //loop through each checked box in the form
                $(".form-checkbox:checked").each(function(){
                    //set integer variable for the raw value of the text in the cost column
                    var num = parseInt($(this).closest("td").next().find("strong").html().replace("%", ""));
                    //add the value to the "selected" array
                    selected.push(num);
                });
                //callback function for reduce method
                function getSum(total, num) {
                    return total + num;
                }
                //if selected array is not empty
                if (selected.length > 0){
                  //set planbudget as sum of all checked box values
                  var planbudget = selected.reduce(getSum);
                }
               //if array is empty
               else {
                  //set planbuget to zero
                  var planbudget = 0;
                }
                var elem = document.getElementById("myBar");
                var width = 0;
                var id = setInterval(frame, 0);

                function frame() {
                    if (width >= planbudget) {
                        clearInterval(id);
                    } else {
                        width++;
                        elem.style.width = width + "%";
                        elem.innerHTML = "<strong>" + width * 1 + "%" + "</strong>";
                    }
                    if (width >= 80 && width <= 100) {
                        elem.classList.remove("w3-green");
                        elem.classList.add("orange");
                    }
                    if (width > 100) {
                        elem.classList.remove("orange");
                        elem.classList.add("red");
                    }
                }
                if (planbudget == 0 ){
                  elem.style.width = 0 + "%";
                  elem.innerHTML = "<strong>" + 0 + "%" + "</strong>";
                }
                //reset array
                selected = [];
                //run function any time the form is changed
                $("#sp-learningmod-myresponses").change(function(){
                  $("tr.selected").find("label").addClass("checked");
                  if($("tr").hasClass("selected") == false) {
                    $("tr").find("label").removeClass("checked");
                  }
                    //loop through each checked box in the form
                    $("tr.selected").find(".form-checkbox").each(function(){
                        //set integer variable for the raw value of the text in the cost column
                        var num = parseInt($(this).closest("td").next().find("strong").html().replace("%", ""));
                        //add the value to the "selected" array
                        selected.push(num);
                    });
                    //callback function for reduce method
                    function getSum(total, num) {
                        return total + num;
                    }
                    //if selected array is not empty
                    if (selected.length > 0){
                      //set planbudget as sum of all checked box values
                      var planbudget = selected.reduce(getSum);
                    }
                   //if array is empty
                   else {
                      //set planbuget to zero
                      var planbudget = 0;
                    }
                    var elem = document.getElementById("myBar");
                    var width = 0;
                    var id = setInterval(frame, 0);

                    function frame() {
                        if (width >= planbudget) {
                            clearInterval(id);
                        } else {
                            width++;
                            elem.style.width = width + "%";
                            elem.innerHTML = "<strong>" + width * 1 + "%" + "</strong>";
                        }
                        if (width >= 80 && width <= 100) {
                            elem.classList.remove("w3-green");
                            elem.classList.add("orange");
                        }
                        if (width > 100) {
                            elem.classList.remove("orange");
                            elem.classList.add("red");
                        }
                        if (width < 80) {
                        elem.classList.remove("orange");
                        elem.classList.remove("red");
                        elem.classList.add("w3-green");
                        }
                    }
                    if (planbudget == 0 ){
                      elem.style.width = 0 + "%";
                      elem.innerHTML = "<strong>" + 0 + "%" + "</strong>";
                    }
                  //reset array
                  selected = [];
                  });
                });
            </script>
        </div></span>
      </div>
    '), 'warning', FALSE
  );
  /* Check for revealed responses and add them to user account */

  return $form;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function sp_learningmod_form_sp_learningmod_myresponses_alter(&$form, &$form_state, $form_id) {
  // Access user variable.
  global $user;
  // Set variable for current user.
  $account = user_load($user->uid);

}

/**
 * My Responses Submit callback function.
 */
function sp_learningmod_myresponses_submit($form, $form_state) {
  // Access user variable.
  global $user;
  // Set variable for current user.
  $account = user_load($user->uid);
  // Set results to a variable.
  $choices = array_filter($form_state['values']['table']);
  // dpm($choices, 'choices');.
  /* Check for revealed responses and add them to user account */
  // Load user choices list.
  $user_choices_list = field_get_items('user', $account, 'field_learnsp_plan_choices');
  // Isolate nid column of $user_choices_list multidimensional array.
  if ($user_choices_list !== FALSE) {
    $choices_nids = array_column($user_choices_list, 'target_id');
  }
  // What to do if the user_choices_list is blank.
  if ($user_choices_list == FALSE) {
    // Loop through choices and save them to user account.
    foreach ($choices as $rnid) {
      $account->field_learnsp_plan_choices[LANGUAGE_NONE][]['target_id'] = $rnid;
      // Save user account.
      $account = user_save($account);
    }
  }
  // What to do if the user_choices_list is not blank.
  elseif ($user_choices_list !== FALSE) {
    // Reset user_choices_list.
    $account->field_learnsp_plan_choices = NULL;
    // Save user account.
    $account = user_save($account);
    // Run a loop of all nids in the $choices array.
    foreach ($choices as $rnid) {
      $account->field_learnsp_plan_choices[LANGUAGE_NONE][]['target_id'] = $rnid;
      // Save user account.
      $account = user_save($account);
    }
  }
  // Set redirect location.
  $_GET['destination'] = '/learning/prostitution/plan/myplan';

  // Prevent budget spent message from displaying on redirected page.
  $remove_strings = array('Create My Plan');
  if (!empty($_SESSION['messages']['warning'])) {
    foreach ($_SESSION['messages']['warning'] as $key => $message) {
      foreach ($remove_strings as $string) {
        if (strpos($message, $string) !== FALSE) {
          unset($_SESSION['messages']['warning'][$key]);
        }
      }
    }
    // Remove empty status messages if no other messages have been set.
    if (empty($_SESSION['messages']['warning'])) {
      unset($_SESSION['messages']['warning']);
    }
  }
}
