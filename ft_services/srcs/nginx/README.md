#CHECK
1. Dockerfile env 삭제
2. SSH_USER = jikwon, SSH_PWD = 2021 변수로 설정하기. 

# Promblem01
## 상황
첫번째 컨테이너에서 ssh 접속을 한 후, 새로운 컨테이너를 만들고, 
`ssh $SSH_USER@IP` 접속을 할때.

## 에러
WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED

## 해결
`ssh-keygen -R IP`
RSA 공유키 충돌 문제. 한번 접속할 경우 호스트에서 해당 서버에 대한 정보를 저장하게 되는데 새로운 컨테이너 서버로 접속시 정보가 일치하지 않아 발생. 
