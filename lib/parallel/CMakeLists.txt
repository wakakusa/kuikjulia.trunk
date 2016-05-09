#cmake 必要バージョン
#cmake_minimum_required(VERSION 2.6.4)
# プロジェクト名
#####共有ライブラリの作成
#project(kuikjulia)

# SHARED Libraryのバージョン
SET(soparallel "1.0.0")

###### EXECUTABLE&SORCE_DEFINE #####
## 元となるソースSET
SET(PALLET ${PROJECT_LIBRARY_DIR}/pallet_create.c)
SET(FUNCTION_SOURCE pallet_parallel.c
#pallet_parallel_function01.c
pallet_parallel_function02.c)


##ライブラリの作成
add_library(${FUNCTION_LIB_PARALLEL} SHARED ${PALLET} ${FUNCTION_SOURCE})


