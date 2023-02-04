# TRINITY　LEGENDS

河原電子ビジネス専門学校

ゲームクリエイター科 １年	石村幸徳
***
## 1.	作品の概要  
### ・TRINITY　LEGENDS(トリニティレジェンズ)

　三人称視点のプッシャー式メダルゲームで、
最初に与えられる**1000枚**から、一定数のメダルを獲得口に落とすとフィールドに投下されるボールを落とし、メダルの大量獲得を目指すゲームです。

<iframe width="560" height="315" src="https://www.youtube.com/embed/E4G8Av2CdBI" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

### ・使用ゲームエンジン

学校内製エンジンを改造して使用

### ・使用ツール

Visual Studio 2022

3ds Max 2023

Adobe Photoshop 2023

### ・使用言語

C++

HLSL

### ・開発環境

Windows11

DirectX12

・制作人数
1人

・開発期間
2022年9月～2023年1月
***

## 2.	　操作解説
### ・ゲーム画面時

　　Aボタン：メダルの投下

　　右スティック：カメラの移動(制限あり)

上下ボタン：レベルの選択

STARTボタン：レベルの決定

***
## 3.	　作成したソースコード
・BackGround.cpp

・BackGround.h

・Ball1.cpp

・Ball1.h

・Ball2.cpp

・Ball2.h

・Ball3.cpp

・Ball3.h

・Bout.cpp

・Bout.h

・Bouto.cpp

・Bouto.h


・CharacterControllerCylinder.cpp

・CharacterControllerCylinder.h

・Choice.cpp

・Choice.h

・Counter.cpp

・Counter.h

・Game.cpp

・Game.h

・GameClear.cpp

・GameClear.h

・Gameover.cpp

・Gameover.h

・Haitou.cpp

・Haitou.h

・Medal.cpp

・Medal.h

・PhysicsCylinderObject.cpp

・PhysicsCylinderObject.h

・PhysicsSphereObject.cpp

・PhysicsSphereObject.h

・PhysicsStaticObjectM.cpp

・PhysicsStaticObjectM.h

・PhysicsStaticObjectP.cpp

・PhysicsStaticObjectP.h

・Pusher.cpp

・Pusher.h

・Text.cpp

・Text.h

・Title.cpp

・Title.h
***
## 4.	　改造したエンジンのコード
### ・ModelRender.cpp、ModelRender.h、MeshParts.cpp

頻繁に呼び出すモデルの軽量化を行えるように変更

### ・PhysicsGhostObject.cpp、PhysicsGhostObject.h

円柱コライダーを作成できるように変更
### ・CollisionObject.h

円柱コライダーの当たり判定を取るコードを追加
***
## 5.	　物理的挙動
メダルゲームを作るにあたって、挙動をプログラムで制御するのは公平性に欠けるため、**メダルやボールの挙動を、物理制御にしました**。
また、摩擦力を設定し、メダルが落ちそうで落ちないハラハラ感を演出するようにしました。
***
## 6.	ゲームでのこだわり部分
### ・横穴の実装
ゲームセンターで見かけるメダルゲームと遜色ないようにするために、メダルが横に流れる横穴(アウトポケット)を実装し、容易にゲームをクリアできないようにしました。
また、レベル選択で横穴の開度を選択できるようにし、メダルゲームが得意ではない人でも楽しめるようにしました。

### ・ボール払い出し装置
　　ボールをそのまま排出するのは味気ないと思ったため、払い出し装置に演出を加え、
直接ボールを獲得出来る機会を設けました。
### ・ペイアウト率
独自で計算されたメダルの獲得率を示したペイアウト率を実装し、目視だけだはなくデータでも分かるようにしました。
### ・JP抽選
　　ゲームクリアの近道であるJPを簡単に獲得させないようにするために、実機と同等かそれ以上の難易度(10分の1～300分の1)に調整しました。