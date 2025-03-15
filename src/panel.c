#include "panel.h"

panel_t *result_panel_widget_new(void) {
    panel_t *scroll_widget_t = g_new(panel_t, 1);
    scroll_widget_t->panel_area_t = gtk_scrolled_window_new();
    GtkWidget *text_view_t = gtk_text_view_new();

    GtkTextBuffer *text_buffer_t = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view_t));

    gtk_widget_set_hexpand(scroll_widget_t->panel_area_t, TRUE);
    gtk_widget_set_vexpand(scroll_widget_t->panel_area_t, TRUE);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll_widget_t->panel_area_t), text_view_t);
    gtk_text_buffer_set_text(text_buffer_t, DEFAULT_TEXT_CONTENT, -1);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view_t), FALSE);

    scroll_widget_t->width = 20;
    scroll_widget_t->height = 1;

    scroll_widget_t->grid_column = 15;
    scroll_widget_t->grid_row = 10;

    scroll_widget_t->grid_width = 20;
    scroll_widget_t->grid_height = 1;

    gtk_widget_set_size_request(scroll_widget_t->panel_area_t, scroll_widget_t->width, scroll_widget_t->height);
    return scroll_widget_t;
}

void result_text_append_new(panel_t *panel_text_view_t, const char *content) {
    GtkWidget *text_view_t = gtk_scrolled_window_get_child(
        GTK_SCROLLED_WINDOW(panel_text_view_t->panel_area_t)
    );
    GtkTextBuffer *text_buffer_t = gtk_text_view_get_buffer(
        GTK_TEXT_VIEW(text_view_t)
    );
    GtkTextIter text_iter_t;
    gtk_text_buffer_get_end_iter(text_buffer_t, &text_iter_t);

    char *content_append = g_strdup_printf("%s\n", content);
    gtk_text_buffer_insert(text_buffer_t, &text_iter_t, content_append, -1);

    g_free(content_append);
}

void result_text_clear_new(panel_t *paneL_text_view_t) {
    GtkWidget *text_view_t = gtk_scrolled_window_get_child(
        GTK_SCROLLED_WINDOW(paneL_text_view_t->panel_area_t)
    );
    GtkTextBuffer *text_buffer_t = gtk_text_view_get_buffer(
        GTK_TEXT_VIEW(text_view_t)
    );
    gtk_text_buffer_set_text(text_buffer_t, "", -1);
}

int is_default_text_view(panel_t *panel_text_view_t, const char *match) {
    GtkWidget *text_view_t = gtk_scrolled_window_get_child(
        GTK_SCROLLED_WINDOW(panel_text_view_t->panel_area_t)
    );
    GtkTextBuffer *text_buffer_t = gtk_text_view_get_buffer(
        GTK_TEXT_VIEW(text_view_t)
    );

    GtkTextIter start_t, end_t;
    gtk_text_buffer_get_start_iter(text_buffer_t, &start_t);
    gtk_text_buffer_get_end_iter(text_buffer_t, &end_t);
    gchar *current_text_t = gtk_text_buffer_get_text(text_buffer_t, &end_t, &start_t, FALSE);

    int text_view_status = (strcmp(current_text_t, match) == 0) ? IS_DEFAULT_TEXT_VIEW : IS_NOT_DEFAULT_TEXT_VIEW;
    g_free(current_text_t);

    return text_view_status;
}
