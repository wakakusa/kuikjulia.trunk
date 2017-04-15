#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"


/************************************************************************************************************
 * function2:get process numeric 
************************************************************************************************************/

/************************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:none
************************************************************************************************************/
G_MODULE_EXPORT void cb_Parallel_function2_for_terminal(GtkWidget *widget, gpointer data)
{
  
  gchar *script;
  g_free(script);
  
  script=g_strconcat("workers()\n",NULL);
  Vte_terminal_insert(&VTE[VTE_No],script);
  g_free(script);
}


/************************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:none
************************************************************************************************************/
G_MODULE_EXPORT void cb_Parallel_function2_for_editor(GtkWidget *widget, gpointer data)
{

  gchar *script;
  g_free(script);
  
  script=g_strconcat("workers()\n",NULL);
  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],script);
  g_free(script);
}


