# Smart Home - SKT ICT 체험관 'T.um 모바일'
![Alt text](/images/smarthome_1.jpg?raw=true "SmartHome1")
![Alt text](/images/smarthome_2.jpg?raw=true "SmartHome2")

## Overview
SKT의 이동형 ICT 체험관 ‘T.um 모바일’이 서해 최전방 연평도에서 첨단 기술 교육과 청소년들을 위한 다채로운 체험행사를 진행했다.
본 코드는 'T.um 모바일'의 IoT 부스에 전시한 Smart Home 체험관의 아두이노 소스코드이다.

## Project Goals
아두이노와 센서 그리고 LoRa 네트워크를 활용하여 Smart Home을 간접적으로 체험할 수 있으며, 원리의 이해를 돕는 체험 부스를 설계한다.
Smart Home에서 축적되는 센서값을 대쉬보드에 시각화한다.

- LoRa 네트워크 망의 활용
- Smart Home의 기능을 모형 집에 구현
- 단계별로 직접 Smart Home의 기능을 개발하도록 설계

## Main Features
- 어플로 문 열기 : LoRa 망
- 어플로 선풍기 틀기 : LoRa 망
- 자동 문 열림 : 적외선 거리 탐지
- 조이스틱 조명색 컨트롤 : LoRa 망, LED, 조이스틱
- 자동 불켜짐 : 조도 센서

## Some Challenges
- LoRa의 신호가 동시에 좁은 공간에서 발생시 수신에 딜레이가 생기는 이슈가 있었다.
- 시연하는 곳의 조명 밝기에 따라서 조도 센서 초기값을 새로 세팅해야하는 이슈가 있었다.

## [SK텔레콤 첨단 ICT 체험관 T.um 모바일]
![Alt text](/images/article_1.jpg?raw=true "Article1")
![Alt text](/images/article_2.jpg?raw=true "Article2")

[SK텔레콤 첨단 ICT 체험관 T.um 모바일]: https://www.sktinsight.com/88610