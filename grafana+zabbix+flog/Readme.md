Постановка задачи

С помощью генератора поддельных логов "flog" ( https://github.com/mingrammer/flog ) заполнить ими файл любым количеством, создать отдельный Item мониторинга логов в свободной системе мониторинга Zabbix, удостовериться в безошибочной работе во вкладке latest data, следующим шагом подключить к Grafana для наглядной визуализации.


1. После установки Flog в ОС Ubuntu проверю работоспособность генерации логов в размере 5 записей
![image](https://user-images.githubusercontent.com/73434222/145996982-de0ae83b-af15-435d-a9d5-20b5ae23e13f.png)
2. Следующим шагом заполню файл логами 
![image](https://user-images.githubusercontent.com/73434222/145997232-9a7a9b13-c3c9-4e7c-a288-dbc1cd1472b4.png)
![image](https://user-images.githubusercontent.com/73434222/145997342-ca0212e0-ca6b-4f23-afe3-401263ddf76c.png)
3.Далее создам Item на хосте Zabbix server и произведу поиск нужных логов, по ключевому слову "PUT"
![image](https://user-images.githubusercontent.com/73434222/145997594-1ebc3a76-aa72-4bb9-8d4c-5989836ea4ce.png)
![image](https://user-images.githubusercontent.com/73434222/145997733-0abbe976-2e51-401a-863c-b10d46ccffa1.png)
4.После установки Grafana установлю плагин Zabbix и создам базу данных Zabbix, впоследствии создам "Dashboard", в котором будет находиться таблица найденных логов, а также для примера добавлю таблицу системных логов, найденных по ключевому слову "housekeeper" и выведу график использования памяти
![image](https://user-images.githubusercontent.com/73434222/145998483-ed8057ab-a064-46a6-816f-37c913918275.png)
