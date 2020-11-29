1. 对此目录下的文件与文件夹进行说明：
	Makefile：这是顶层的makefile。
	system.cfg：这是为了兼容各个系统所作的配置文件。
	common：放公共头文件代码。
	chapter_x：《数据结构》中第x章节，比如chapter_2指的是第二章。

2. 编译：
	a. 进入system.cfg文件，选择对应的SYSTEM_TYPE，比如选择UBUNTU。
	b. make clean;make开始编译。
	c 编译完成的文件放在output文件夹下面。
