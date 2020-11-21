#pragma once

class Button {
public:
	virtual void click(void) = 0;
};

class TextArea {
public:
	virtual const char* getText(void) = 0;
};

class GuiFactory {
public:
	virtual Button* createButton(void) = 0;
	virtual TextArea* createTextArea(void) = 0;
};
class WinButton : public Button {
public:
	void click(void);
};

class WinTextArea : public TextArea {
public:
	const char* getText(void);
};

class WinGuiFactory : public GuiFactory {
public:
	Button* createButton(void);
	TextArea* createTextArea(void);
};

class LinuxButton : public Button {
public:
	void click(void);
};

class LinuxTextArea : public TextArea {
public:
	const char* getText(void);
};

class LinuxGuiFactory : public GuiFactory {
public:
	Button* createButton(void);
	TextArea* createTextArea(void);
};


class abstract_factory {
public:
	static GuiFactory* getInstance();
};