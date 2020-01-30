/**
 * @file
 * SP_Learningmod javascript functions.
 */

(function($) {
  Drupal.behaviors.spLearningMod = {
    attach: function(context, settings) {
      $(".responseset a").click(function() {
        $(this)
          .parent()
          .next("div.responsedetail")
          .slideToggle("fast");
        $(this)
          .next("div.responsedetail")
          .slideToggle("fast");
      });

      $("#sp-learningmod-buildmyplan .form-type-checkbox label").removeClass(
        "element-invisible"
      );
      $("#sp-learningmod-buildmyplan .form-type-checkbox label").click(
        function() {
          $(this).toggleClass("checked");
        }
      );

      if (typeof Drupal.settings.sp_learningmod.spSubmitted !== "undefined") {
        if (Drupal.settings.sp_learningmod.spSubmitted !== "yes") {
          $(".menu-name-menu-sp-learning-mod")
            .find("li")
            .children("a")
            .filter(function(index) {
              return $(this).text() === "Feedback";
            })
            .hide();
        }
      }
    }
  };
})(jQuery);
