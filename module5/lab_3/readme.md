# Моргание лампочек на клавиатуре

Объеденить модуль отвечающий за миганием светодиодов на клавиатуре с модулем чтения и записи `sysfs`  

В модуль отвечающий за светодиодами добавили функции чтения и записи  `foo_show` и `foo_store`  

В функции `kbleds_init` добавили объект `example_kobject`, представляющий каталог в sysfs, который будем использовать для чтения и записи значений светодиодов.

## Компилируем и проверяем, что новый модуль вставился в ядро  
![](images_gif/make.png)   

![](images_gif/module.png)  
## Проверка модуля 

- echo 1 > setting_leds  

![](images_gif/1.gif)  

- echo 2 > setting_leds  

![](images_gif/2.gif)  

- echo 3 > setting_leds  

![](images_gif/3.gif)  

- echo 4 > setting_leds  

![](images_gif/4.gif)  

- echo 5 > setting_leds  

![](images_gif/5.gif)  

- echo 6 > setting_leds  

![](images_gif/6.gif)  

- echo 7 > setting_leds  

![](images_gif/7.gif)  

При остальных значения миганий нет  






