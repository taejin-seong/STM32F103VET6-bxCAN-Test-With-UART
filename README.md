## 개발 환경<br>
### IDE
* STM32CubeIDE 1.6.0 <br>
* STM32CubeMX <br>

### 개발 보드
* **STM32F103VET6 Custom Development Board** <br>
  + :pushpin: [이미지 링크 및 구매처](https://ko.aliexpress.com/item/32693544239.html?gatewayAdapt=glo2kor&srcSns=sns_KakaoTalk&spreadType=socialShare&bizType=ProductDetail&social_params=20527276655&aff_fcid=6a92134b6f66447fb4e5392261410de1-1649825428883-09137-_mMqvBK2&tt=MG&aff_fsk=_mMqvBK2&aff_platform=default&sk=_mMqvBK2&aff_trace_key=6a92134b6f66447fb4e5392261410de1-1649825428883-09137-_mMqvBK2&shareId=20527276655&businessType=ProductDetail&platform=AE&terminal_id=62559df8374f42348f14bc09e497c7f3&afSmartRedirect=y)<br>
  
  + :pushpin: [개발보드 회로도](https://github.com/taejin-seong/STM32F103VET6-bxCAN-Test-With-UART/tree/master/STM32F103VET6%20Dev%20Board%20Schematic)<br>
    - 제공되는 개발보드 회로도를 확인해 본 결과, 회로도에 표기되어있는 커넥터 및 핀 헤더명이 실제 보드의 커넥터 및 핀 헤더명과 서로 다른 것을 확인하였습니다. **이를 주의하시고** 회로도를  보시길 바랍니다. <br><br>
 
### CAN 트랜시버 모듈
* **SN65HVD230 CAN Board** <br>
  + :pushpin: [이미지 링크 및 구매처](https://www.waveshare.com/sn65hvd230-can-board.htm) <br>
  
  + :pushpin: [해당 트랜시버 모듈 데이터시트 및 회로도](https://github.com/taejin-seong/STM32F103VET6-bxCAN-Test-With-UART/tree/master/SN65HVD230%20CAN%20Board%20Datasheets%20%26%20Schematic)<br>
    - 사용한 CAN 트랜시버 모듈에는 **종단저항 120Ω**이 실장되어 있으므로 따로 종단저항을 구성하여 회로를 설계하지 않아도 됩니다.
    <p align="center">
      <img src="https://user-images.githubusercontent.com/70312248/166659288-7debcb52-83cb-4e70-aa4e-5cef46597f41.png" width="630" height="280"/>  
    </p>  
    
 
