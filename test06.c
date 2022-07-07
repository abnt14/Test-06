#include <stdio.h>
#include <gtk/gtk.h>
#include <glib/gstdio.h>

//Declaracão variáveis globais
GtkWidget *janela;
GtkApplication *app;
gpointer user_data;
GtkBuilder *builder;

void ativaUI(){
	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder,"test06.ui", NULL);	
}

void fechaJanela(GtkWindow *janela){
	gtk_window_close(janela);
}

void criaJanela(){
	ativaUI();
	GObject *janela = gtk_builder_get_object(builder, "janela");
	gtk_window_set_application(GTK_WINDOW(janela), app);
	
	GObject *inserirTexto = gtk_builder_get_object(builder, "isrTexto");
	GObject *scrol = gtk_builder_get_object(builder, "scrol");
	
	GObject *botao01 = gtk_builder_get_object(builder, "botao01");
	g_signal_connect_swapped(botao01, "clicked", G_CALLBACK(fechaJanela), janela);
	
	gtk_widget_show(GTK_WIDGET(janela));
	g_object_unref(builder);
}

int main(int argc, char **argv){
	int status;

	app = gtk_application_new("test06.desktop", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(criaJanela), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}
