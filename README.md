Bin calc
========

## Interface

* byte 1 - 8 bit (8 leds, 8 switches or buttons)
* byte 2 - 8 bit (8 leds, 8 switches or buttons)
* result:
	* leds 16bit - (16 leds)
	* 5*7seg indicators
* operations: (10 operations )
  * add +
  * sub -
  * div /
  * mul *
  * xor ^
  * and &
  * or  |
  * not ~
  * shr >>
  * shl <<

## Steps

1. set byte1 and byte2
2. press operation button
3. show result on 16 leds
4. show decimal result on 7-seg
5. (optional) show result on LCD
6. (optional) show info on lcd (describe every operation, )


## Materials
* arduino uno
* atmega 328 - dip
* 32 * leds
* 16 * switches
* 16 * micro-buttons  

* 74HC165 — входной сдвиговый регистр 3шт
або
* MCP23017 - 2шт
або
* PCF8574T - 3шт

* 74HC595 выходной сдвиговый регистр - 2шт
* 7шт * npn transistors (КТ3102А, BC546, BC547 )
* 7шт * 1000 Ом
* 24шт * 180 ОМ

## Notes

### Input buttons

http://www.openmusiclabs.com/learning/digital/input-scanning-matrix/shift-brigade/
http://www.learningaboutelectronics.com/images/74HC165-register-pinout.png

Команда: Черкаси-1 :)
Проект: Бінарний калькулятор

Бінарний калькулятор - додаємо здивування в навчання

Що це?
Це невеличкий навчальний пристрій для поліпшення візуального і практичного засвоєння двійкової системи числення, та бінарних операції.

Навіщо?
Виключно для того, що додати в навчальний процес елемент здивування і зацікавлення.
Значно цікавіше скористатися таким калькулятором, випробувати різні варіанти, перевірити правдивість слів вчителя/викладача

Для кого?
Для школярів, для студентів технікумів та університетів. Для викладачів.

Актуальність:
Як був студентом, то було досить важко уявити що ж це за двійкова система числення. Теорію я знав. Щось, навіть, рахувати навчився, але тема залишалася чимось абстрактним

Згодом я опинився "по той бік барикад" - почав викладати інформатику в технікумі . І знову зіткнувся з цією проблемою, але ситуація була критичнішою, то потрібно було поячнити це студентам.


Чому сам один?
Так вийшло що на брейнштормі я дуже загорівся ідеєю . Команда була не проти, щоб я займався паралельним проектом
Переваги:
	- займався тим проектом, яким я зацікавився/загорівся/в який вірю.

Недоліки:
	- власних ресурсів недостатньо для реалізації проекту за короткий час
	- витратив час всієї команди, бо пішов трохи не в тому напрямку
	- багато недоліків

Завжди будьте частиною команди. Команди рулять :)



Що встиг зробити?
Мало.
Розробив інтерфейс.
Почав розробку макету друкованої плати. Завершив на 70%.
Почав розробку прототипу:
 - виготовив одну з двох плат для встановлення біт
 - виготовив плату-інтерфейс для результатів
 - виготовив одну з двох плат для виведення результатів
 - успішно зчитав інформацію про стан всіх біт
 - успішно вивів тестові дані на панель результатів
Черговий раз переконався в прямій залежності продуктивності від кількості сну :)  

Моєю помилкою стало неправильне розподілення часу, який я інвестував у розробку

Що не встиг?
Виготовити робочий прототип.




Аналоги і конкуренти (хард, софт)
Зовнішній вигляд

	аксесуар - смарт лінійка

Ціна
Подальший розвиток
Щиро вірю в майбутнє цього пристрою.
