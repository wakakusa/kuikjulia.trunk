kuikjulia
===

##このアプリケーションは？
juliaのスクリプト記述と実行を補助するアプリケーションです。

##必要なライブラリ
cmake >= 2.64  
GTk+3 >= 3.14  
gtksourceview >= 3.14  
vte >= 0.38  
gmodule >= 2.42  

gtksourceviewとvteはgladeでも利用できるようにしておいて下さい。

##コンパイル方法
以下の手順で実行してください。ダウンロードしてきたファイル名をkuikujulia-*.tar.gzとします。  
tar zxf kuikjulia-*.tar.gz  
cd kuikjulia-*  
cmake .  
make  

##実行方法
解凍した圧縮ファイルのディレクトリ配下で以下のコマンドを実行してください。  
./src/kuikjulia

##ショートカットキー
 command | shortcut kye
---------|--------------
copy     |Ctrl+c
paste    |Ctrt+v
undo     |Ctrl+z
redo     |Ctrl+y