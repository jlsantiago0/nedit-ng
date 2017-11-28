
#ifndef DIALOG_SHELL_MENU_H_
#define DIALOG_SHELL_MENU_H_

#include "Dialog.h"
#include "ui_DialogShellMenu.h"

#include <memory>

struct MenuItem;

class DialogShellMenu : public Dialog {
	Q_OBJECT

private:
    enum class Mode {
        Silent,
        Verbose
    };

public:
    DialogShellMenu(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~DialogShellMenu() noexcept override;

private Q_SLOTS:
	void on_buttonNew_clicked();
	void on_buttonCopy_clicked();
	void on_buttonDelete_clicked();
	void on_buttonUp_clicked();
	void on_buttonDown_clicked();
	void on_listItems_itemSelectionChanged();
	void on_buttonBox_clicked(QAbstractButton *button);
	void on_buttonBox_accepted();
	void on_radioToSameDocument_toggled(bool checked);
	
private:
    bool checkCurrent(Mode mode);
    std::unique_ptr<MenuItem> readDialogFields(Mode mode);
	QString ensureNewline(const QString &string);
	bool applyDialogChanges();
	void updateButtons();
	MenuItem *itemFromIndex(int i) const;
	bool updateCurrentItem();
	bool updateCurrentItem(QListWidgetItem *item);		
	
private:
	Ui::DialogShellMenu ui;
	QListWidgetItem *previous_;
};

#endif

