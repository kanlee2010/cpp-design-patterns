#include <iostream>
#include "abstract_factory.h"

void WinButton::click(void)
{
	std::cout << "WinButton::click\n";
}

const char* WinTextArea::getText(void)
{
	return "WinTextArea::getText";
}

void LinuxButton::click(void)
{
	std::cout << "LinuxButton::click\n";
}

const char* LinuxTextArea::getText(void)
{
	return "LinuxTextArea::getText";
}

Button* WinGuiFactory::createButton(void)
{
	return new WinButton;
}

TextArea* WinGuiFactory::createTextArea(void)
{
	return new WinTextArea;
}

Button* LinuxGuiFactory::createButton(void)
{
	return new LinuxButton;
}

TextArea* LinuxGuiFactory::createTextArea(void)
{
	return new LinuxTextArea;
}

GuiFactory* abstract_factory::getInstance(void)
{
	return new WinGuiFactory;
}

void abstract_factory_client(void)
{
	GuiFactory *factory = abstract_factory::getInstance();
	Button *button = factory->createButton();
	TextArea *textArea = factory->createTextArea();

	button->click();
	std::cout << textArea->getText() << std::endl;
}