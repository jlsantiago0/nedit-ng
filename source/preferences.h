/*******************************************************************************
*                                                                              *
* preference.h -- Nirvana Editor Preferences Header File                       *
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

#ifndef PREFERENCES_H_
#define PREFERENCES_H_

#include "nedit.h"
#include "string_view.h"
#include "nullable_string.h"
#include <exception>

class XString;


class invalid_character_error : public std::exception {
public:
	virtual const char *what() const noexcept {
		return "invalid_character_error";
	}
};



#include <X11/Intrinsic.h>
#include <X11/Xresource.h>
#include <Xm/Xm.h>
#include <X11/Xlib.h>

#define PLAIN_LANGUAGE_MODE -1

/* maximum number of language modes allowed */
#define MAX_LANGUAGE_MODES 127

#define MAX_TITLE_FORMAT_LEN 50

/* Identifiers for individual fonts in the help fonts list */
enum helpFonts {
	HELP_FONT,
	BOLD_HELP_FONT,
	ITALIC_HELP_FONT,
	BOLD_ITALIC_HELP_FONT,
	FIXED_HELP_FONT,
	BOLD_FIXED_HELP_FONT,
	ITALIC_FIXED_HELP_FONT,
	BOLD_ITALIC_FIXED_HELP_FONT,
	HELP_LINK_FONT,
	H1_HELP_FONT,
	H2_HELP_FONT,
	H3_HELP_FONT,
	NUM_HELP_FONTS
};

Boolean GetPrefFocusOnRaise(void);
Boolean GetPrefForceOSConversion(void);
Boolean GetPrefHighlightSyntax(void);
Boolean GetPrefHonorSymlinks(void);
Boolean GetPrefUndoModifiesSelection(void);
char *EscapeSensitiveChars(const char *string);
char *GetPrefBacklightCharTypes(void);
char *GetPrefBGMenuBtn(void);
char *GetPrefBoldFontName(void);
char *GetPrefBoldItalicFontName(void);
char *GetPrefColorName(int colorIndex);
char *GetPrefDelimiters(void);
char *GetPrefFontName(void);
char *GetPrefGeometry(void);
char *GetPrefHelpFontName(int index);
char *GetPrefHelpLinkColor(void);
char *GetPrefItalicFontName(void);
char *GetPrefServerName(void);
char *GetPrefTagFile(void);
char *GetPrefTooltipBgColor(void);
char *GetWindowDelimiters(const Document *window);
char *LanguageModeName(int mode);
char *ReadSymbolicField(const char **inPtr);
char *ReadSymbolicFieldTextWidget(Widget textW, const char *fieldName, int silent);
const char *GetPrefShell(void);
const char *GetPrefTitleFormat(void);
int AllocatedStringsDiffer(const char *s1, const char *s2);
int CheckPrefsChangesSaved(Widget dialogParent);
int FindLanguageMode(const char *languageName);
int GetPrefAlwaysCheckRelTagsSpecs(void);
int GetPrefAppendLF(void);
int GetPrefAutoIndent(int langMode);
int GetPrefAutoSave(void);
int GetPrefAutoScroll(void);
int GetPrefBacklightChars(void);
int GetPrefBeepOnSearchWrap(void);
int GetPrefCols(void);
int GetPrefEmTabDist(int langMode);
int GetPrefFindReplaceUsesSelection(void);
int GetPrefGlobalTabNavigate(void);
int GetPrefInsertTabs(void);
int GetPrefISearchLine(void);
int GetPrefKeepSearchDlogs(void);
int GetPrefLineNums(void);
int GetPrefMapDelete(void);
int GetPrefMatchSyntaxBased(void);
int GetPrefMaxPrevOpenFiles(void);
int GetPrefOpenInTab(void);
int GetPrefOverrideVirtKeyBindings(void);
int GetPrefRepositionDialogs(void);
int GetPrefRows(void);
int GetPrefSaveOldVersion(void);
int GetPrefSearchDlogs(void);
int GetPrefSearch(void);
int GetPrefSearchWraps(void);
int GetPrefShowMatching(void);
int GetPrefShowPathInWindowsMenu(void);
int GetPrefSmartTags(void);
int GetPrefSortOpenPrevMenu(void);
int GetPrefSortTabs(void);
int GetPrefStatsLine(void);
int GetPrefStdOpenDialog(void);
int GetPrefStickyCaseSenseBtn(void);
int GetPrefTabBarHideOne(void);
int GetPrefTabBar(void);
int GetPrefTabDist(int langMode);
int GetPrefToolTips(void);
int GetPrefTruncSubstitution(void);
int GetPrefTypingHidesPointer(void);
int GetPrefWarnExit(void);
int GetPrefWarnFileMods(void);
int GetPrefWarnRealFileMods(void);
int GetPrefWrap(int langMode);
int GetPrefWrapMargin(void);
int GetVerticalAutoScroll(void);
int ParseError(Widget toDialog, const char *stringStart, const char *stoppedAt, const char *errorIn, const char *message);
int ReadNumericField(const char **inPtr, int *value);
int ReadQuotedString(const char **inPtr, const char **errMsg, char **string);
int ReadQuotedStringEx(const char **inPtr, const char **errMsg, XString *string);
int SkipDelimiter(const char **inPtr, const char **errMsg);
int SkipOptSeparator(char separator, const char **inPtr);
std::string EscapeSensitiveCharsEx(view::string_view string);
std::string MakeQuotedStringEx(view::string_view string);
nullable_string ReadSymbolicFieldEx(const char **inPtr);
nullable_string ReadSymbolicFieldTextWidgetEx(Widget textW, const char *fieldName, int silent);
void ChooseColors(Document *window);
void ChooseFonts(Document *window, int forWindow);
void CreateLanguageModeSubMenu(Document *window, const Widget parent, const char *name, const char *label, const char mnemonic);
void DetermineLanguageMode(Document *window, int forceNewDefaults);
void EditLanguageModes(void);
void ImportPrefFile(const char *filename, int convertOld);
void MarkPrefsChanged(void);
void RestoreNEditPrefs(XrmDatabase prefDB, XrmDatabase appDB);
void RowColumnPrefDialog(Widget parent);
void SaveNEditPrefs(Widget parent, int quietly);
void SelectShellDialog(Widget parent, Document *forWindow);
void SetLangModeMenu(Widget optMenu, const char *modeName);
void SetLanguageMode(Document *window, int mode, int forceNewDefaults);
void SetPrefAppendLF(int state);
void SetPrefAutoIndent(int state);
void SetPrefAutoSave(int state);
void SetPrefAutoScroll(int state);
void SetPrefBacklightChars(int state);
void SetPrefBeepOnSearchWrap(int state);
void SetPrefBoldFont(char *fontName);
void SetPrefBoldItalicFont(char *fontName);
void SetPrefColorName(int colorIndex, const char *color);
void SetPrefCols(int nCols);
void SetPrefEmTabDist(int tabDist);
void SetPrefFindReplaceUsesSelection(int state);
void SetPrefFocusOnRaise(Boolean);
void SetPrefFont(char *fontName);
void SetPrefGlobalTabNavigate(int state);
void SetPrefHighlightSyntax(Boolean state);
void SetPrefInsertTabs(int state);
void SetPrefISearchLine(int state);
void SetPrefItalicFont(char *fontName);
void SetPrefKeepSearchDlogs(int state);
void SetPrefLineNums(int state);
void SetPrefMatchSyntaxBased(int state);
void SetPrefOpenInTab(int state);
void SetPrefRepositionDialogs(int state);
void SetPrefRows(int nRows);
void SetPrefSaveOldVersion(int state);
void SetPrefSearchDlogs(int state);
void SetPrefSearch(int searchType);
void SetPrefSearchWraps(int state);
void SetPrefShell(const char *shell);
void SetPrefShowMatching(int state);
void SetPrefShowPathInWindowsMenu(int state);
void SetPrefSmartTags(int state);
void SetPrefSortOpenPrevMenu(int state);
void SetPrefSortTabs(int state);
void SetPrefStatsLine(int state);
void SetPrefTabBarHideOne(int state);
void SetPrefTabBar(int state);
void SetPrefTabDist(int tabDist);
void SetPrefTitleFormat(const char *format);
void SetPrefToolTips(int state);
void SetPrefUndoModifiesSelection(Boolean);
void SetPrefWarnExit(int state);
void SetPrefWarnFileMods(int state);
void SetPrefWarnRealFileMods(int state);
void SetPrefWrap(int state);
void SetPrefWrapMargin(int margin);
void TabsPrefDialog(Widget parent, Document *forWindow);
void UnloadLanguageModeTipsFile(Document *window);
void WrapMarginDialog(Widget parent, Document *forWindow);
Widget CreateLanguageModeMenu(Widget parent, XtCallbackProc cbProc, void *cbArg);
XFontStruct *GetPrefBoldFont(void);
XFontStruct *GetPrefBoldItalicFont(void);
XFontStruct *GetPrefItalicFont(void);
XmFontList GetPrefFontList(void);
XrmDatabase CreateNEditPrefDB(int *argcInOut, char **argvInOut);

#ifdef REPLACE_SCOPE
void SetPrefReplaceDefScope(int scope);
int GetPrefReplaceDefScope(void);
#endif

#endif
