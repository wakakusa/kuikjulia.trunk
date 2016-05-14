#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"


/*****************************************************************************************************
 * function4:rmproc:remove process
*****************************************************************************************************/
 
/*****************************************************************************************************
 * function:ダイアログ作成
 * 
 * 
 * glade:workdirectory_chooserdialog
*****************************************************************************************************/
void create_rmprocess_dialog(StructPalletParallelWidget *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
{
  GtkBuilder *builder;
  GError* error = NULL;

  /* GtkBuilder作成 */
  builder = gtk_builder_new(); 
  
  /* UI_FILEの読み込み*/
  if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
  {
	g_warning ("Couldn't load builder file: %s", error->message);
	g_error_free (error);
  }

  /* windowのオブジェクト取得 */
  (struct_widget->function_window1) = GTK_WIDGET( gtk_builder_get_object(builder, Window_name)); 
  /*複数のウィジェットを操作する場合、構造体に格納にすること。
   * 格納先にあわせて、GTK_LABELやGTK_ENTRYなどGTK_～を変更すること。
   *不明な場合はGTK_WIDGETでも可能。ただしエラーは出力される。*/
   (struct_widget->entry_variable) = GTK_ENTRY(gtk_builder_get_object(builder, "Parallel_rm_process_entry1"));


  /* UI_FILEのシグナルハンドラの設定  This is important */
  gtk_builder_connect_signals (builder, &struct_widget); 

   g_object_unref( G_OBJECT( builder ) );
} 


/*****************************************************************************************************
 * function:ファイル選択ダイアログをOKで閉じ、処理する
 * 
 * 
 * glade:workdirectory_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void create_rmprocess_dialog_OK (GtkWidget *widget,gpointer data  )
{

  (Pallet_Parallel.variable) = gtk_entry_get_text(Pallet_Parallel.entry_variable);	

  (Pallet_Parallel.script1) = g_strconcat("rmprocs(",Pallet_Parallel.variable,")\n",NULL);
  
  (Pallet_Parallel.process_check_flag1) =TRUE;
  gtk_widget_destroy((Pallet_Parallel.function_window1)); 
}


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:workdirectory_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_Parallel_function4_for_terminal(GtkWidget *widget, gpointer data)
{
  create_rmprocess_dialog(&Pallet_Parallel,PalletInterfaceFile04,"Parallel_rm_process_dialog1");
  gtk_dialog_run(GTK_DIALOG(Pallet_Parallel.function_window1));
  gtk_widget_destroy(Pallet_Parallel.function_window1);
   
  if((Pallet_Parallel.process_check_flag1) ==TRUE)
  { 
	  Vte_terminal_insert(&VTE[VTE_No],Pallet_Parallel.script1);
	  g_free( Pallet_Parallel.script1 );
  }
  
  (Pallet_Parallel.process_check_flag1) =FALSE;
}


/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:workdirectory_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_Parallel_function4_for_editor(GtkWidget *widget, gpointer data)
{
  create_rmprocess_dialog(&Pallet_Parallel,PalletInterfaceFile04,"Parallel_rm_process_dialog1");
  gtk_dialog_run(GTK_DIALOG(Pallet_Parallel.function_window1));
  gtk_widget_destroy(Pallet_Parallel.function_window1);
  
  if((Pallet_Parallel.process_check_flag1) ==TRUE)
  { 
	  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],Pallet_Parallel.script1);
	  g_free( Pallet_Parallel.script1 );
  }
  
  (Pallet_Parallel.process_check_flag1) =FALSE;
}


