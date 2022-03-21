# minishell_team

minishell

with jikwon, hyonn

## 목표


* 새로운 명령을 기다릴 때에는 prompt를 보여줘야(show) 한다.
* 정확히 실행가능한 path를 찾고 실행시켜야 한다. (PATH 변수를 이용하거나 상대 경로 또는 절대 경로를 이용하라. bash에서 처럼)
* bash에서 처럼 builtin을 implement시켜야 한다:
* '-n' 옵션을 가지는 echo
* 상대경로와 절대경로만을 인식하는 cd
* pwd without any options
* export without any options
* unset without any options
* env without any options and any arguments
* exit wtihout any options
* `;` 는 bash에서처럼 명령을 구분시켜야 한다.
* `'` 그리고 `"`는 여러 줄의(multiline) 명령인 경우를 제외하고 bash처럼 동작해야 한다.
* Redirection, 즉 <, >, ">>"는 bash처럼 동작해야 한다. File descriptor aggregation(집합)을 제외하고.
* Pipes(|)는 bash처럼 작동해야 한다.
* 환경변수(Environment variables)는 bash처럼 작동해야 한다.
* `$?` 는 bash처럼 작동해야 한다.
* Ctrl -C, ctrl -D 그리고 ctrl -\ 는 bash와 같은 결과를 가져야 한다.
