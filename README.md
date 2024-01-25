# [STM32] ELEVATOR

<aside>
💡 NUCLEO-F429ZI 개발 보드와 FREERTOS를 사용한 STM32 기반 엘리베이터

</aside>

### 결과물

---

![result.jpg](https://prickle-starburst-015.notion.site/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2Fa94a1061-03b0-48eb-abdf-da844b5d915c%2Fd0efb8f9-2b21-4762-a46a-bdb7be7530c5%2FIMG_3150.jpg?table=block&id=41da7479-e996-4698-a78e-2657722ac3b7&spaceId=a94a1061-03b0-48eb-abdf-da844b5d915c&width=2000&userId=&cache=v2)


### 프로젝트 기간

---

2024.01.23 ~ 2024.01.24 (2일)

### 개발 도구

---

STM32CubeIDE

### 요구 사항

---

| 요구 사항 | 사용 모듈 | 달성 |
| --- | --- | --- |
| 가고자 하는 층을 선택한다 | 버튼, LCD | 100% |
| 선택한 층으로 이동한다 | 스텝 모터 | 100% |
| 이동 중일 때는 층을 선택할 수 없다 |  | 100% |
| 멈춰있을 때, 위로 갈 때, 아래로 갈 때를 다르게 표현해야 한다 | Dot matrix | 100% |
| 현재 층을 나타내야 한다 | FND, Photo coupler | 100% |
| 일시 정지하면 진행 방향의 다음 층에 도착하고 멈춰야 한다 | 조도 센서 | 100% |
| 현재 층은 선택할 수 없다 |  | 100% |

### 다이어그램

---

- **FSM**

![fsm.png](https://prickle-starburst-015.notion.site/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2Fa94a1061-03b0-48eb-abdf-da844b5d915c%2Fe3d75787-7a83-47b2-9f17-13606920fca0%2F%25EC%258A%25A4%25ED%2581%25AC%25EB%25A6%25B0%25EC%2583%25B7_2024-01-25_094056.png?table=block&id=ccc84853-d7f9-4cdf-bba9-5a687fb4d197&spaceId=a94a1061-03b0-48eb-abdf-da844b5d915c&width=1490&userId=&cache=v2)

- **시퀀스 다이어그램**

![sequence_diagram.png](https://prickle-starburst-015.notion.site/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2Fa94a1061-03b0-48eb-abdf-da844b5d915c%2F538f2d85-b021-41b5-8c0d-2b3519b41e75%2Felevator_sd.png?table=block&id=4d2bdc46-c2a7-4b0b-9206-e9cd9bcfc85b&spaceId=a94a1061-03b0-48eb-abdf-da844b5d915c&width=1140&userId=&cache=v2)

### 시연

---

[![Video Label](http://img.youtube.com/vi/F2Nfsbo0o_4/0.jpg)](https://youtu.be/F2Nfsbo0o_4)
