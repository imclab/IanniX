#ifndef UITEXTUREITEM_H
#define UITEXTUREITEM_H

#include "misc/applicationexecute.h"
#include "uitreeview.h"
#include "misc/options.h"
#include "iannix_cmd.h"

class UiTextureItem : public UiSyncItem {
public:
    explicit UiTextureItem(UiSyncList *_baseList, UiSyncItem *_parent = 0);

public:
    QString name;
    UiRenderTexture *texture;
private:
    UiSyncList *baseList;
protected:
    QVariant data(int column, int role) const;
    void setData(int column, int role, const QVariant &value);

protected:
    void dataChanged() { emitDataChanged(); }
};



class UiTextureItems : public QMap<QString, UiRenderTexture*>, public UiSyncItem, public UiSyncList {
public:
    explicit UiTextureItems(UiSyncItem *_parent = 0);
private:
    UiTextureItem* generateItem(UiSyncItem *otherItem, bool doInsert = true, bool fromGui = true);
    UiTextureItem* generateItem(const QString &name, UiRenderTexture *texture, bool insert = true, bool fromGui = true);

public:
    void configure(const QString &name, UiTreeView *);
    void update();
protected:
    bool askForImport(UiSyncItem *, const QFileInfoList &list);
    bool askForDeletion(UiSyncItem *i, bool);
    bool askForPaste(UiSyncItem *i, const QList<UiSyncItem *> &list);
protected:
    UiRenderTexture *setValue(const QString &key, UiRenderTexture *valeur);
    const QString renameKey(const QString &oldKey, const QString &newKey);
protected:
    void dataChanged();
};

#endif // UITEXTUREITEM_H
