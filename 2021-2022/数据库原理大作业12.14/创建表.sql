/*老师信息：教师编号、老师姓名、性别、手机号、职教信息（毕业院校、所获奖项等）、固定薪资*/
create table teachers (tno char(8)  unique not null 
,tname char(10)
,tsex char(4) check(tsex in('男','女'))
,ttel char(11) 
,msg text
,salary int
primary key (tno))

/*学生信息：学号、学生姓名、密码、性别、年龄、手机号、所选教学模式、所选老师、缴费情况、班级编号*/
create table students (sno char(8) unique not null 
,sname char(10)
,pas char(20)
,ssex char(4) check(ssex in('男','女'))
,sage int check (sage>=0 and sage<=100)
,tel char(11) 
,edumode char(10)
,tno char(8)
,paystate int check (paystate in(0,1))
,cno char(8) 
primary key (sno)
,foreign key(tno) references teachers(tno))

insert into teachers values ('10000001','李华','男','18500000000','烟台理工学院',6000),
('10000002','刘强','男','18600000000','烟台理工学院',6300),
('10000003','张三','男','18700000000','烟台理工学院',6300),
('10000004','杨幂','女','18800000000','烟台理工学院',7000)

insert into students values ('11100001','王鹤','000000','男',20,'19500000000','一对一','10000001',1,''),
('11100002','王一','000000','男',20,'19600000000','一对一','10000002',1,''),
('11100003','王美','000000','女',21,'19700000000','一对一','10000001',1,''),
('11100004','王二','000000','男',20,'19800000000','一对一','10000003',1,''),
('11100005','王水','000000','女',22,'19900000000','一对一','10000002',1,''),
('11100006','王森','000000','男',20,'19500000000','一对一','10000001',1,''),
('11100007','王淼','000000','男',20,'19500000001','一对一','10000004',1,''),
('11100008','王岩','000000','男',21,'19500000002','一对一','10000004',1,''),
('11100009','王炎','000000','女',20,'19500000003','一对一','10000004',1,''),
('11100010','王宁','000000','男',22,'19500000004','一对一','10000001',1,''),
('11100011','王军','000000','男',20,'19500000005','一对一','10000002',1,''),
('11100012','王倩','000000','女',21,'19500000006','一对一','10000003',1,''),
('11100013','王硕','000000','男',20,'19500000007','一对一','10000004',1,''),
('11100014','王静','000000','女',21,'19500000008','一对一','10000004',1,''),
('11100015','王田','000000','男',20,'19500000009','一对一','10000001',1,'')


/*班助信息：班助编号、班助姓名、性别、手机号、薪水*/
create table hteacher (htno char(8)  unique not null 
,htname char (4)
,htsex char(4) check(htsex in('男','女'))
,httel char(11) 
,salary int
,primary key (htno)
)


insert into hteacher values ('20000001','小艾','女','13100000000',5000),
('20000002','一艾','女','13100000002',5000),
('20000003','二艾','男','13100000003',5000),
('20000004','三艾','女','13100000004',5000),
('20000005','四艾','男','13100000005',5000)



/*课程表：课程编号、课程名称、课时*/
create table classinfo (cno char(4) unique not null 
,cname char (30)
,ctime int  check (ctime>=1 and ctime<=100),
primary key (cno)
)

insert into classinfo values ('2001' ,'数据库系统概论','24'),
('2002' ,'数据结构','2'),('2003' ,'操作系统','20')



/*班级信息（一对多）：班级编号、教师编号、班助编号、班级名称、班级类型、*/
create table grade (gno char(4) unique not null 
,tno char(8)
,htno char(8)
,gname char(8)
,gtype int check (gtype between 0 and 1)
,primary key (gno)
,foreign key(tno) references teachers(tno)
,foreign key(htno) references hteacher(htno)
)

insert into grade values ('0001','10000001','20000001','一班','0'),
('0002','10000001','20000001','二班','1'),
('0003','10000002','20000002','三班','0'),
('0004','10000002','20000002','四班','1'),
('0005','10000003','20000003','五班','0'),
('0006','10000003','20000003','六班','1'),
('0007','10000004','20000004','七班','0'),
('0008','10000004','20000004','八班','1')

/*上课课程（一对一）：学号、课程编号、教师编号、成绩、上课时间、地点、教学模式、金额*/
create table goclass (sno char(8)
,cno char(4) 
,tno char(8)
,gread int check (gread between 0 and 150)
,classtime datetime
,loaction char(20)
,tmode char(10)
,pay int
,foreign key(sno) references students(sno)
,foreign key(cno) references classinfo(cno)
,foreign key(tno) references teachers(tno)
)


/*成绩表（一对多）：学号、班级编号、成绩*/
create table score (id int primary key identity(0,1)
,sno char(8) 
,gno char(4)
,num int check (num between 0 and 150)
,foreign key(sno) references students(sno)
,foreign key(gno) references grade(gno)
)


insert into score values ('11100001','0001','88'),
('11100002','0002','90'),
('11100003','0003','89'),
('11100004','0004','98'),
('11100005','0005','78'),
('11100006','0006','87'),
('11100007','0007','96'),
('11100008','0008','100')