## Игра рутина окрасит ненастье
Игра в жанре ресурс-менеджер с элементами аркады. Проект выполнен в рамках всероссийского хакатона "Начни игру". Задача хакатона поиск перспективных разработчиков России 
## Установка и запуск проекта
- Для запуска проекта из исходного кода, необходимо скачать актуальную, на момент выхода проекта, версию движка DecaDot (внутренний форк движка Godot, поддерживаемый нашей командой). Открыть проект в дереве проектов и запустить
- Скачать скомпилированный бинарный файл проекта, на  [сайте итогов проведения конкурса](https://ims.cr5.space/app/p/5Nt6Uo5H/Рутина-окрасит-ненастье/about). Запустить exe файл
## Основной функционал проекта
- **Навыки планирования:**
    - Игрок учится распределять ограниченные ресурсы (время, энергия) для достижения наилучшего результата, что полезно в реальной жизни.

- **Тренировка памяти и реакции:**
    - Мини-игры развивают когнитивные способности, улучшая память, скорость принятия решений и внимательность.

- **Анализ и адаптация:**
    - Игрок анализирует последствия своих решений, учится адаптироваться к изменяющимся условиям и разрабатывать новые стратегии.

- **Стресс-менеджмент:**
    - Ситуации ограниченного времени и ресурсов помогают тренировать управление стрессом и работать в условиях неопределённости.

- **Распределение времени и ресурсов:**
    - Игровой день делится на три части: утро, день и вечер.
    - Каждое действие занимает определённую часть дня, но приносит ресурсы, или позволяет выполнить ключевую цель.
    - Некоторые действия ограничены временем суток.

- **Мини-игры на память и реакцию:**    
    - Мини-игры разнообразят игровой процесс и проверяют внимательность, быстроту реакции и способность запоминать.
    - Успех в мини-играх повышает эффективность действий

- **Уникальные ограничения:**    
    - Определённые действия не требуют времени, но накладывают ограничения (например, можно выполнять действия только внутри дома).
    - Игроку нужно учитывать баланс между ограничениями и выгодой.

- **Ключевые задачи и цели:**  
    - Игроку необходимо грамотно планировать ресурсы и время, чтобы выполнить обязательные ключевые точки.

## Технологии и инструменты
- DecaDot (Godot fork) - основной фреймворк и инструмент написания, для реализации проекта. DecaDot является внутренним движком команды, содержа в себе некоторые улучшения (система логгирования, интеграция с Arc, багтреккинг), является форком готового решения Godot, форк содержит в себе базовую универсальную архитектуру, реализация которой происходит в отдельных проектах, исходя из их целей и задач, позволяет избегать сильной связности и ошибок ООП, так как контракты заключены на низком уровне. 
- C++ - Высокопроизводительный язык программирования, подходящий для разработки приложений с требовательными требованиями к ресурсам. Благодаря своей эффективности и гибкости, позволяет реализовать сложные механики и обеспечить стабильность работы при больших объёмах данных.
## Команда проекта
Натаров Олег - программист и гейм-дизайнер
Ивлев Егор - 2д художник
Савосин Александр - саунд дизайнер и актер озвучки
Аношин Сергей - 3д дизайнер
## Демонстрация работы проекта
<br>.
[Видео Игрового процесса](https://www.youtube.com/watch?v=XDsNBaxpsS8&embeds_referring_euri=https%3A%2F%2Fims.cr5.space%2F&source_ve_path=Mjg2NjY)
<br><br><br>
![Скриншот 1](https://fs.cr5.space/file/p-5Nt6Uo5H/06b32f57-46aa-4f4a-a6a9-85ebb6a1d6b8/thumb/1232/674/outside)
![Скриншот 2](https://fs.cr5.space/file/p-5Nt6Uo5H/2cc96454-3983-4466-bb03-74d8f5bb3eee/thumb/1232/674/outside)
![Скриншот 3](https://fs.cr5.space/file/p-5Nt6Uo5H/8208cc65-f387-4492-9a27-a9b15401f44b/thumb/1232/674/outside)
![Скриншот 4](https://fs.cr5.space/file/p-5Nt6Uo5H/17a3d8d7-4e38-4979-8115-d583ca2289c1/thumb/1232/674/outside)

## Финальный текст-заключение
Проект обладает высокой системностью на геймплейном уровне, каждое действие влияет на общее состояние игрока и всей системы, также общий визуально приятный стиль, который согласован сам с собой и с атмосферой игры, за счет чего игра ощущается цельной и общей. На техническом уровне проект как отдельно следует принципам ооп, так и за счет внутреней архитектуры избегает высокой связности, что позволяет проводить большое масштабирование проекта, как в глубину так и в ширину.