#include <gtk/gtk.h>
#include <string.h>
#include <unistd.h>

gboolean update_loading_text(gpointer data) {
    static int dot_count = 0;
    GtkWidget *label = GTK_WIDGET(data);
    const char *custom_text = (const char *)g_object_get_data(G_OBJECT(label), "custom_text");
    char loading_text[50];
    snprintf(loading_text, sizeof(loading_text), "<span font_desc='25'>%s%s</span>", custom_text, "...."+4-dot_count);
    gtk_label_set_markup(GTK_LABEL(label), loading_text);
    dot_count = (dot_count + 1) % 4;
    return G_SOURCE_CONTINUE;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "loading window");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 100);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
    GtkWidget *label = gtk_label_new(NULL);
    gtk_label_set_xalign(GTK_LABEL(label), 0.5);
    gtk_label_set_yalign(GTK_LABEL(label), 0.5);
    gtk_container_add(GTK_CONTAINER(window), label);
    const char *custom_text = "Sending";
    if (argc > 1) {
        custom_text = argv[1];
    }
    g_object_set_data(G_OBJECT(label), "custom_text", (gpointer)custom_text);
    guint timer_id = g_timeout_add(100, update_loading_text, label);
    gtk_widget_show_all(window);
    gtk_main();
    g_source_remove(timer_id);
    return 0;
}
