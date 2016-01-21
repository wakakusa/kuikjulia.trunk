#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"


/**********************************************************************************************
 * read_data function4:Excelファイルの読み込み 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:データ読み込み用ダイアログ表示callback関数。 
 * 
 * 
 * glade:Read_Delimfile_chooserdialog1
 **********************************************************************************************/
void create_ReadExcel_filechooserdialog(StructPalletReadWriteData *struct_widget,char UI_FILE[256],char Window_name[512])
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
	(struct_widget->entry_variable_name) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_entry_variable_name"));

	(struct_widget->entry_sheet) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_entry_sheet"));

	(struct_widget->entry_region) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_entry_region"));
   
	(struct_widget->checkbutton_header) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_checkbutton_header"));
	
	(struct_widget->checkbutton_nastrings) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_checkbutton_nastrings"));
	(struct_widget->entry_nastrings) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_entry_nastrings"));
	
	(struct_widget->checkbutton_truestrings) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_checkbutton_truestrings"));
	(struct_widget->entry_truestrings) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_entry_truestrings"));

	(struct_widget->checkbutton_falsestrings) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_checkbutton_falsestrings"));
	(struct_widget->entry_falsestrings) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_entry_falsestrings"));

	(struct_widget->checkbutton_colnames) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_checkbutton_colnames"));
	(struct_widget->entry_colnames) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_entry_colnames"));
	
	/* UI_FILEのシグナルハンドラの設定  This is important */
	gtk_builder_connect_signals (builder, &struct_widget); 

	g_object_unref( G_OBJECT( builder ) );
}



/**********************************************************************************************
 * function:ファイル選択ダイアログをOKで閉じ、処理する 
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void ReadExcel_filechooserdialog_FileOpen_OK (GtkWidget *widget,gpointer data  )
{
	const gchar *toggle_button_active_str[]={"false","true"}; 
	//OKボタンを押下したので後続処理を実行させるためにflagを変更する。

	
	//変数名取得
	Pallet_Read_Data.variable_name=gtk_entry_get_text(Pallet_Read_Data.entry_variable_name);
	
	//読み込み対象ファイル名を取得
	Pallet_Read_Data.file_path1 = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Read_Data.function_window1));
	Pallet_Read_Data.script1 =g_strconcat("using Taro\nTaro.init()\n",Pallet_Read_Data.variable_name,"=Taro.readxl(\"",Pallet_Read_Data.file_path1,"\"",NULL);
	g_free(Pallet_Read_Data.file_path1);
	
	//sheet
	Pallet_Read_Data.sheet=g_strconcat(",\"",gtk_entry_get_text(Pallet_Read_Data.entry_sheet),"\"",NULL);
	Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.sheet,NULL);
	g_free(Pallet_Read_Data.sheet);
	
	//region
	Pallet_Read_Data.region=g_strconcat(",\"",gtk_entry_get_text(Pallet_Read_Data.entry_region),"\"",NULL);
	Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.region,NULL);
	g_free(Pallet_Read_Data.region);

	//header
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_header);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.header=g_strconcat(",header=",toggle_button_active_str[Pallet_Read_Data.toggle_button_active],NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.header,NULL);
		g_free(Pallet_Read_Data.header);
	}
	
	//nastrings
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_nastrings);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.nastrings=g_strconcat(",nastrings=[",gtk_entry_get_text(Pallet_Read_Data.entry_nastrings),"]",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.nastrings,NULL);
		g_free(Pallet_Read_Data.nastrings);	
	}
	
	//truestrings
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_truestrings);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.truestrings=g_strconcat(",truestrings=[",gtk_entry_get_text(Pallet_Read_Data.entry_truestrings),"]",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.truestrings,NULL);
		g_free(Pallet_Read_Data.truestrings);
	}
	
	//falsestrings
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_falsestrings);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.falsestrings=g_malloc(g_strconcat(",falsestrings=[",gtk_entry_get_text(Pallet_Read_Data.entry_falsestrings),"]",NULL));
		Pallet_Read_Data.falsestrings=g_strconcat(",falsestrings=[",gtk_entry_get_text(Pallet_Read_Data.entry_falsestrings),"]",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.falsestrings,NULL);
		g_free(Pallet_Read_Data.falsestrings);
	}

	//colnames
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_colnames);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.colnames=g_strconcat(",colnames='",gtk_entry_get_text(Pallet_Read_Data.entry_colnames),"'",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.colnames,NULL);
		g_free(Pallet_Read_Data.colnames);
	}
	

	//finish
	Pallet_Read_Data.script1=g_strconcat(Pallet_Read_Data.script1,");\n",NULL);
	(Pallet_Read_Data.process_check_flag1) =TRUE;

	gtk_widget_destroy((Pallet_Read_Data.function_window1)); 
}


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:Read_Excelfile_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_read_data_function4_for_terminal(GtkWidget *widget, gpointer data)
{
  create_ReadExcel_filechooserdialog(&Pallet_Read_Data,PalletInterfaceFile02,"Read_Excelfile_chooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.function_window1));
  gtk_widget_destroy(Pallet_Read_Data.function_window1);
    
  if((Pallet_Read_Data.process_check_flag1)==TRUE)
  {
    Vte_terminal_insert(&VTE[VTE_No], Pallet_Read_Data.script1 );
    g_free( Pallet_Read_Data.script1 );
  }
  (Pallet_Read_Data.process_check_flag1)=FALSE;

}


/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:Read_Excelfile_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_read_data_function4_for_editor(GtkWidget *widget, gpointer data)
{
  create_ReadExcel_filechooserdialog(&Pallet_Read_Data,PalletInterfaceFile02,"Read_Excelfile_chooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.function_window1));
  gtk_widget_destroy(Pallet_Read_Data.function_window1);
   
  if((Pallet_Read_Data.process_check_flag1)==TRUE)
  {
    ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No], Pallet_Read_Data.script1 );
    g_free( Pallet_Read_Data.script1 );
  }
  (Pallet_Read_Data.process_check_flag1)=FALSE;

}


