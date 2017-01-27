/*******************************************************************************
*                                                                              *
* shell.h -- Nirvana Editor Shell Header File                                  *
*                                                                              *
* Copyright 2004 The NEdit Developers                                          *
*                                                                              *
* This is free software; you can redistribute it and/or modify it under the    *
* terms of the GNU General Public License as published by the Free Software    *
* Foundation; either version 2 of the License, or (at your option) any later   *
* version. In addition, you may distribute versions of this program linked to  *
* Motif or Open Motif. See README for details.                                 *
*                                                                              *
* This software is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for    *
* more details.                                                                *
*                                                                              *
* You should have received a copy of the GNU General Public License along with *
* software; if not, write to the Free Software Foundation, Inc., 59 Temple     *
* Place, Suite 330, Boston, MA  02111-1307 USA                                 *
*                                                                              *
* Nirvana Text Editor                                                          *
* July 31, 2001                                                                *
*                                                                              *
*******************************************************************************/

#ifndef SHELL_H_
#define SHELL_H_

#include "MenuItem.h"
#include <string>
class Document;
class DocumentWidget;
class TextArea;
class MainWindow;

void FilterSelection(Document *window, const std::string &command, int fromMacro);
void ExecShellCommand(Document *window, const std::string &command, int fromMacro);
void ExecCursorLine(Document *window, int fromMacro);
void ShellCmdToMacroString(Document *window, const std::string &command, const std::string &input);
void DoShellMenuCmd(Document *window, const std::string &command, InSrcs input, OutDests output, int outputReplaceInput, int saveFirst, int loadAfter, int fromMacro);
void AbortShellCommand(Document *window);
void AbortShellCommandEx(DocumentWidget *document);

#endif
