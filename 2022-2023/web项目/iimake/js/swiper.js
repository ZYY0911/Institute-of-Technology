//轮播图样式
var swiper1 = new Swiper('#swiper1', {
    speed: 1000,
    loop: true,
    autoplay: {
        stopOnLastSlide: false,
    },
    pagination: {
        el: '.swiper-pagination',
    },
    navigation: {
        nextEl: '.swiper-button-next',
        prevEl: '.swiper-button-prev'
    }
})
//轮播图样式结束

