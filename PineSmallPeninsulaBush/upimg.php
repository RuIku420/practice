<!DOCTYPE html>
<html>




  <head>
      <meta charset="utf-8">
      <title>しげる？しげらない？</title>
      <link rel="icon" href="Matsuzaki_1.icoのURL">
      <link rel="stylesheet" href="result.cssのURL">

  </head>
  <body>
    <?php
      $command = "python.exe(各自のもの)のパス analyze.py";
      $command2 = "python.exe(各自のもの)のパス histcomp.py";
      //ここにおける$img_nameの中身はただのファイル名
      $img_name = $_FILES['upimg']['name'];
      //echo($img_name);
      //rename($img_name,"gazou")
      //画像を保存
      move_uploaded_file($_FILES['upimg']['tmp_name'], '.\\img\\' . $img_name);
      if (substr($img_name, -4) == '.png'){
        rename('.\\img\\' . $img_name, '.\\img\\gazou.png'); //とりあえずファイル名を変えることをこれで成功なり
      }else{
        rename('.\\img\\' . $img_name, '.\\img\\gazou.jpg'); //とりあえずファイル名を変えることをこれで成功なり
      }


      /*
      シングルクオーテーションで挟まれてない . は左右の文字列を結合するという意味やで
      */
      //pythonコマンドを実行

      exec($command,$opt,$return_ver);
      //echo($return_ver);  //異常終了はソースの途中でreturnされたり、elseの内部で終了されたりすることらしい
      //print_r($opt);

      exec($command2,$opt2,$return_ver);
      //echo($return_ver);  //異常終了はソースの途中でreturnされたり、elseの内部で終了されたりすることらしい
      //print_r($opt2);
    ?>
  <!--多分ここのlocalhostをipアドレスにするとスマホでも表示されるはず-->
  <div class="imgs">
    <img src="moto.jpgのURL?<?= uniqid() ?>" id="kakomotoimg"/>
    <p>加工元の画像</p>
    <img src="gazou.jpgのURL?<?= uniqid() ?>" id="kakogoimg"/>
    <p>加工後の画像</p>
    <!--orの理由は顔認識に失敗したら前の画像が残る、それとの比較した類似度が出ちゃう-->
    <!--なので顔認識できてても類似度が0を下回るなら加工後の画像を出さないことにする-->
    <?php if (end($opt) != "()" && end($opt2) > 0) { ?>
      <div class="koimgs">
        <img src="parent_image/Matsuzaki1FC.jpgのURL?" id="parimg"/>
        <img src="output/face_cut.jpgのURL?<?= uniqid() ?>" id="usrimg">
      </div>
  </div>
    <p>類似度は<?php echo(end($opt2)) ?>%</p>
  <?php } else { ?>
    <a>顔認識に失敗しました</a>
  <?php }?>
  </body>
</html>
