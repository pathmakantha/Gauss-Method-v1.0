# Gauss-Method-v1.0
Составить программу решения системы N линейных алгебраических уравнений с N неизвестными. Вычисление корней уравнения должно производиться с заданной точностью (например, до 10 знака). Исходные данные должны загружаться из файла. Предусмотреть возможность сохранения результатов в файл.Translation: (Make a program to solve a system of N linear algebraic equations with N unknowns. The calculation of the roots of the equation must be done with a given accuracy (for example, up to 10 digits). Initial data must be loaded from a file. Provide possibility to save results to file.)

# 1 Руководство пользователя
## 1.1 Запуск приложения и общее описание

После запуска вы увидите следующее (рис. 1).

<img src="https://user-images.githubusercontent.com/91780755/161282398-ace39a10-6aea-4043-be44-8bbd00e5a141.png" width="400">

Окно приложения содержит 
•	рабочую область, где отображается матрица (рис.2); 

<img src="https://user-images.githubusercontent.com/91780755/161282446-c49aa33b-9811-4ac5-9c9e-3b8f8fd53522.png" width="400">

•	Кнопки для открытия и сохранения файлов, расчета и закрытия программы (рис.3); 

<img src="https://user-images.githubusercontent.com/91780755/161282530-126ec8f6-59b5-4131-8c5c-780fc34f615d.png" width="400">

•	Статус бар (рис.4); 

<img src="https://user-images.githubusercontent.com/91780755/161282571-7ff908e2-421c-42a4-985d-dd6569c07dae.png" width="400">

•	Строка меню (рис.5); 

<img src="https://user-images.githubusercontent.com/91780755/161282616-fdc7bffe-4a13-4f54-827c-80509297cbcc.png" width="400"> 

•	Область для отображения ответов (рис.6); 

<img src="https://user-images.githubusercontent.com/91780755/161282636-d0e6e1e4-a8c9-44fd-97c4-88f64a683ac6.png" width="400"> 

•	Поле ввода текста, чтобы установить точность (рис.7).

<img src="https://user-images.githubusercontent.com/91780755/161282682-bd45d3ab-1d68-4678-b698-353e9c4087d8.png" width="400">

## 1.2. Ввод данных вручную

После запуска приложения вы должны либо создать новое рабочее пространство, которое можно инициировать тремя способами:

Способ 1: используя меню «File -> New» (рис.8); 

<img src="https://user-images.githubusercontent.com/91780755/161285698-752bb91f-617a-48c1-94e4-56ff70293fc4.png" width="400">

Способ 2: либо нажать кнопку «New» (рис 9);

<img src="https://user-images.githubusercontent.com/91780755/161286204-cfd02cf6-83ae-4d7f-8077-6adeb39f18fb.png" width="400">

Способ 3: либо с помощью клавиатуры просто нажмите «Ctrl + N» : 
Данный пункт предназначен для создания новой рабочей области. Выбор этого пункта приводит к очистке области содержимого файла и сброса всех данных формируемых в результате анализа. Если на момент выбора этого пункта в программе были несохраненные изменения, то Вам будет предложено сохранить их (рис.10).

<img src="https://user-images.githubusercontent.com/91780755/161286515-b94a566c-7a99-4004-954c-0f782b6d149e.png" width="400">

При нажатии на «No» инициализированное действие будет выполнено без сохранения данных. 
При выборе «Yes» будет произведено сохранение данных в текущий файл с последующим выполнением инициализированного действия. Если же программе неизвестно имя файла, то будет выдан запрос на выбор имени файла.
Если вы нажмете кнопку отмены, операция будет прервана.
А также при вводе значений в «String Grid» это позволит использовать только цифры, точка (.),  минус (-), ctrl + X (резать), Ctrl + C (копия) и Ctrl + V (вставить). 
Далее пользователь может ввести, сколько линейных уравнений нужно вычислить (рис.11).

<img src="https://user-images.githubusercontent.com/91780755/161286605-69821d11-519c-4523-80a2-a31df37e4db2.png" width="400">

Затем пользователь может ввести коэффициенты уравнений (рис.12).

<img src="https://user-images.githubusercontent.com/91780755/161286699-6a40b66c-6fff-4a1a-9514-b0ad2d66217d.png" width="400">

## 1.3. Ввод данных с использованием файла 

После запуска приложения пользователь может вводить данные с помощью файла тремя способами:
Способ 1: используя меню «File -> Open…» (рис.13);

<img src="https://user-images.githubusercontent.com/91780755/161286973-c91640a3-64af-492e-8e14-29cef9e68bc6.png" width="400">

Способ 2: либо нажать кнопку «New» (рис.14);

<img src="https://user-images.githubusercontent.com/91780755/161287063-d17c2ffd-d4a0-4e5f-a521-7977472d2149.png" width="400">

Способ 3: либо с помощью клавиатуры просто нажмите «Ctrl + O»:
Если на момент выбора этого пункта в программе были несохраненные изменения, то вам будет предложено сохранить их (рис.15).

<img src="https://user-images.githubusercontent.com/91780755/161287142-98d2f54e-b931-45da-81c3-2b9c9f1c7cee.png" width="400">

При нажатии на «No» инициализированное действие будет выполнено без сохранения данных. 
При выборе «Yes» будет произведено сохранение данных в текущий файл с последующим выполнением инициализированного действия. Если же программе неизвестно имя файла, то будет выдан запрос на выбор имени файла.
Если вы нажмете кнопку отмены, операция будет прервана.
Далее вы получите окно, как в (рис.16). Тогда вы можете выбрать любой файл.

<img src="https://user-images.githubusercontent.com/91780755/161287237-5823313d-b35d-4330-8aca-38fd920b27d5.png" width="400">
 
А также я ввожу специальный тип файла под названием «Gauss Method (. gmt)» только для этой программы (рис.17). Пользователь может сохранить и открыть эти файлы с помощью этой программы.

<img src="https://user-images.githubusercontent.com/91780755/161287374-86b89826-b130-4e95-9b4b-e5e58c43b7c3.png" width="400">

Если в открытом файле отсутствует допустимая матрица (n x n+1), программа выдаст сообщение об ошибке (рис.18) и автоматически перенаправит в открытое диалоговое окно.

<img src="https://user-images.githubusercontent.com/91780755/161287473-82376a44-5f85-4f12-a54d-072826adfd0b.png" width="400">

## 1.4 Добавить или удалить уравнения

Для добавления уравнения, используя меню «Edit -> Add Equation» (рис.19).

<img src="https://user-images.githubusercontent.com/91780755/161287661-da6235f7-244e-43cc-8750-80e3de060374.png" width="300">

Для удаления уравнения, используя меню «Edit -> Delete Equation» (рис.20).

<img src="https://user-images.githubusercontent.com/91780755/161288726-2f129f19-3e4e-4f34-bc8a-9d191ded4ff6.png" width="300">

Для удаления всех значений и уравнений из окна, используя меню «Edit -> Erase» (рис.21).

<img src="https://user-images.githubusercontent.com/91780755/161288788-7f0f1b2b-5c3a-45d9-a9fc-ac006dc89083.png" width="300">

## 1.5. Установить точность

Чтобы установить точность ответов, введите любое значение (рис.22):

<img src="https://user-images.githubusercontent.com/91780755/161288877-d2d097cb-3849-4bac-8ca4-a72ec62ec821.png" width="400">

В текстовом поле для редактирования пользователю разрешено вводить только цифры (рис.23) и, если пользователь введет огромное значение, появится сообщение об ошибке (рис.24).

<img src="https://user-images.githubusercontent.com/91780755/161289043-5b537c4c-51a7-4cef-aad3-fe47d8260d81.png" width="400"><img src="https://user-images.githubusercontent.com/91780755/161289083-e56473cd-0cd8-421c-a7a9-e560919d97bd.png" width="400">

## 1.6. Рассчитать ответы

Для расчета данных, которые вводятся выше с использованием любых методов, можно измерить тремя способами:
Способ 1: используя меню «Run -> Calculate» (рис.25);

<img src="https://user-images.githubusercontent.com/91780755/161289292-2a705495-c0bf-4da0-9395-ad3b7ab50b26.png" width="400">

Способ 2: либо нажать кнопку «Calculate» (рис.26);

<img src="https://user-images.githubusercontent.com/91780755/161289415-087df440-5490-40e3-b7d2-55cc07c7e5d6.png" width="400">

Способ 3: либо с помощью клавиатуры просто нажмите «F5»:
При нажатии кнопки «Calculate», если матрица содержит не плавающее значение, программа отобразит сообщение (рис.27) об ошибке с недопустимым символом. 

<img src="https://user-images.githubusercontent.com/91780755/161289494-0ed7ebb1-3096-477f-a95d-17d2c4f436df.png" width="400">

А также, если вы введете неправильные коэффициенты, которые не имеют ответов, программа также покажет сообщение об ошибке (рис.28).
 
<img src="https://user-images.githubusercontent.com/91780755/161289566-f44a77aa-e6be-4cba-84ae-fc7918e50dd2.png" width="400">
 
## 1.7. Сохранить отредактированные или вновь добавленные уравнения

После редактирования или добавления уравнений вы можете сохранить эти значения в виде матрицы в текстовый или двоичный файл. Для этого есть 3 способа:
Способ 1: используя меню «File -> Save As…» (рис.29);

<img src="https://user-images.githubusercontent.com/91780755/161289656-73483c39-0759-4809-950f-ef053c5da6d5.png" width="300">

Способ 2: либо нажать кнопку «Save As…» (рис.30);

<img src="https://user-images.githubusercontent.com/91780755/161289727-631289fd-8bea-431f-8ec5-f09d400ada04.png" width="400">

Способ 3: либо с помощью клавиатуры просто нажмите «Ctrl + A».
Далее вы получите окно, как в (рис.31). Тогда вы можете ввести любое имя и сохранить файл.

<img src="https://user-images.githubusercontent.com/91780755/161289797-9d47c7d4-f056-4997-8a1e-ac7f201ed93c.png" width="400">

## 1.8. Сохранить результаты

После расчета линейных уравнений методом Гаусса вы можете сохранить свои ответы в текстовом файле. Вы можете сделать это тремя способами:

Способ 1: используя меню «File -> Save» (рис.32);

<img src="https://user-images.githubusercontent.com/91780755/161289858-16c53615-943f-4209-a043-928a83abeb1e.png" width="300">
 
Способ 2: либо нажать кнопку «Save» (рис.33);

<img src="https://user-images.githubusercontent.com/91780755/161289933-4a89b761-713b-4c62-9e12-815a75760b56.png" width="300">

Способ 3: либо с помощью клавиатуры просто нажмите «Ctrl + S»:
Далее вы получите окно, как в (рис.34). Тогда вы можете ввести любое имя и сохранить файл.

<img src="https://user-images.githubusercontent.com/91780755/161290027-745928c5-e07f-4342-9bbe-390f935695da.png" width="400">

# 2. Выбор среды разработки

Среда разработки EmbarcaderoRADStudio была выбрана в связи с необходимостью разработки графического пользовательского интерфейса в сравнительно короткие сроки.

# 3. Структура программы

Программа состоит из двух модулей – «GaussMthd» и «NumEqu». В модуле «GaussMthd» описана главная форма и ее компоненты. Также тут описаны, обработчики событий компонентов формы и все пользовательские функции. В модуле же «NumEqu» описана второстепенная форма, предназначенная для окна сообщения, установите количество уравнений.


## 3.1 Модуль«GaussMthd»
### 3.1.1 Класс оконной формы TForm1
#### 3.1.1.1 Перечень компонентов, размещённых в форме

| Имя | Класс | Назначение |
| --- | --- | --- |
| **Button1** | TButton | При нажатии закрывает программу. |
| **Button2** | TButton | При нажатии открывает гистограмму в новой форме. |
| **Button3** | TButton | При нажатии он рассчитывает данные в соответствии с предустановленными настройками. |
| **Button4** | TButton | При нажатии инициирует диалог открытия файла. |
| **Button5** | TButton | При нажатии он сохраняет ответы, рассчитанные программой |
| **Button6** | TButton | При нажатии он сохраняет данные, введенные пользователем |
| **Edit1** | TEdit | Добавление значения точности |
| **Image1** | TImage | Отображение картинки о программе |
| **Label1** | TLabel | Строка «Pathma Arts». |
| **Label2** | TLabel | Строка «Input Matrix:». |
| **Label4** | TLabel | Строка «Solving a system of N linear algebraic equations with N unknowns». |
| **Label5** | TLabel | Строка «Accuracy :». |
| **MainMenu1** | TMainMenu | Главное меню с выпадающими списками команд для работы с программой. |
| **About1** | TMenuItem | Пункт меню MainMenu1 – «About». |
| **AboutProgram1** | TMenuItem | При нажатии выводит информацию о программе. |
| **Addequation1** | TMenuItem | Подпункт пункта меню Edit3. При нажатии можете добавить новое уравнение |
| **Calculate1** | TMenuItem | Подпункт пункта меню Edit2. При нажатии он рассчитывает данные в соответствии с предустановленными настройками. |
| **CleanAll1** | TMenuItem | Подпункт пункта меню Edit3. При нажатии можете удалить все уравнения и значения |
| **DeleteEquation1** | TMenuItem | Подпункт пункта меню Edit3. При нажатии можете удалить уравнение |
| **Edit2** | TMenuItem | Пункт меню MainMenu1 – «Run». |
| **Edit3** | TMenuItem | Пункт меню MainMenu1 – «Edit». |
| **Exit1** | TMenuItem | Подпункт пункта меню N1. При нажатии закрывает программу. |
| **N1** | TMenuItem | Пункт меню MainMenu1 – «File». |
| **N2** | TMenuItem | Подпункт пункта меню N1. Разделитель списка |
| **N3** | TMenuItem | Подпункт пункта меню About1. Разделитель списка |
| **N4** | TMenuItem | Подпункт пункта меню N1. Разделитель списка |
| **N5** | TMenuItem | Подпункт пункта меню Edit1. Разделитель списка |
| **New1** | TMenuItem | Подпункт пункта меню N1. При нажатии создает новый проект. |
| **Open1** | TMenuItem | Подпункт пункта меню N1. При нажатии вызывается диалог открытия файла. |
| **PathmaArts1** | TMenuItem | Подпунктменю MainMenu1 – About1 – «Pathma Arts». |
| **Save1** | TMenuItem | Подпункт пункта меню N1. При нажатии сохраняет ответы, рассчитанные программой |
| **Saveas1** | TMenuItem | Подпункт пункта меню N1. При нажатии сохраняет данные, введенные пользователем |
| **OpenDialog1** | TOpenDialog | Подпункт пункта меню N1. При нажатии инициирует диалог открытия файла. |
| **Panel1** | TPanel | Панель на главной форме, которая является контейнером для помещенных на нее элементов. |
| **Panel2** | TPanel | Панель на главной форме, которая является контейнером для помещенных на нее элементов. |
| **Panel4** | TPanel | Панель на главной форме, которая является контейнером для помещенных на нее элементов. |
| **SaveDialog1** | TSaveDialog | Диалог сохранения файла. |
| **SaveDialog2** | TSaveDialog | Диалог сохранения файла. |
| **Splitter1** | TSlitter | Сплиттер для разделения двух сеток. |
| **StatusBar1** | TStatusBar | Показывать статуи в реальном времени о программе |
| **StringGrid1** | TStringGrid | Таблица, содержащая данные для расчета. |
| **StringGrid2** | TStringGrid | Таблица, содержащая ответы, рассчитанные программой. |

#### 3.1.1.2 Глобальные переменные

| Имя | Тип | Назначение |
| --- | --- | --- |
| n | Int | Количество уравнений. |
| c | Int | Размер точности. |
| A[Max][Max+1] | Float | Матрица коэффициентов. |
| X[Max] | Float | Множество решений. |
| f\_not | Bool | Что указывает на наличие или отсутствие решений в системе уравнений. |
| open\_err | Bool | 1 - открыть файл с пустой ячейкой. |
| save\_as | Bool | 1 - Сохранить как не нажали. |

#### 3.1.1.3 Перечень обработчиков событий

| Имя | Событие (элемент управления) | Суть обработки |
| --- | --- | --- |
| AboutProgram1Click | OnClick(AboutProgram1) | Выводит окно с информацией о программе. |
| Addequation1Click | OnClick(Addequation1) | Добавляет новое уравнение |
| Button1Click | OnClick(Button1) | Инициирует выход из программы. |
| Button2Click | OnClick(Button2) | Открывает форму, спрашивая, сколько уравнений пользователь хочет вставить. |
| Button3Click | OnClick(Button3) | Начинает вычислять ответы. |
| Button4Click | OnClick(Button4) | Обработка нажатия кнопки «OpenFile». При нажатии инициирует диалог открытия файла. |
| Button5Click | OnClick(Button5) | Обработка нажатия кнопки «SavetoFile». При нажатии он сохраняет ответы, рассчитанные программой. |
| Button6Click | OnClick(Button6) | Обработка нажатия кнопки «SavetoFile». При нажатии он сохраняет данные, введенные пользователем. |
| Calculate1Click | OnClick(Calculate1) | Обработка нажатия Run -\&gt; Calculate. При нажатии он рассчитывает данные в соответствии с предустановленными настройками. |
| CleanAll1Click | OnClick(CleanAll1) | Обработка нажатия Edit-\&gt;EraseAll. При нажатии можете удалить все уравнения и значения |
| Deleteequaation1Click | OnClick(Deleteequaation1) | Обработканажатия Edit-\&gt;Delete Equation.При нажатии можете удалить уравнение. |
| Exit1Click | OnClick(Exit1) | Обработка нажатия File-\&gt;Exit. При нажатии можете удалить уравнение. |
| Form1Close | OnClose(Form1) | Проверьте, что программа сохранена |
| Form1Create | OnCreate(Form1) | Изменяет высоту строки. |
| New1Click | OnClick(New1) | Обработка нажатия File-\&gt;New. При нажатии создает новый проект. |
| Open1Click | OnClick(Open1) | Обработка нажатия File-\&gt;Open… . При нажатии вызывается диалог открытия файла. |
| Save1Click | OnClick(Save1) | Обработка нажатия File-\&gt;Save. При нажатии сохраняет ответы, рассчитанные программой |
| Saveas1Click | OnClick(Saveas1) | Обработка нажатия File-\&gt;SaveAs… . При нажатии сохраняет данные, введенные пользователем. |
| StringGrid1GetEditText | OnGetEditText(StringGrid1) | Включить кнопку Сохранить как |
| StringGrid1KeyPress | OnKeyPress(StringGrid1) | Проверяет правильность ввода символов. |
| StringGrid1SelectCell | OnSelectCell(StringGrid1) | Показывает номер выбранной ячейки в строке состояния. |


#### 3.1.1.4 Метод класса

| Название функции | Краткое описание | Результат работы |
| --- | --- | --- |
| int Calc(void) | Функция расчета методом Гаусса. У функции нет входных параметров. | Если система уравнений не определена, функция Calc () возвращает 0. В противном случае возвращаемое значение равно 1. |

## 3.2 Модуль«NumEqu»

### 3.2.1 Класс оконной формы TForm2

#### 3.2.1.1 Перечень компонентов, размещённых в форме

| Имя | Класс | Назначение |
| --- | --- | --- |
| **Button1** | TButton | Подтвердить ввод, сказав ОК |
| **Button2** | TButton | Прервать ввод, сказав отменить |
| **Edit1** | TEdit | Ввести значения |
| **Label1** | TLabel | Строка «Set the number of Equations :». |
| **Panel1** | TPanel | Панель на главной форме, которая является контейнером для помещенных на нее элементов. |
| **Panel2** | TPanel | Панель на главной форме, которая является контейнером для помещенных на нее элементов. |

#### 3.2.1.2 Перечень обработчиков событий

| Имя | Событие (элемент управления) | Суть обработки |
| --- | --- | --- |
| Button1Click | OnClick(Button1) | Подтвердить ввод, сказав ОК |
| Button2Click | OnClick(Button2) | Прервать ввод, сказав отменить |

# 4. Описание алгоритмов 
## 4.1 Алгоритм работы пользовательского интерфейса 

<img src="https://user-images.githubusercontent.com/91780755/161292536-b87e8b61-a42b-4943-aa97-a10a99cd010a.png" width="800">

## 4.2 Алгоритм работы метода Гаусса 
(TForm1::Button3Click)

<img src="https://user-images.githubusercontent.com/91780755/161292794-69db4246-7614-4a3a-993a-7b52722601cf.png" width="800">

## 4.3 Алгоритм метода обработки нажатия на кнопку «Open…»
(TForm1::Button4Click)

<img src="https://user-images.githubusercontent.com/91780755/161292849-dde03b30-9c26-428d-9e87-9a2eea395a73.png" width="600">

## 4.4 Алгоритм метода обработки нажатия на кнопку (Save As…)
(TForm1::Button6Click)

<img src="https://user-images.githubusercontent.com/91780755/161292891-3ffc100a-e0dc-4087-b669-b3566c6aa750.png" width="600">

## 4.5 Алгоритм метода обработки нажатия на кнопку (Save Results As…)
  (TForm1::Button5Click)

<img src="https://user-images.githubusercontent.com/91780755/161292940-91bd62ff-0ff7-47d8-9bbe-8ceaf9c1c444.png" width="600">




