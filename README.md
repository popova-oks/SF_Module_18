# SF_Module_18
## Cчитывание и запись в файл

*Программа записывает в файл и считывает из файла состояния объектов классов User и Message.*
*При создании файлов устанавливаем, чтобы они были недоступны для других пользователей:*
*прочитать или записать информацию в файлы может только текущий пользователь.*

### Структура программы

1. void set_permissions функция устанавливает права доступа только для владельца
2. void demo_perms функция для демонстрации прав доступа к файлу
3. Работа с файлами может осуществляться как с использованием функций, так и с использованием перегруженных операторов:
   - void SaveState
   - void LoadState

   - std::ostream &operator<< 
   - std::fstream &operator>>    
5. В Makefile созданы синтетические цели: all, clean, install и uninstall

