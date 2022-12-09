-- MySQL dump 10.13  Distrib 5.7.31, for Linux (x86_64)
--
-- Host: localhost    Database: jspm0ie5r
-- ------------------------------------------------------
-- Server version	5.7.31

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `address`
--

DROP TABLE IF EXISTS `address`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `address` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `userid` bigint(20) NOT NULL COMMENT '用户id',
  `address` varchar(200) NOT NULL COMMENT '地址',
  `name` varchar(200) NOT NULL COMMENT '收货人',
  `phone` varchar(200) NOT NULL COMMENT '电话',
  `isdefault` varchar(200) NOT NULL COMMENT '是否默认地址[是/否]',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COMMENT='地址';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `address`
--

LOCK TABLES `address` WRITE;
/*!40000 ALTER TABLE `address` DISABLE KEYS */;
INSERT INTO `address` VALUES (1,'2030-12-21 09:47:53',1,'宇宙银河系金星1号','金某','13823888881','是'),(2,'2030-12-21 09:47:53',2,'宇宙银河系木星1号','木某','13823888882','是'),(3,'2030-12-21 09:47:53',3,'宇宙银河系水星1号','水某','13823888883','是'),(4,'2030-12-21 09:47:53',4,'宇宙银河系火星1号','火某','13823888884','是'),(5,'2030-12-21 09:47:53',5,'宇宙银河系土星1号','土某','13823888885','是'),(6,'2030-12-21 09:47:53',6,'宇宙银河系月球1号','月某','13823888886','是');
/*!40000 ALTER TABLE `address` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `config`
--

DROP TABLE IF EXISTS `config`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `config` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `name` varchar(100) NOT NULL COMMENT '配置参数名称',
  `value` varchar(100) DEFAULT NULL COMMENT '配置参数值',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COMMENT='配置文件';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `config`
--

LOCK TABLES `config` WRITE;
/*!40000 ALTER TABLE `config` DISABLE KEYS */;
INSERT INTO `config` VALUES (1,'picture1','http://localhost:8080/jspm0ie5r/upload/1608544218019.jpeg'),(2,'picture2','http://localhost:8080/jspm0ie5r/upload/picture2.jpg'),(3,'picture3','http://localhost:8080/jspm0ie5r/upload/picture3.jpg'),(4,'picture4','http://localhost:8080/jspm0ie5r/upload/1608544206846.jpg'),(5,'picture5','http://localhost:8080/jspm0ie5r/upload/picture5.jpg'),(6,'homepage',NULL);
/*!40000 ALTER TABLE `config` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dianyingleixing`
--

DROP TABLE IF EXISTS `dianyingleixing`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dianyingleixing` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `leixing` varchar(200) NOT NULL COMMENT '类型',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1608601497048 DEFAULT CHARSET=utf8 COMMENT='电影类型';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dianyingleixing`
--

LOCK TABLES `dianyingleixing` WRITE;
/*!40000 ALTER TABLE `dianyingleixing` DISABLE KEYS */;
INSERT INTO `dianyingleixing` VALUES (1,'2030-12-21 09:47:53','类型1'),(2,'2030-12-21 09:47:53','类型2'),(3,'2030-12-21 09:47:53','类型3'),(4,'2030-12-21 09:47:53','类型4'),(1608601489045,'2030-12-22 01:44:48','动作片'),(1608601497047,'2030-12-22 01:44:56','历史片');
/*!40000 ALTER TABLE `dianyingleixing` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dianyingxinxi`
--

DROP TABLE IF EXISTS `dianyingxinxi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dianyingxinxi` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `dianyingmingcheng` varchar(200) NOT NULL COMMENT '电影名称',
  `leixing` varchar(200) NOT NULL COMMENT '类型',
  `shangyingriqi` date NOT NULL COMMENT '上映日期',
  `haibao` varchar(200) DEFAULT NULL COMMENT '海报',
  `daoyan` varchar(200) DEFAULT NULL COMMENT '导演',
  `zhuyan` varchar(200) NOT NULL COMMENT '主演',
  `yugao` varchar(200) DEFAULT NULL COMMENT '预告',
  `yingyuanmingcheng` varchar(200) DEFAULT NULL COMMENT '影院名称',
  `dizhi` varchar(200) DEFAULT NULL COMMENT '地址',
  `fangyingting` varchar(200) DEFAULT NULL COMMENT '放映厅',
  `changci` datetime DEFAULT NULL COMMENT '场次',
  `dianyingjianjie` longtext COMMENT '电影简介',
  `clicktime` datetime DEFAULT NULL COMMENT '最近点击时间',
  `clicknum` int(11) DEFAULT '0' COMMENT '点击次数',
  `price` float NOT NULL COMMENT '价格',
  `number` int(11) NOT NULL COMMENT '座位总数',
  `selected` longtext COMMENT '已选座位[用,号隔开]',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1608601575624 DEFAULT CHARSET=utf8 COMMENT='电影信息';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dianyingxinxi`
--

LOCK TABLES `dianyingxinxi` WRITE;
/*!40000 ALTER TABLE `dianyingxinxi` DISABLE KEYS */;
INSERT INTO `dianyingxinxi` VALUES (1,'2030-12-21 09:47:53','电影名称1','类型1','2030-12-21','http://localhost:8080/jspm0ie5r/upload/1608544254807.jpg','导演1','主演1','','影院名称1','地址1','1号厅','2030-12-21 17:47:53','电影简介1\r\n','2030-12-21 23:03:20',6,99.9,20,'1,3,5,7,9,15,16'),(2,'2030-12-21 09:47:53','电影名称2','类型2','2030-12-21','http://localhost:8080/jspm0ie5r/upload/1608544265885.jpg','导演2','主演2','','影院名称2','地址2','1号厅','2030-12-21 17:47:53','电影简介2\r\n','2030-12-21 23:16:07',12,99.9,20,'1,3,5,7,9,16,17,13,14,11,12'),(3,'2030-12-21 09:47:53','电影名称3','类型3','2030-12-21','http://localhost:8080/jspm0ie5r/upload/1608544275528.jpg','导演3','主演3','','影院名称3','地址3','1号厅','2030-12-21 17:47:53','电影简介3\r\n','2030-12-21 23:23:54',17,99.9,20,'1,3,5,7,9,13,14,17,18,11,12,19,20'),(4,'2030-12-21 09:47:53','电影名称4','类型4','2030-12-21','http://localhost:8080/jspm0ie5r/upload/1608544287183.jpg','导演4','主演4','','影院名称4','地址4','1号厅','2030-12-21 17:47:53','电影简介4\r\n','2030-12-21 17:51:21',6,99.9,20,'1,3,5,7,9'),(5,'2030-12-21 09:47:53','电影名称5','类型5','2030-12-21','http://localhost:8080/jspm0ie5r/upload/1608544298379.jpg','导演5','主演5','','影院名称5','地址5','1号厅','2030-12-21 17:47:53','电影简介5\r\n','2030-12-21 17:51:33',7,99.9,20,'1,3,5,7,9'),(6,'2030-12-21 09:47:53','电影名称6','类型6','2030-12-21','http://localhost:8080/jspm0ie5r/upload/1608544310480.jpg','导演6','主演6','','影院名称6','地址6','1号厅','2030-12-21 17:47:53','电影简介6\r\n','2030-12-21 23:11:02',22,99.9,20,'1,3,5,7,9,13,14'),(1608595682001,'2030-12-22 00:08:01','1','类型1','2030-12-22','http://localhost:8080/jspm0ie5r/upload/1608595628569.jpg','1','1','','影院名称1','地址1','1号厅','2030-12-22 05:10:43','dgfgh \r\n','2030-12-22 09:47:19',5,20,10,',3,4'),(1608601575623,'2030-12-22 01:46:14','紧急救援','动作片','2030-12-17','http://localhost:8080/jspm0ie5r/upload/1608601549412.jpg','林','彭于晏','','影院A','DSDS ','1号厅','2030-12-22 05:00:31','《紧急救援》是由林超贤执导，由彭于晏、王彦霖、辛芷蕾、蓝盈莹领衔主演，王雨甜、徐洋、李岷城、刘亦淳等联合主演的动作剧情电影，于2020年12月18日在中国大陆上映。该片取材自真实海上救援事件，讲述了王牌特勤队员高谦和好兄弟赵呈与其他救捞人直面重大灾难的挑战，一同执行惊险的海上救援任务的故事。\r\n','2030-01-20 13:57:40',4,35,40,',3,4');
/*!40000 ALTER TABLE `dianyingxinxi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `discussdianyingxinxi`
--

DROP TABLE IF EXISTS `discussdianyingxinxi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `discussdianyingxinxi` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `refid` bigint(20) NOT NULL COMMENT '关联表id',
  `userid` bigint(20) NOT NULL COMMENT '用户id',
  `content` longtext NOT NULL COMMENT '评论内容',
  `reply` longtext COMMENT '回复内容',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1608601691562 DEFAULT CHARSET=utf8 COMMENT='电影信息评论表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `discussdianyingxinxi`
--

LOCK TABLES `discussdianyingxinxi` WRITE;
/*!40000 ALTER TABLE `discussdianyingxinxi` DISABLE KEYS */;
INSERT INTO `discussdianyingxinxi` VALUES (1,'2030-12-21 09:47:53',1,1,'评论内容1','回复内容1'),(2,'2030-12-21 09:47:53',2,2,'评论内容2','回复内容2'),(3,'2030-12-21 09:47:53',3,3,'评论内容3','回复内容3'),(4,'2030-12-21 09:47:53',4,4,'评论内容4','回复内容4'),(5,'2030-12-21 09:47:53',5,5,'评论内容5','回复内容5'),(6,'2030-12-21 09:47:53',6,6,'评论内容6','回复内容6'),(1608550471603,'2030-12-21 11:34:31',6,1608550437986,'好看',NULL),(1608551142645,'2030-12-21 11:45:42',6,1608551117961,'henhao ',NULL),(1608551209537,'2030-12-21 11:46:48',1608551076238,1608551117961,'好看',NULL),(1608557183629,'2030-12-21 13:26:23',6,1608557138813,'很好看',NULL),(1608557199479,'2030-12-21 13:26:39',1608557106325,1608557138813,'打发的',NULL),(1608562813619,'2030-12-21 15:00:12',6,1608562780256,'好看',NULL),(1608601691561,'2030-12-22 01:48:10',1608601575623,1608601606668,'看其他用户的评论',NULL);
/*!40000 ALTER TABLE `discussdianyingxinxi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `discussgonggaoxinxi`
--

DROP TABLE IF EXISTS `discussgonggaoxinxi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `discussgonggaoxinxi` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `refid` bigint(20) NOT NULL COMMENT '关联表id',
  `userid` bigint(20) NOT NULL COMMENT '用户id',
  `content` longtext NOT NULL COMMENT '评论内容',
  `reply` longtext COMMENT '回复内容',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COMMENT='公告信息评论表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `discussgonggaoxinxi`
--

LOCK TABLES `discussgonggaoxinxi` WRITE;
/*!40000 ALTER TABLE `discussgonggaoxinxi` DISABLE KEYS */;
INSERT INTO `discussgonggaoxinxi` VALUES (1,'2030-12-21 09:47:53',1,1,'评论内容1','回复内容1'),(2,'2030-12-21 09:47:53',2,2,'评论内容2','回复内容2'),(3,'2030-12-21 09:47:53',3,3,'评论内容3','回复内容3'),(4,'2030-12-21 09:47:53',4,4,'评论内容4','回复内容4'),(5,'2030-12-21 09:47:53',5,5,'评论内容5','回复内容5'),(6,'2030-12-21 09:47:53',6,6,'评论内容6','回复内容6');
/*!40000 ALTER TABLE `discussgonggaoxinxi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `discussyingyuanxinxi`
--

DROP TABLE IF EXISTS `discussyingyuanxinxi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `discussyingyuanxinxi` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `refid` bigint(20) NOT NULL COMMENT '关联表id',
  `userid` bigint(20) NOT NULL COMMENT '用户id',
  `content` longtext NOT NULL COMMENT '评论内容',
  `reply` longtext COMMENT '回复内容',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1608601633750 DEFAULT CHARSET=utf8 COMMENT='影院信息评论表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `discussyingyuanxinxi`
--

LOCK TABLES `discussyingyuanxinxi` WRITE;
/*!40000 ALTER TABLE `discussyingyuanxinxi` DISABLE KEYS */;
INSERT INTO `discussyingyuanxinxi` VALUES (1,'2030-12-21 09:47:53',1,1,'评论内容1','回复内容1'),(2,'2030-12-21 09:47:53',2,2,'评论内容2','回复内容2'),(3,'2030-12-21 09:47:53',3,3,'评论内容3','回复内容3'),(4,'2030-12-21 09:47:53',4,4,'评论内容4','回复内容4'),(5,'2030-12-21 09:47:53',5,5,'评论内容5','回复内容5'),(6,'2030-12-21 09:47:53',6,6,'评论内容6','回复内容6'),(1608557167525,'2030-12-21 13:26:06',1608557056330,1608557138813,'很不错的影院',NULL),(1608561475834,'2030-12-21 14:37:55',1608561368290,1608561457259,'环境很好',NULL),(1608562801306,'2030-12-21 15:00:00',1608562700511,1608562780256,'环境很好',NULL),(1608601633749,'2030-12-22 01:47:13',1608601524284,1608601606668,'环境很好',NULL);
/*!40000 ALTER TABLE `discussyingyuanxinxi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gonggaoxinxi`
--

DROP TABLE IF EXISTS `gonggaoxinxi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `gonggaoxinxi` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `gonggaobiaoti` varchar(200) NOT NULL COMMENT '公告标题',
  `tupian` varchar(200) DEFAULT NULL COMMENT '图片',
  `neirong` longtext COMMENT '内容',
  `faburiqi` date DEFAULT NULL COMMENT '发布日期',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1608601478678 DEFAULT CHARSET=utf8 COMMENT='公告信息';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `gonggaoxinxi`
--

LOCK TABLES `gonggaoxinxi` WRITE;
/*!40000 ALTER TABLE `gonggaoxinxi` DISABLE KEYS */;
INSERT INTO `gonggaoxinxi` VALUES (1,'2030-12-21 09:47:52','公告标题1','http://localhost:8080/jspm0ie5r/upload/gonggaoxinxi_tupian1.jpg','内容1','2030-12-21'),(2,'2030-12-21 09:47:53','公告标题2','http://localhost:8080/jspm0ie5r/upload/gonggaoxinxi_tupian2.jpg','内容2','2030-12-21'),(3,'2030-12-21 09:47:53','公告标题3','http://localhost:8080/jspm0ie5r/upload/gonggaoxinxi_tupian3.jpg','内容3','2030-12-21'),(4,'2030-12-21 09:47:53','公告标题4','http://localhost:8080/jspm0ie5r/upload/gonggaoxinxi_tupian4.jpg','内容4','2030-12-21'),(5,'2030-12-21 09:47:53','公告标题5','http://localhost:8080/jspm0ie5r/upload/gonggaoxinxi_tupian5.jpg','内容5','2030-12-21'),(6,'2030-12-21 09:47:53','公告标题6','http://localhost:8080/jspm0ie5r/upload/gonggaoxinxi_tupian6.jpg','内容6','2030-12-21'),(1608601478677,'2030-12-22 01:44:38','VIP活动','http://localhost:8080/jspm0ie5r/upload/1608601470813.jpg','<img src=\"http://localhost:8080/jspm0ie5r/upload/1608601476713.jpg\" width=\"900\" height=\"560\" _src=\"http://localhost:8080/jspm0ie5r/upload/1608601476713.jpg\">\r\n','2030-12-22');
/*!40000 ALTER TABLE `gonggaoxinxi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `messages`
--

DROP TABLE IF EXISTS `messages`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `messages` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `userid` bigint(20) NOT NULL COMMENT '留言人id',
  `username` varchar(200) DEFAULT NULL COMMENT '用户名',
  `content` longtext NOT NULL COMMENT '留言内容',
  `reply` longtext COMMENT '回复内容',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1608601731603 DEFAULT CHARSET=utf8 COMMENT='留言板';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `messages`
--

LOCK TABLES `messages` WRITE;
/*!40000 ALTER TABLE `messages` DISABLE KEYS */;
INSERT INTO `messages` VALUES (1,'2030-12-21 09:47:53',1,'用户名1','留言内容1','回复内容1'),(2,'2030-12-21 09:47:53',2,'用户名2','留言内容2','回复内容2'),(3,'2030-12-21 09:47:53',3,'用户名3','留言内容3','回复内容3'),(4,'2030-12-21 09:47:53',4,'用户名4','留言内容4','回复内容4'),(5,'2030-12-21 09:47:53',5,'用户名5','留言内容5','回复内容5'),(1608595796294,'2030-12-22 00:09:56',1,'用户1','表空间可怜见','vbfgbgbbvnv'),(1608601731602,'2030-12-22 01:48:50',1608601606668,'chen','我会发动机分工会偶尔的客人 ','合肥市金风科技打开个人 ');
/*!40000 ALTER TABLE `messages` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orders` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `orderid` varchar(200) NOT NULL COMMENT '订单编号',
  `tablename` varchar(200) DEFAULT 'dianyingxinxi' COMMENT '商品表名',
  `userid` bigint(20) NOT NULL COMMENT '用户id',
  `goodid` bigint(20) NOT NULL COMMENT '商品id',
  `goodname` varchar(200) DEFAULT NULL COMMENT '商品名称',
  `picture` varchar(200) DEFAULT NULL COMMENT '商品图片',
  `buynumber` int(11) NOT NULL COMMENT '购买数量',
  `price` float NOT NULL DEFAULT '0' COMMENT '价格/积分',
  `discountprice` float DEFAULT '0' COMMENT '折扣价格',
  `total` float NOT NULL DEFAULT '0' COMMENT '总价格/总积分',
  `discounttotal` float DEFAULT '0' COMMENT '折扣总价格',
  `type` int(11) DEFAULT '1' COMMENT '支付类型',
  `status` varchar(200) DEFAULT NULL COMMENT '状态',
  `address` varchar(200) DEFAULT NULL COMMENT '地址',
  PRIMARY KEY (`id`),
  UNIQUE KEY `orderid` (`orderid`)
) ENGINE=InnoDB AUTO_INCREMENT=1608601704395 DEFAULT CHARSET=utf8 COMMENT='订单';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orders`
--

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
INSERT INTO `orders` VALUES (1608550496361,'2030-12-21 11:34:55','2020122119345218732152','dianyingxinxi',1608550437986,1608550401205,'紧急救援','http://localhost:8080/jspm0ie5r/upload/1608550362562.jpg',1,40,40,80,80,1,'未支付','5,6'),(1608551196098,'2030-12-21 11:46:35','2020122119463188586965','dianyingxinxi',1608551117961,1608551076238,'紧急救援','http://localhost:8080/jspm0ie5r/upload/1608551048567.jpg',1,40,40,80,80,1,'已支付','4,5'),(1608561525869,'2030-12-21 14:38:45','2020122122384194555046','dianyingxinxi',1608561457259,1608561417683,'紧急救援','http://localhost:8080/jspm0ie5r/upload/1608561390613.jpg',1,40,40,80,80,1,'已支付','3,4'),(1608562852276,'2030-12-21 15:00:52','202012212304873844487','dianyingxinxi',1608562780256,1608562751936,'紧急救援','http://localhost:8080/jspm0ie5r/upload/1608562724763.jpg',1,55,55,110,110,1,'已退款','3,4'),(1608562890368,'2030-12-21 15:01:30','202012212312669098552','dianyingxinxi',1608562780256,1608562751936,'紧急救援','http://localhost:8080/jspm0ie5r/upload/1608562724763.jpg',1,55,55,110,110,1,'已退款','24,25'),(1608562976549,'2030-12-21 15:02:56','202012212325267467770','dianyingxinxi',1608562780256,1,'电影名称1','http://localhost:8080/jspm0ie5r/upload/1608544254807.jpg',1,99.9,99.9,199.8,199.8,1,'已退款','15,16'),(1608563028597,'2030-12-21 15:03:47','202012212334437964504','dianyingxinxi',1608562780256,2,'电影名称2','http://localhost:8080/jspm0ie5r/upload/1608544265885.jpg',1,99.9,99.9,199.8,199.8,1,'已退款','16,17'),(1608563241888,'2030-12-21 15:07:21','202012212371795596926','dianyingxinxi',1608562780256,6,'电影名称6','http://localhost:8080/jspm0ie5r/upload/1608544310480.jpg',1,99.9,99.9,199.8,199.8,1,'已退款','13,14'),(1608563379140,'2030-12-21 15:09:39','202012212393573117963','dianyingxinxi',1608562780256,3,'电影名称3','http://localhost:8080/jspm0ie5r/upload/1608544275528.jpg',1,99.9,99.9,199.8,199.8,1,'未支付','13,14'),(1608563423221,'2030-12-21 15:10:22','2020122123101956350838','dianyingxinxi',1608562780256,3,'电影名称3','http://localhost:8080/jspm0ie5r/upload/1608544275528.jpg',1,99.9,99.9,199.8,199.8,1,'已退款','17,18'),(1608563500414,'2030-12-21 15:11:39','2020122123113629262813','dianyingxinxi',1608562780256,2,'电影名称2','http://localhost:8080/jspm0ie5r/upload/1608544265885.jpg',1,99.9,99.9,199.8,199.8,1,'已退款','13,14'),(1608563767159,'2030-12-21 15:16:07','202012212316377134365','dianyingxinxi',1608562780256,2,'电影名称2','http://localhost:8080/jspm0ie5r/upload/1608544265885.jpg',1,99.9,99.9,199.8,199.8,1,'已支付','11,12'),(1608563994355,'2030-12-21 15:19:53','2020122123195045999795','dianyingxinxi',1608562780256,3,'电影名称3','http://localhost:8080/jspm0ie5r/upload/1608544275528.jpg',1,99.9,99.9,199.8,199.8,1,'已支付','11,12'),(1608564235584,'2030-12-21 15:23:54','2020122123235163682499','dianyingxinxi',1608562780256,3,'电影名称3','http://localhost:8080/jspm0ie5r/upload/1608544275528.jpg',2,99.9,99.9,199.8,199.8,1,'已支付','19,20'),(1608595727851,'2030-12-22 00:08:47','20201222884750345302','dianyingxinxi',1,1608595682001,'1','http://localhost:8080/jspm0ie5r/upload/1608595628569.jpg',2,20,20,40,40,1,'已支付','3,4'),(1608601704394,'2030-12-22 01:48:23','202012229482216066139','dianyingxinxi',1608601606668,1608601575623,'紧急救援','http://localhost:8080/jspm0ie5r/upload/1608601549412.jpg',2,35,35,70,70,1,'已支付','3,4');
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `storeup`
--

DROP TABLE IF EXISTS `storeup`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `storeup` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `userid` bigint(20) NOT NULL COMMENT '用户id',
  `refid` bigint(20) DEFAULT NULL COMMENT '收藏id',
  `tablename` varchar(200) DEFAULT NULL COMMENT '表名',
  `name` varchar(200) NOT NULL COMMENT '收藏名称',
  `picture` varchar(200) NOT NULL COMMENT '收藏图片',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1608601640583 DEFAULT CHARSET=utf8 COMMENT='收藏表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `storeup`
--

LOCK TABLES `storeup` WRITE;
/*!40000 ALTER TABLE `storeup` DISABLE KEYS */;
INSERT INTO `storeup` VALUES (1608550453400,'2030-12-21 11:34:12',1608550437986,1608550342543,'yingyuanxinxi','影城B','http://localhost:8080/jspm0ie5r/upload/1608550332610.jpg'),(1608550458142,'2030-12-21 11:34:18',1608550437986,1608550401205,'dianyingxinxi','紧急救援','http://localhost:8080/jspm0ie5r/upload/1608550362562.jpg'),(1608551130337,'2030-12-21 11:45:29',1608551117961,1608551026938,'yingyuanxinxi','多影城','http://localhost:8080/jspm0ie5r/upload/1608551017698.png'),(1608557158698,'2030-12-21 13:25:58',1608557138813,1608557056330,'yingyuanxinxi','C影城','http://localhost:8080/jspm0ie5r/upload/1608557045388.jpg'),(1608557174356,'2030-12-21 13:26:13',1608557138813,6,'dianyingxinxi','电影名称6','http://localhost:8080/jspm0ie5r/upload/1608544310480.jpg'),(1608557193062,'2030-12-21 13:26:32',1608557138813,1608557106325,'dianyingxinxi','紧急救援','http://localhost:8080/jspm0ie5r/upload/1608557075667.jpg'),(1608561468889,'2030-12-21 14:37:48',1608561457259,1608561368290,'yingyuanxinxi','B影院','http://localhost:8080/jspm0ie5r/upload/1608561357952.jpg'),(1608562795571,'2030-12-21 14:59:55',1608562780256,1608562700511,'yingyuanxinxi','影院以','http://localhost:8080/jspm0ie5r/upload/1608562690898.jpg'),(1608562806186,'2030-12-21 15:00:05',1608562780256,6,'dianyingxinxi','电影名称6','http://localhost:8080/jspm0ie5r/upload/1608544310480.jpg'),(1608595748198,'2030-12-22 00:09:08',1,1608595682001,'dianyingxinxi','1','http://localhost:8080/jspm0ie5r/upload/1608595628569.jpg'),(1608601640582,'2030-12-22 01:47:20',1608601606668,1608595682001,'dianyingxinxi','1','http://localhost:8080/jspm0ie5r/upload/1608595628569.jpg');
/*!40000 ALTER TABLE `storeup` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `token`
--

DROP TABLE IF EXISTS `token`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `token` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `userid` bigint(20) NOT NULL COMMENT '用户id',
  `username` varchar(100) NOT NULL COMMENT '用户名',
  `tablename` varchar(100) DEFAULT NULL COMMENT '表名',
  `role` varchar(100) DEFAULT NULL COMMENT '角色',
  `token` varchar(200) NOT NULL COMMENT '密码',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '新增时间',
  `expiratedtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '过期时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COMMENT='token表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `token`
--

LOCK TABLES `token` WRITE;
/*!40000 ALTER TABLE `token` DISABLE KEYS */;
INSERT INTO `token` VALUES (1,1,'abo','users','管理员','d3njw662jygo4w387eswja4n30yuepus','2030-12-21 09:49:49','2030-12-22 02:49:22'),(2,1608550437986,'111','yonghu','用户','0ll038oa1drylvmlkwsioanyl4ojno9v','2030-12-21 11:34:06','2030-12-21 12:34:06'),(3,1608551117961,'1','yonghu','用户','umvkpddr8kx8lbvl4zjhlepo61f1onez','2030-12-21 11:45:24','2030-12-21 12:49:04'),(4,1608557138813,'chen','yonghu','用户','k3ierkunfvcpugpad9d987sltoqptbvn','2030-12-21 13:25:47','2030-12-21 14:25:48'),(5,1,'用户1','yonghu','用户','hsp64v3tvg0ql80gjxm7xrianawc6ml2','2030-12-21 13:35:16','2030-12-24 14:21:52'),(6,1608561457259,'1','yonghu','用户','o0ujb6buj7zz1xto9hq8alo57rn9i7bg','2030-12-21 14:37:42','2030-12-21 15:37:43'),(7,1608562780256,'chen','yonghu','用户','jbikfifxeh9wgg18ogc7hpqzq9mz9qri','2030-12-21 14:59:47','2030-12-21 15:59:48'),(8,1608601606668,'chen','yonghu','用户','34adw2zsi5nffgrjwg5e9xkbm7ubnjis','2030-12-22 01:46:56','2030-12-22 02:46:57');
/*!40000 ALTER TABLE `token` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `username` varchar(100) NOT NULL COMMENT '用户名',
  `password` varchar(100) NOT NULL COMMENT '密码',
  `role` varchar(100) DEFAULT '管理员' COMMENT '角色',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '新增时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COMMENT='用户表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'abo','abo','管理员','2030-12-21 09:47:53');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `yingyuanxinxi`
--

DROP TABLE IF EXISTS `yingyuanxinxi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `yingyuanxinxi` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `yingyuanmingcheng` varchar(200) DEFAULT NULL COMMENT '影院名称',
  `yingyuantupian` varchar(200) DEFAULT NULL COMMENT '影院图片',
  `dizhi` varchar(200) DEFAULT NULL COMMENT '地址',
  `lianxidianhua` varchar(200) DEFAULT NULL COMMENT '联系电话',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1608601524285 DEFAULT CHARSET=utf8 COMMENT='影院信息';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `yingyuanxinxi`
--

LOCK TABLES `yingyuanxinxi` WRITE;
/*!40000 ALTER TABLE `yingyuanxinxi` DISABLE KEYS */;
INSERT INTO `yingyuanxinxi` VALUES (1,'2030-12-21 09:47:53','影院名称1','http://localhost:8080/jspm0ie5r/upload/1608544325950.jpg','地址1','020-89819991'),(2,'2030-12-21 09:47:53','影院名称2','http://localhost:8080/jspm0ie5r/upload/yingyuanxinxi_yingyuantupian2.jpg','地址2','020-89819992'),(3,'2030-12-21 09:47:53','影院名称3','http://localhost:8080/jspm0ie5r/upload/1608544346080.jpg','地址3','020-89819993'),(4,'2030-12-21 09:47:53','影院名称4','http://localhost:8080/jspm0ie5r/upload/1608544358889.jpg','地址4','020-89819994'),(5,'2030-12-21 09:47:53','影院名称5','http://localhost:8080/jspm0ie5r/upload/1608544372731.jpg','地址5','020-89819995'),(6,'2030-12-21 09:47:53','影院名称6','http://localhost:8080/jspm0ie5r/upload/1608544385573.jpg','地址6','020-89819996'),(1608601524284,'2030-12-22 01:45:23','影院A','http://localhost:8080/jspm0ie5r/upload/1608601512369.jpg','DSDS ','020-23654178');
/*!40000 ALTER TABLE `yingyuanxinxi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `yonghu`
--

DROP TABLE IF EXISTS `yonghu`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `yonghu` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `yonghuming` varchar(200) NOT NULL COMMENT '用户名',
  `mima` varchar(200) NOT NULL COMMENT '密码',
  `xingming` varchar(200) DEFAULT NULL COMMENT '姓名',
  `xingbie` varchar(200) DEFAULT NULL COMMENT '性别',
  `touxiang` varchar(200) DEFAULT NULL COMMENT '头像',
  `dianhua` varchar(200) DEFAULT NULL COMMENT '电话',
  `dizhi` varchar(200) DEFAULT NULL COMMENT '地址',
  `money` float DEFAULT '0' COMMENT '余额',
  PRIMARY KEY (`id`),
  UNIQUE KEY `yonghuming` (`yonghuming`)
) ENGINE=InnoDB AUTO_INCREMENT=1608601606669 DEFAULT CHARSET=utf8 COMMENT='用户';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `yonghu`
--

LOCK TABLES `yonghu` WRITE;
/*!40000 ALTER TABLE `yonghu` DISABLE KEYS */;
INSERT INTO `yonghu` VALUES (1,'2030-12-21 09:47:52','用户1','123456','姓名1','男','http://localhost:8080/jspm0ie5r/upload/yonghu_touxiang1.jpg','13823888881','地址1',60),(2,'2030-12-21 09:47:52','用户2','123456','姓名2','男','http://localhost:8080/jspm0ie5r/upload/yonghu_touxiang2.jpg','13823888882','地址2',100),(3,'2030-12-21 09:47:52','用户3','123456','姓名3','男','http://localhost:8080/jspm0ie5r/upload/yonghu_touxiang3.jpg','13823888883','地址3',100),(4,'2030-12-21 09:47:52','用户4','123456','姓名4','男','http://localhost:8080/jspm0ie5r/upload/yonghu_touxiang4.jpg','13823888884','地址4',100),(1608601606668,'2030-12-22 01:46:46','chen','1','1','男','http://localhost:8080/jspm0ie5r/upload/1608601655711.jpg','12345678909','',930);
/*!40000 ALTER TABLE `yonghu` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2030-03-11 11:13:10
