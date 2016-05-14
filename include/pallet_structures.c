/******************************************************************************
 * Title:Pallet Structure 
 * summary:Palletの構造体内容を定義
 * 
 *LastUpdate: 
******************************************************************************/

//基本形Palletの構造体内容を定義
typedef struct {
	GtkWidget *pallet_window,*function_window1;	//
	gchar *file_path1;	//set file name
	gchar *script1;				// script of command
	gboolean process_check_flag1;	//proc_flag1:OK button clicked
	const gchar *variable_name;
	GtkEntry *entry_variable_name;//
}StructPalletWidget;

/*構造体変数名を宣言*/
StructPalletWidget Pallet_Master; 
StructPalletWidget Pallet_Test;
StructPalletWidget Pallet_Essentials;


//FileSystemコマンド用Palletの構造体内容を定義
typedef struct {
	GtkWidget *pallet_window,*function_window1;	//
	gchar *file_path1;	//set file name
	gchar *script1;				// script of command
	gboolean process_check_flag1;	//proc_flag1:OK button clicked
	const gchar *variable_name;
	GtkEntry *entry_variable_name;//
}StructPalletFilesystemWidget;

/*構造体変数名を宣言*/
StructPalletFilesystemWidget Pallet_Filesystem;


//Parallel用Palletの構造体内容を定義
typedef struct {
	GtkWidget *pallet_window,*function_window1;	//
	gchar *file_path1;	//set file name
	gchar *script1;				// script of command
	gboolean process_check_flag1;	//proc_flag1:OK button clicked
	const gchar *variable_numeric;
	GtkEntry *entry_variable_numeric;//
	const gchar *variable;
	GtkEntry *entry_variable;//
}StructPalletParallelWidget;

/*構造体変数名を宣言*/
StructPalletParallelWidget Pallet_Parallel; 
