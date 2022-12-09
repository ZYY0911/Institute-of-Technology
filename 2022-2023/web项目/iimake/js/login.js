
// 密码登录的个人输入框
$('.password-login .log-form-item:nth-child(1) input').focus(function () {
	$(this).css('border-color', '#409eff').siblings().css('transform', 'rotate(-90deg)');
	$('.select').slideDown();
}).blur(function () {
	$(this).css('border-color', '#dcdfe6').siblings().css('transform', 'rotate(90deg)');
	$('.select').slideUp();
})
$('.select li').mouseenter(function () {
	$(this).addClass('hover').siblings().removeClass('hover');
}).click(function () {
	$('.password-login .log-form-item:nth-child(1) input').attr('placeholder', $(this).text());
	$('.select').slideUp();
	$('.input-arr').css('transform', 'rotate(90deg)');
})

// 登录的tab切换
$('.tabs-list .tabs-item').click(function () {
	$(this).addClass('is-active').siblings('.tabs-item').removeClass('is-active');
	if ($(this).index() == 1) {
		$('.tabs-active-bar').css('transform', 'translateX(10px)');
		$('.password-login').show();
		$('.text-login').hide();
	} else if ($(this).index() == 2) {
		$('.tabs-active-bar').css('transform', 'translateX(99px)');
		$('.text-login').show();
		$('.password-login').hide();
	}
})
