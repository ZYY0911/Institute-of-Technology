// 返回顶部
$(function () {
    $(window).scroll(function () {
        if ($(window).scrollTop() >= $(window).height()) {
            $(".btop").stop().fadeIn(1000)
        } else {
            $(".btop").stop().fadeOut(1000)
        }
    })
    $(".btop").click(function () {
        $("html,body").stop().animate({ scrollTop: 0 }, 1000);
        $(window).scrollTop(0);
    })
})