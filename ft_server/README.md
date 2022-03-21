
## 소개
이 서브젝트는 시스템 관리를 소개합니다.
이는 스크립트를 사용하여 작업을 자동화하는 것의 중요성을 알려줄 겁니다. 

이를 위해, 당신은 “docker”기술을 이해하고 이를 이용해 완전한 웹 서버를 설치하십시오.
이 서버는 동시에 여러 서비스를 실행할 것입니다. : Wordpress, phpMyAdmin, SQL database.

## 규칙
* ./srcs/서버_구성에_필요한_모든_파일_넣기
* ./srcs/워드프레스_웹사이트에_필요한_모든_파일_넣기
* 도커파일이 당신의 컨테이너를 빌드 할 것입니다. docker compose는 사용 금지.
* 딱 하나의 도커 컨테이너에 Nginx가 있는 웹 서버를 설정해야합니다. 컨테이너 OS는 꼭 debian buster여야합니다
* 웹 서버는 여러 서비스를 동시에 실행할 수 있어야합니다.
* 그 서비스들은 WordPress 웹 사이트, phpMyAdmin, MySQL 입니다.
* SQL 데이터베이스가 WordPress 및 phpMyAdmin과 작동하는지 확인해야합니다.
* 서버는 SSL 프로토콜을 사용할 수 있어야합니다.
* URL에 따라 서버가 올바른 웹 사이트로 리디렉션되는지 확인해야합니다.
* 서버가 오토 인덱스로 실행 중인지 확인하고, 이를 비활성화 할 수 있어야합니다.