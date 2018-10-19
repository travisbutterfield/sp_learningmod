jQuery(document).ready(function($){
  $('.responseset a').click(function(){
    $( this ).parent().next('div.responsedetail').slideToggle('fast');
    $( this ).next('div.responsedetail').slideToggle('fast');
  });

  $('#sp-learningmod-myresponses .form-type-checkbox label').removeClass('element-invisible');
  $('#sp-learningmod-myresponses .form-type-checkbox label').click(function() {
    $(this).toggleClass('checked');
  });
});
