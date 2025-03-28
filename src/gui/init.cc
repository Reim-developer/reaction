#include "init.hpp"
#include "include/buttons.hpp"
#include "include/dropbox.hpp"
#include "include/label.hpp"

using namespace Reaction::Gui;
void InitUI::setup(MainWindow *window, Signal *signal, State *state, Context *context) {
    GuiLabel *guiLabel = new GuiLabel();
    QLabel *deviceSelect = guiLabel->setLabel(window, "Device Selection:", 10, 30, 100, 30);
    QLabel *bootFileSelect = guiLabel->setLabel(window, "Boot File Selection:", 10, 100, 100, 30);
    QLabel *partitionSelect = guiLabel->setLabel(window, "Partition Selection", 10, 170, 100, 30);

    GuiLabelUtils *guiLabelUtils = new GuiLabelUtils();
    guiLabelUtils->setLabelFixedSize(deviceSelect, 12);
    guiLabelUtils->setLabelFixedSize(bootFileSelect, 12);
    guiLabelUtils->setLabelFixedSize(partitionSelect, 12);

    GuiDropbox *guiDropbox = new GuiDropbox();
    QComboBox *deviceList = guiDropbox->setComboBox(window, "No device found", 10, 60, 150, 30);
    static_cast<Gui::GuiDropboxStyle*>(deviceList)->setTransparent(true);

    QComboBox *bootSelctionList = guiDropbox->setComboBox(window, "No boot file", 10, 130, 150, 30);
    static_cast<Gui::GuiDropboxStyle*>(bootSelctionList)->setTransparent(true);

    vector<QString> partitionSelectionList = {"MBR", "GPT"};
    QComboBox *selectPartition = guiDropbox->setMultiComboBox(window, partitionSelectionList, 10, 200,  150, 30);
    static_cast<Gui::GuiDropboxStyle*>(selectPartition)->setTransparent(true);

    GuiButtons *guiButtons = new GuiButtons();
    guiButtons->setButtons(window, "Device not found? Reload", 300, 60, 200, 30);
    guiButtons->setButtons(window, "Choose device manually",530, 60, 200, 30);

    QPushButton *openBootFileButton  = guiButtons->setButtons(window, "Choose boot file", 300, 130, 200, 30);

    context->setOpenFileContext(openBootFileButton, signal, window, bootSelctionList, state);
}
