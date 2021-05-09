# BC-101 Hookup Guide
BC-101 為基於[ Arduino Micro ](https://store.arduino.cc/usa/arduino-micro)為基礎打造而成的開源[ MIDI Controller ](https://en.wikipedia.org/wiki/MIDI_controller)<br>
本文為BC-101的組裝說明書，目錄如下：
* 開箱準備
* 零件清點
* 工具準備
* 零件焊接
* 韌體燒錄
* 功能測試
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/00.png?w=1024)
## 開箱準備
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/01-2.jpg?w=1024)<br><br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/02-3.jpg?w=1024)<br><br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/03-3.jpg?w=1024)<br><br>
## 零件清點
* BC-101 主板 x 1
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/04.jpg?w=1024)<br><br>
* Arduino Micro 控制器模組 x 1、Micro USB 線材 x 1
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/05.jpg?w=1024)<br><br>
* LCM1602 顯示器模組 x 1
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/06.jpg?w=1024)<br><br>
* 電阻220Ω x 5、電阻10KΩ x 5、二極體 x 1、撥盤電位器 x 1
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/08.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/07.jpg?w=1024)<br><br>
* 積體電路PC900V x 1、積體電路CD74HC4051E x 6、3.5mm音頻插座 x 2
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/10.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/09.jpg?w=1024)<br><br>
* 按鍵開關(白色) x 33、按鍵開關(黃色) x 4、按鍵帽(白色) x 19<br>按鍵帽(黑色) x 10、按鍵帽(綠色) x 2、按鍵帽(紅色) x 2、按鍵帽(黃色) x 2、按鍵帽(藍色) x 2
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/12.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/11.jpg?w=1024)<br><br>
* 跳線帽 x 20、1x16排針公座 x 1、2x3排針公座 x 1、2x6排針公座 x 2、2x8排針公座 x 1<br>1x6排針母座 x 1、1x8排針母座 x 2、1x10排針母座 x 1、1x16排針母座 x 1、1x17排針母座 x 2
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/14.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/13.jpg?w=1024)<br><br>
* 旋鈕 x 8、旋轉電位器 x 8
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/16.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/15.jpg?w=1024)<br><br>
* 6.5mm音頻插座 x 1、雙軸搖桿 x 1、蘑菇頭 x 1、塑膠螺絲 x 2、塑膠螺帽 x 2、塑膠銅柱 x 2、橡膠腳墊 x 8
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/18.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/17.jpg?w=1024)<br><br>
## 工具準備
* 電烙鐵、焊錫、排煙機（非必要，但建議使用；若無排煙機建議保持焊接時的空氣流通）
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/19.jpg?w=1024)<br><br>
* IC整角器、小十字起子、尖嘴鉗、6mm套筒起子、電阻折角器<br>
（其中IC整角器、電阻折角器、套筒起子為非必要之工具，使用的話可增加組裝流暢度）
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/20.jpg?w=1024)<br><br>
## 零件焊接
焊接零件時，首先從高度矮的零件依序往高的零件焊起，所以首先處理二極體、電組和撥盤電位器<br>
- STEP1：焊接二極體、電組、撥盤電位器<br><br>
  - 先將二極體和電阻從料袋拿出，這時若有電組折角器會方便很多
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/21.jpg?w=1024)<br><br>
  - 將電阻放至折角器的適當位置
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/22.jpg?w=1024)<br><br>
  - 將電阻雙腳順著折角器的方向壓下
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/23.jpg?w=1024)<br><br>
  - 折完腳的二極體和電組
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/24.jpg?w=1024)<br><br>
  - 將二極體放置電路板D1位置，二極體是有方向的，因此二極體零件上左方的黑線記號需要朝左
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/34.jpg?w=1024)<br><br>
  - 放置完零件後將電路板翻面，準備好已預熱好的烙鐵和銲錫，準備焊接零件
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/26.jpg?w=1024)<br><br>
  - 焊接中
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/27.jpg?w=1024)<br><br>
  - 第一個焊點完成
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/28.jpg?w=1024)<br><br>
  - 再將第二個焊點完成
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/29.jpg?w=1024)<br><br>
  - 使用斜口鉗將零件腳都剪除，剪腳時建議用手將零件腳抓住再剪，防止零件腳亂飛
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/30.jpg?w=1024)<br><br>
  - 零件焊接完成
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/31.jpg?w=1024)<br><br>
  - 依照上述方法將R1~R7位置焊上10KΩ電組，共7個
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/32.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/35.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/33.jpg?w=1024)<br><br>
  - 依照上述方法將R8~R12位置焊上10KΩ電組，共5個
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/37.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/36.jpg?w=1024)<br><br>
  - 接著將POT1位置焊上10KΩ撥盤電位器
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/38.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/39.jpg?w=1024)<br><br>
  - STEP1至此完成
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/40.jpg?w=1024)<br><br><br><hr>
- STEP2：焊接積體電路IC、3.5mm音頻插座<br>
  - 先將積體電路IC從料袋拿出，這時若有IC整角器也會方便很多
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/41.jpg?w=1024)<br><br>
  - 將積體電路IC放置於整角器上
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/42.jpg?w=1024)<br><br>
  - 雙手分別置於整腳器上下緣
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/43.jpg?w=1024)<br><br>
  - 雙手平均施力向內壓
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/44.jpg?w=1024)<br><br>
  - 整腳完將IC拿出，其餘的IC也執行相同動作
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/45.jpg?w=1024)<br><br>
  - 準備一顆CD74HC4051E，並焊在MUX1位置上
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/46.jpg?w=1024)<br><br>
  - 將IC放入電路板的孔位，注意IC是有方向性的，外觀的缺口要朝左<br>另外，若此時的IC腳未往內壓過的話，會發現無法順利放入
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/47.jpg?w=1024)<br><br>
  - 將電路板翻面開始焊接
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/48.jpg?w=1024)<br><br>
  - 焊接完成
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/49-1.jpg?w=1024)<br><br>
  - 將其餘的MUX2~MUX6位置均焊上CD74HC4051E
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/50-1.jpg?w=1024)<br><br>
IC1位置則是焊上PC900V，一樣注意IC的圓圈記號朝左
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/51.jpg?w=1024)<br><br>
  - 將兩個3.5mm音頻插座分別放入MIDI-IN和MIDI-OUT的位置上
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/52.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/53.jpg?w=1024)<br><br>
  - 將電路板翻面開始焊接
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/54.jpg?w=1024)<br><br>
  - STEP2至此完成
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/55.jpg?w=1024)<br><br><br><hr>
- STEP3：焊接按鍵開關<br>
  - 先將黃色按鍵開關放置SW1~SW4位置
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/56.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/59.jpg?w=1024)<br><br>
  - 將電路板翻面開始焊接
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/57.jpg?w=1024)<br><br>
  - 焊接完成
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/58.jpg?w=1024)<br><br>
  - 如上述步驟，將SW1~SW4位置焊上白色按鍵開關
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/60.jpg?w=1024)<br><br>
  - 如上述步驟，將KEY1~KEY12位置焊上白色按鍵開關
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/61.jpg?w=1024)<br><br>
  - 如上述步驟，將KEY13~KEY25位置焊上白色按鍵開關
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/62.jpg?w=1024)<br><br>
  - 準備按鍵帽
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/63.jpg?w=1024)<br><br>
  - 將KEY23裝上黑色按鍵帽
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/64.jpg?w=1024)<br><br>
  - KEY23按鍵帽安裝完成
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/65.jpg?w=1024)<br><br>
  - 將按鍵帽全數安裝，STEP3至此完成
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/66.jpg?w=1024)<br><br><br><hr>
- STEP4：焊排針<br><br>
  - 將1x16排針母座放置於Monitor位置
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/67.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/68.jpg?w=1024)<br><br>
  - 將兩個1x17排針母座放置於Arduino Micro位置
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/69.jpg?w=1024)<br><br>
  - 其餘排針母座依對應位置放置於Arduino Shiled區域
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/70.jpg?w=1024)<br><br>
  - 將排針母座依序焊接完成
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/71.jpg?w=1024)<br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/72.jpg?w=1024)<br><br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/75.jpg?w=1024)<br><br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/73.jpg?w=1024)<br><br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/74.jpg?w=1024)<br><br>

![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/76.jpg?w=1024)<br><br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/77.jpg?w=1024)<br><br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/78.jpg?w=1024)<br><br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/79.jpg?w=1024)<br><br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/80.jpg?w=1024)<br><br>
![GitHub Logo](https://mainnolab.files.wordpress.com/2021/05/81.jpg?w=1024)<br><br>
## 韌體燒錄
## 功能測試
