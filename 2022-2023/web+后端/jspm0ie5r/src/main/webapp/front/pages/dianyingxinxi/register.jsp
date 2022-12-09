<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page isELIgnored="true" %>

<!-- 注册 -->
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
		<title>注册</title>
		<link rel="stylesheet" href="../../layui/css/layui.css">
		<!-- 样式 -->
		<link rel="stylesheet" href="../../css/style.css" />
		<!-- 主题（主要颜色设置） -->
		<link rel="stylesheet" href="../../css/theme.css" />
		<!-- 通用的css -->
		<link rel="stylesheet" href="../../css/common.css" />
	</head>
	<body style="background: #EEEEEE; ">

		<div class="login-bg" style="background-image: url(../../img/banner.jpg);"></div>

		<div class="login-container">
			<!-- 标题 -->
			<h2 class="index-title" style="width: 480px;">USER / REGISTER</h2>
			<div class="line-container">
				<p class="line"> 电影信息注册 </p>
			</div>
			<!-- 标题 -->
			<form class="layui-form login-form">
				
                                                <div class="layui-form-item layui-form-text">
					<label class="layui-form-label">电影名称：</label>
					<div class="layui-input-inline" style="width: 300px;">
						<input type="text" id="dianyingmingcheng" name="dianyingmingcheng" placeholder="请输入电影名称" autocomplete="off" class="layui-input">
					</div>
				</div>
                                                                                                                                                                                                                <div class="layui-form-item layui-form-text">
					<label class="layui-form-label">导演：</label>
					<div class="layui-input-inline" style="width: 300px;">
						<input type="text" id="daoyan" name="daoyan" placeholder="请输入导演" autocomplete="off" class="layui-input">
					</div>
				</div>
                                                                <div class="layui-form-item layui-form-text">
					<label class="layui-form-label">主演：</label>
					<div class="layui-input-inline" style="width: 300px;">
						<input type="text" id="zhuyan" name="zhuyan" placeholder="请输入主演" autocomplete="off" class="layui-input">
					</div>
				</div>
                                                                                                                                                                <div class="layui-form-item layui-form-text">
					<label class="layui-form-label">地址：</label>
					<div class="layui-input-inline" style="width: 300px;">
						<input type="text" id="dizhi" name="dizhi" placeholder="请输入地址" autocomplete="off" class="layui-input">
					</div>
				</div>
                                                                                                                                                                                                                                                                <div class="layui-form-item layui-form-text">
					<label class="layui-form-label">点击次数：</label>
					<div class="layui-input-inline" style="width: 300px;">
						<input type="text" id="clicknum" name="clicknum" placeholder="请输入点击次数" autocomplete="off" class="layui-input">
					</div>
				</div>
                                                                <div class="layui-form-item layui-form-text">
					<label class="layui-form-label">价格：</label>
					<div class="layui-input-inline" style="width: 300px;">
						<input type="text" id="price" name="price" placeholder="请输入价格" autocomplete="off" class="layui-input">
					</div>
				</div>
                                                                <div class="layui-form-item layui-form-text">
					<label class="layui-form-label">座位总数：</label>
					<div class="layui-input-inline" style="width: 300px;">
						<input type="text" id="number" name="number" placeholder="请输入座位总数" autocomplete="off" class="layui-input">
					</div>
				</div>
                                                                                                
				<div class="layui-form-item">
					<div class="layui-input-block" style="text-align: right;margin-right: 30px;">
						<button class="layui-btn btn-submit" lay-submit lay-filter="register">注册</button>
						<button type="reset" class="layui-btn layui-btn-primary">重置</button>
					</div>
				</div>
			</form>
			<div class="bottom-container">
				<a href="javascript:window.location.href='../login/login.jsp'">已有账号？去登录</a>
			</div>
		</div>

		<script src="../../layui/layui.js"></script>
		<script src="../../js/vue.js"></script>
		<!-- 组件配置信息 -->
		<script src="../../js/config.js"></script>
		<!-- 扩展插件配置信息 -->
		<script src="../../modules/config.js"></script>
		<!-- 工具方法 -->
		<script src="../../js/utils.js"></script>
		<!-- 校验格式工具类 -->
		<script src="../../js/validate.js"></script>

		<script>
			layui.use(['layer', 'element', 'carousel', 'form', 'http', 'jquery'], function() {
				var layer = layui.layer;
				var element = layui.element;
				var carousel = layui.carousel;
				var form = layui.form;
				var http = layui.http;
				var jquery = layui.jquery;

				var tablename = http.getParam('tablename');
								
				// 注册
				form.on('submit(register)', function(data) {
					data = data.field;
                    					                    if(!data.dianyingmingcheng){
                        layer.msg('电影名称不能为空', {
							time: 2000,
							icon: 5
						});
                        return false
                    }
                                                                                                                                                                					                    if(!data.leixing){
                        layer.msg('类型不能为空', {
							time: 2000,
							icon: 5
						});
                        return false
                    }
                                                                                                                                                                					                    if(!data.shangyingriqi){
                        layer.msg('上映日期不能为空', {
							time: 2000,
							icon: 5
						});
                        return false
                    }
                                                                                                                                                                					                                                                                                                                            					                                                                                                                                            					                    if(!data.zhuyan){
                        layer.msg('主演不能为空', {
							time: 2000,
							icon: 5
						});
                        return false
                    }
                                                                                                                                                                					                                                                                                                                            					                                                                                                                                            					                                                                                                                                            					                                                                                                                                            					                                                                                                                                            					                                                                                                                                            					                                                                                                                                            					                                        if(!isIntNumer(data.clicknum)){
                        layer.msg('点击次数应输入整数', {
							time: 2000,
							icon: 5
						});
                        return false
                    }
                                                                                                                                            					                    if(!data.price){
                        layer.msg('价格不能为空', {
							time: 2000,
							icon: 5
						});
                        return false
                    }
                                                                                if(!isNumber(data.price)){
                        layer.msg('价格应输入数字', {
							time: 2000,
							icon: 5
						});
                        return false
                    }
                                                                                                                        					                    if(!data.number){
                        layer.msg('座位总数不能为空', {
							time: 2000,
							icon: 5
						});
                        return false
                    }
                                                            if(!isIntNumer(data.number)){
                        layer.msg('座位总数应输入整数', {
							time: 2000,
							icon: 5
						});
                        return false
                    }
                                                                                                                                            					                                                                                                                                                                http.requestJson(tablename + '/register', 'post', data, function(res) {
						layer.msg('注册成功', {
							time: 2000,
							icon: 6
						},function(){
							// 路径访问设置
							window.location.href = '../login/login.jsp';
						});
					});
					return false
				});

			});
		</script>
	</body>
</html>
