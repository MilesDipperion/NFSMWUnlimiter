#include "stdio.h"
#include "InGameFunctions.h"

int __fastcall FEShoppingCartItem_GetCarPartCatHash(DWORD* _this, int EDX_Unused, int CarSlotID)
{
    int result;

    switch (CarSlotID)
    {
    case 0:
        result = bStringHash("CO_ROOF");
        break;
    case 23:
        result = bStringHash("CO_BODY_KITS");
        break;
    case 24:
        result = bStringHash("CO_BRAKES");
        break;
    case 28:
        result = bStringHash("CO_INTERIOR");
        break;
    case 29:
        result = bStringHash("CO_TAILLIGHTS");
        break;
    case 31:
        result = bStringHash("CO_HEADLIGHTS");
        break;
    case 33:
        result = bStringHash("CO_SIDE_MIRROR");
        break;
    case 43:
        result = bStringHash("CO_DRIVER");
        break;
    case 44:
        result = bStringHash("CO_SPOILERS");
        break;
    case 52:
        result = bStringHash("CO_ATTACHMENT_1");
        break;
    case 53:
        result = bStringHash("CO_ATTACHMENT_2");
        break;
    case 54:
        result = bStringHash("CO_ATTACHMENT_3");
        break;
    case 55:
        result = bStringHash("CO_ATTACHMENT_4");
        break;
    case 56:
        result = bStringHash("CO_ATTACHMENT_5");
        break;
    case 57:
        result = bStringHash("CO_ATTACHMENT_6");
        break;
    case 58:
        result = bStringHash("CO_ATTACHMENT_7");
        break;
    case 59:
        result = bStringHash("CO_ATTACHMENT_8");
        break;
    case 60:
        result = bStringHash("CO_ATTACHMENT_9");
        break;
    case 61:
        result = bStringHash("CO_ATTACHMENT_10");
        break;
    case 62:
        result = bStringHash("CO_ROOF_SCOOPS");
        break;
    case 63:
        result = bStringHash("CO_HOODS");
        break;
    case 64: // HEADLIGHT
        result = bStringHash("CO_TIRES");
        break;
    case 66:
        result = bStringHash("CO_RIMS");
        break;
    case 69:
        result = bStringHash("CO_LICENSE_PLATE");
        break;
    case 76:
        result = bStringHash("CO_PAINT");
        break;
    case 77:
        result = bStringHash("CO_VINYLS");
        break;
    case 78:
        result = bStringHash("CO_RIM_PAINT");
        break;
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
        result = bStringHash("CO_DECAL_WINDSHIELD");
        break;
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
        result = bStringHash("CO_DECAL_REAR_WINDOW");
        break;
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
        result = bStringHash("CO_DECAL_LEFT_DOOR");
        break;
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
        result = bStringHash("CO_DECAL_RIGHT_DOOR");
        break;
    case 113:
        result = bStringHash("CO_NUMBERS");
        break;
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 122:
        result = bStringHash("CO_DECAL_LEFT_QUARTER");
        break;
    case 123:
    case 124:
    case 125:
    case 126:
    case 127:
    case 128:
    case 129:
    case 130:
        result = bStringHash("CO_DECAL_RIGHT_QUARTER");
        break;
    case 131:
        result = bStringHash("CO_WINDOW_TINT");
        break;
    case 132:
        result = bStringHash("CO_CUSTOM_HUD");
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

void __fastcall FEShoppingCartItem_DrawPartName(DWORD* FEShoppingCartItem)
{
    int SelectablePart; // esi
    int PerformancePartType; // ebx
    int PerformancePartMaxLevel; // esi
    int PerformancePartLevel; // esi
    const char* PartMaterialName; // eax MAPDST
    DWORD PaintTypeNameHash; // ebp
    DWORD PaintBrandNameHash; // eax
    DWORD SpeechColourNameHash; // eax MAPDST
    int RightDoorNumberLeft; // ebx
    int RightDoorNumberRight; // eax
    DWORD* RightDoorNumberLeftPart; // ebp
    DWORD* RightDoorNumberRightPart; // ebx
    DWORD DecalSlotNameHash; // ebx
    const char* Decals; // eax MAPDST
    int PartNameBufLen; // eax
    DWORD* CartItemName; // ebx MAPDST
    DWORD CarSlotID; // esi MAPDST
    DWORD PartCategoryNameHash; // eax MAPDST
    const char* PartCategoryName; // eax MAPDST
    DWORD* ThePartInCart; // ebx MAPDST
    int CurrLanguage; // eax MAPDST
    DWORD PartNameHash; // eax MAPDST
    const char* PaintTypeName; // [esp-8h] [ebp-5Ch] MAPDST
    const char* LeftNumberName; // [esp-8h] [ebp-5Ch] MAPDST
    const char* DecalSlotName; // [esp-8h] [ebp-5Ch] MAPDST
    const char* Junkman; // [esp-4h] [ebp-58h] MAPDST
    const char* PartName; // [esp-4h] [ebp-58h] MAPDST
    const char* SpeechColourName; // [esp-4h] [ebp-58h] MAPDST
    const char* RightNumberName; // [esp-4h] [ebp-58h] MAPDST
    DWORD StockHash; // [esp-4h] [ebp-58h]
    const char* RemoveDecal; // [esp-4h] [ebp-58h] MAPDST
    int InnerRadius; // [esp-4h] [ebp-58h] MAPDST
    char PartNameBuf[64]; // [esp+14h] [ebp-40h] BYREF

    SelectablePart = *(DWORD*)(*((DWORD*)FEShoppingCartItem + 21) + 12);
    if (!*(BYTE*)(SelectablePart + 28))
    {
        switch (*(DWORD*)(SelectablePart + 16))
        {
        case 44:
        case 62:
        case 63:
            ThePartInCart = *(DWORD**)(SelectablePart + 12);
            if (!CarPart_HasAppliedAttribute(ThePartInCart, bStringHash("CARBONFIBRE")))
                goto LABEL_68;
            ThePartInCart = *(DWORD**)(SelectablePart + 12);
            if (!CarPart_GetAppliedAttributeIParam(ThePartInCart, bStringHash("CARBONFIBRE"), 0))
                goto LABEL_68;
            CurrLanguage = GetCurrentLanguage();
            ThePartInCart = *(DWORD**)(SelectablePart + 12);
            CartItemName = *((DWORD**)FEShoppingCartItem + 11);
            CarSlotID = *(DWORD*)(SelectablePart + 16);
            if (CurrLanguage == 1)
            {
                PartNameHash = CarPart_GetAppliedAttributeUParam(ThePartInCart, bStringHash("LANGUAGEHASH"), 0);
                PartName = GetLocalizedString(PartNameHash);
                PartMaterialName = GetLocalizedString(0x5415B874);// CARBON
                goto LABEL_62;
            }
            PartNameHash = CarPart_GetAppliedAttributeUParam(ThePartInCart, bStringHash("LANGUAGEHASH"), 0);
            PartName = GetLocalizedString(PartNameHash);
            PartMaterialName = GetLocalizedString(0x5415B874);// CARBON
            goto LABEL_64;
        case 66:                                  // FRONT_WHEEL
            ThePartInCart = *(DWORD**)(SelectablePart + 12);
            if (ThePartInCart == CarCustomizeManager_GetStockCarPart((DWORD*)_gCarCustomizeManager, 66))
                goto LABEL_66;
            PartNameHash = CarPart_GetAppliedAttributeUParam(ThePartInCart, bStringHash("LANGUAGEHASH"), 0);
            if (PartNameHash) PartName = GetLocalizedString(PartNameHash);
            else PartName = CarPart_GetName(*(DWORD**)(SelectablePart + 12));
            bSNPrintf(PartNameBuf, 64, "%s", PartName);
            PartNameBufLen = strlen(PartNameBuf);
            if (PartNameBufLen > 0)
            {
                /*v84 = PartNameBufLen - 6;
                if (!__OFSUB__(PartNameBufLen, PartNameBufLen - 6))// Cut last 6 chars
                {
                    do
                        PartNameBuf[PartNameBufLen--] = 0;
                    while (PartNameBufLen >= v84);
                }*/
                CurrLanguage = GetCurrentLanguage();
                ThePartInCart = *(DWORD**)(SelectablePart + 12);
                CartItemName = *((DWORD**)FEShoppingCartItem + 11);
                CarSlotID = *(DWORD*)(SelectablePart + 16);
                if (CurrLanguage == 1)
                {
                    InnerRadius = (char)CarPart_GetAppliedAttributeIParam(ThePartInCart, 0xEB0101E2, 0);// INNER_RADIUS
                    PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                    PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                    FEPrintf_obj(CartItemName, "%s : %s %$d\"", PartCategoryName, PartNameBuf, InnerRadius);
                }
                else
                {
                    InnerRadius = (char)CarPart_GetAppliedAttributeIParam(ThePartInCart, 0xEB0101E2, 0);// INNER_RADIUS
                    PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                    PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                    FEPrintf_obj(CartItemName, "%s: %s %$d\"", PartCategoryName, PartNameBuf, InnerRadius);
                }
            }
            return;
        case 76:                                  // BASE_PAINT
            PaintTypeNameHash = 0x452B5481;         // CP_FILTER_METALLIC
            PaintBrandNameHash = CarPart_GetAppliedAttributeUParam(*(DWORD**)(SelectablePart + 12), 0xEBB03E66, 0);// BRAND_NAME
            if (PaintBrandNameHash > 0x3437A52)
            {
                if (PaintBrandNameHash == 0x3797533)
                    PaintTypeNameHash = 0xB715070A;
            }
            else
            {
                switch (PaintBrandNameHash)
                {
                case 0x3437A52:
                    PaintTypeNameHash = 0x452B5481;
                    break;
                case 0xDA27:
                    PaintTypeNameHash = 0xB3100A3E;
                    break;
                case 0x2DAAB07:
                    PaintTypeNameHash = 0xB6763CDE;
                    break;
                }
            }
            CurrLanguage = GetCurrentLanguage();
            ThePartInCart = *(DWORD**)(SelectablePart + 12);
            CarSlotID = *(DWORD*)(SelectablePart + 16);
            CartItemName = *((DWORD**)FEShoppingCartItem + 11);
            if (CurrLanguage == 1)
            {
                SpeechColourNameHash = CarPart_GetAppliedAttributeUParam(ThePartInCart, bStringHash("SPEECHCOLOUR"), 0);
                SpeechColourName = GetLocalizedString(SpeechColourNameHash);
                PaintTypeName = GetLocalizedString(PaintTypeNameHash);
                PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                FEPrintf_obj(CartItemName, "%s : %s %s", PartCategoryName, PaintTypeName, SpeechColourName);
            }
            else
            {
                SpeechColourNameHash = CarPart_GetAppliedAttributeUParam(ThePartInCart, bStringHash("SPEECHCOLOUR"), 0);
                SpeechColourName = GetLocalizedString(SpeechColourNameHash);
                PaintTypeName = GetLocalizedString(PaintTypeNameHash);
                PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                FEPrintf_obj(CartItemName, "%s: %s %s", PartCategoryName, PaintTypeName, SpeechColourName);
            }
            return;
        case 77:                                  // VINYL_LAYER0
            ThePartInCart = *(DWORD**)(SelectablePart + 12);
            if (ThePartInCart)
                goto LABEL_69;
        LABEL_66:
            CurrLanguage = GetCurrentLanguage();
            CartItemName = *((DWORD**)FEShoppingCartItem + 11);
            CarSlotID = *(DWORD*)(SelectablePart + 16);
            StockHash = 0x60A662F5;                 // CO_RETURN_TO_STOCK
            if (CurrLanguage != 1)
                goto LABEL_67;
            goto LABEL_33;
        case 78:                                  // PAINT_RIM
            CurrLanguage = GetCurrentLanguage();
            ThePartInCart = *(DWORD**)(SelectablePart + 12);
            CartItemName = *((DWORD**)FEShoppingCartItem + 11);
            CarSlotID = *(DWORD*)(SelectablePart + 16);
            if (CurrLanguage == 1)
            {
                SpeechColourNameHash = CarPart_GetAppliedAttributeUParam(ThePartInCart, bStringHash("SPEECHCOLOUR"), 0);
                PartName = GetLocalizedString(SpeechColourNameHash);
                PartMaterialName = GetLocalizedString(0xB3100A3E);// CP_FILTER_RIM
            LABEL_62:
                PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                FEPrintf_obj(CartItemName, "%s : %s %s", PartCategoryName, PartMaterialName, PartName);
            }
            else
            {
                SpeechColourNameHash = CarPart_GetAppliedAttributeUParam(ThePartInCart, bStringHash("SPEECHCOLOUR"), 0);
                PartName = GetLocalizedString(SpeechColourNameHash);
                PartMaterialName = GetLocalizedString(0xB3100A3E);
            LABEL_64:
                PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                FEPrintf_obj(CartItemName, "%s: %s %s", PartCategoryName, PartMaterialName, PartName);
            }
            return;
        case 83:                                  // DECALS (83-130)
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
        case 90:
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
        case 96:
        case 97:
        case 98:
        case 99:
        case 100:
        case 101:
        case 102:
        case 103:
        case 104:
        case 107:
        case 108:
        case 109:
        case 110:
        case 111:
        case 112:
        case 115:
        case 116:
        case 117:
        case 118:
        case 119:
        case 120:
        case 121:
        case 122:
        case 123:
        case 124:
        case 125:
        case 126:
        case 127:
        case 128:
        case 129:
        case 130:
            ThePartInCart = *(DWORD**)(SelectablePart + 12);
            if (ThePartInCart)
            {
                CarPart_GetAppliedAttributeUParam(ThePartInCart, 0xEBB03E66, 0);// BRAND_NAME
                ThePartInCart = *(DWORD**)(SelectablePart + 12);
                CarPart_GetAppliedAttributeUParam(ThePartInCart, bStringHash("NAME"), 0);
                switch (*(DWORD*)(SelectablePart + 16))
                {
                case 83:
                case 91:
                case 99:
                case 107:
                case 115:
                case 123:
                    DecalSlotNameHash = bStringHash("CO_DECAL_SLOT_1");
                    goto LABEL_45;
                case 84:
                case 92:
                case 100:
                case 108:
                case 116:
                case 124:
                    DecalSlotNameHash = bStringHash("CO_DECAL_SLOT_2");
                    goto LABEL_45;
                case 85:
                case 93:
                case 101:
                case 109:
                case 117:
                case 125:
                    DecalSlotNameHash = bStringHash("CO_DECAL_SLOT_3");
                    goto LABEL_45;
                case 86:
                case 94:
                case 102:
                case 110:
                case 118:
                case 126:
                    DecalSlotNameHash = bStringHash("CO_DECAL_SLOT_4");
                    goto LABEL_45;
                case 87:
                case 95:
                case 103:
                case 111:
                case 119:
                case 127:
                    DecalSlotNameHash = bStringHash("CO_DECAL_SLOT_5");
                    goto LABEL_45;
                case 88:
                case 96:
                case 104:
                case 112:
                case 120:
                case 128:
                    DecalSlotNameHash = bStringHash("CO_DECAL_SLOT_6");
                    goto LABEL_45;
                case 89:
                case 97:
                case 121:
                case 129:
                    DecalSlotNameHash = bStringHash("CO_DECAL_SLOT_7");
                    goto LABEL_45;
                case 90:
                case 98:
                case 122:
                case 130:
                    DecalSlotNameHash = bStringHash("CO_DECAL_SLOT_8");
                    //goto LABEL_45;
                LABEL_45:
                    CurrLanguage = GetCurrentLanguage();
                    ThePartInCart = *(DWORD**)(SelectablePart + 12);
                    CartItemName = *((DWORD**)FEShoppingCartItem + 11);
                    CarSlotID = *(DWORD*)(SelectablePart + 16);
                    if (CurrLanguage == 1)
                    {
                        PartName = CarPart_GetName(ThePartInCart);
                        DecalSlotName = GetLocalizedString(DecalSlotNameHash);
                        PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                        PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                        Decals = GetLocalizedString(0x955980BC);// CO_DECALS
                        FEPrintf_obj(CartItemName, "%s : %s %s %s", Decals, PartCategoryName, DecalSlotName, PartName);
                    }
                    else
                    {
                        PartName = CarPart_GetName(ThePartInCart);
                        DecalSlotName = GetLocalizedString(DecalSlotNameHash);
                        PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                        PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                        Decals = GetLocalizedString(0x955980BC);
                        FEPrintf_obj(CartItemName, "%s: %s %s %s", Decals, PartCategoryName, DecalSlotName, PartName);
                    }
                    break;
                default:
                    CurrLanguage = GetCurrentLanguage();
                    ThePartInCart = *(DWORD**)(SelectablePart + 12);
                    CartItemName = *((DWORD**)FEShoppingCartItem + 11);
                    CarSlotID = *(DWORD*)(SelectablePart + 16);
                    if (CurrLanguage == 1)
                    {
                        PartName = CarPart_GetName(ThePartInCart);
                        PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                        PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                        Decals = GetLocalizedString(0x955980BC);
                        FEPrintf_obj(CartItemName, "%s : %s %s", Decals, PartCategoryName, PartName);
                    }
                    else
                    {
                        PartName = CarPart_GetName(ThePartInCart);
                        PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                        PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                        Decals = GetLocalizedString(0x955980BC);
                        FEPrintf_obj(CartItemName, "%s: %s %s", Decals, PartCategoryName, PartName);
                    }
                    break;
                }
            }
            else
            {
                CurrLanguage = GetCurrentLanguage();
                CartItemName = *((DWORD**)FEShoppingCartItem + 11);
                CarSlotID = *(DWORD*)(SelectablePart + 16);
                if (CurrLanguage == 1)
                {
                    RemoveDecal = GetLocalizedString(0x7177DC17);
                    PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                    PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                    Decals = GetLocalizedString(0x955980BC);
                    FEPrintf_obj(CartItemName, "%s : %s - %s", Decals, PartCategoryName, RemoveDecal);
                }
                else
                {
                    RemoveDecal = GetLocalizedString(0x7177DC17);
                    PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                    PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                    Decals = GetLocalizedString(0x955980BC);
                    FEPrintf_obj(CartItemName, "%s: %s - %s", Decals, PartCategoryName, RemoveDecal);
                }
            }
            return;
        case 113:
            RightDoorNumberLeft = CarCustomizeManager_IsPartTypeInCart_ID((DWORD*)_gCarCustomizeManager, 113);
            RightDoorNumberRight = CarCustomizeManager_IsPartTypeInCart_ID((DWORD*)_gCarCustomizeManager, 114);
            if (!RightDoorNumberLeft || !RightDoorNumberRight)
                return;
            RightDoorNumberLeftPart = *(DWORD**)(*(DWORD*)(RightDoorNumberLeft + 12) + 12);
            RightDoorNumberRightPart = *(DWORD**)(*(DWORD*)(RightDoorNumberRight + 12) + 12);
            if (RightDoorNumberLeftPart && RightDoorNumberRightPart)
            {
                CurrLanguage = GetCurrentLanguage();
                CarSlotID = *(DWORD*)(SelectablePart + 16);
                CartItemName = *((DWORD**)FEShoppingCartItem + 11);
                if (CurrLanguage == 1)
                {
                    RightNumberName = CarPart_GetName(RightDoorNumberRightPart);
                    LeftNumberName = CarPart_GetName(RightDoorNumberLeftPart);
                    PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                    PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                    FEPrintf_obj(CartItemName, "%s : %s%s", PartCategoryName, LeftNumberName, RightNumberName);
                }
                else
                {
                    RightNumberName = CarPart_GetName(RightDoorNumberRightPart);
                    LeftNumberName = CarPart_GetName(RightDoorNumberLeftPart);
                    PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                    PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                    FEPrintf_obj(CartItemName, "%s: %s%s", PartCategoryName, LeftNumberName, RightNumberName);
                }
                return;
            }
            CurrLanguage = GetCurrentLanguage();
            CartItemName = *((DWORD**)FEShoppingCartItem + 11);
            CarSlotID = *(DWORD*)(SelectablePart + 16);
            StockHash = 0xBE434A38;                 // CN_REMOVE_NUMBERS
            if (CurrLanguage == 1)
            {
            LABEL_33:
                PartName = GetLocalizedString(StockHash);
                goto LABEL_76;
            }
        LABEL_67:
            PartName = GetLocalizedString(StockHash);
            goto LABEL_78;
        default:
        LABEL_68:
            ThePartInCart = *(DWORD**)(SelectablePart + 12);
        LABEL_69:
            if (!CarPart_HasAppliedAttribute(ThePartInCart, bStringHash("LANGUAGEHASH")))
            {
                CurrLanguage = GetCurrentLanguage();
                ThePartInCart = *(DWORD**)(SelectablePart + 12);
                CartItemName = *((DWORD**)FEShoppingCartItem + 11);
                CarSlotID = *(DWORD*)(SelectablePart + 16);
                if (CurrLanguage == 1)
                {
                    PartName = CarPart_GetName(ThePartInCart);
                LABEL_76:
                    PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                    PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                    FEPrintf_obj(CartItemName, "%s : %s", PartCategoryName, PartName);
                }
                else
                {
                    PartName = CarPart_GetName(ThePartInCart);
                LABEL_78:
                    PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                    PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                    FEPrintf_obj(CartItemName, "%s: %s", PartCategoryName, PartName);
                }
                return;
            }
            CurrLanguage = GetCurrentLanguage();
            ThePartInCart = *(DWORD**)(SelectablePart + 12);
            CartItemName = *((DWORD**)FEShoppingCartItem + 11);
            CarSlotID = *(DWORD*)(SelectablePart + 16);
            if (CurrLanguage == 1)
            {
                PartNameHash = CarPart_GetAppliedAttributeUParam(ThePartInCart, bStringHash("LANGUAGEHASH"), 0);
                PartName = GetLocalizedString(PartNameHash);
                PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
                PartCategoryName = GetLocalizedString(PartCategoryNameHash);
                FEPrintf_obj(CartItemName, "%s : %s", PartCategoryName, PartName);
                return;
            }
            PartNameHash = CarPart_GetAppliedAttributeUParam(ThePartInCart, bStringHash("LANGUAGEHASH"), 0);
            PartName = GetLocalizedString(PartNameHash);
            PartCategoryNameHash = FEShoppingCartItem_GetCarPartCatHash(FEShoppingCartItem, 0, CarSlotID);
            break;
        }
    PrintPartName:
        PartCategoryName = GetLocalizedString(PartCategoryNameHash);
        FEPrintf_obj(CartItemName, "%s: %s", PartCategoryName, PartName);
        return;
    }
    PerformancePartType = *(DWORD*)(SelectablePart + 24);
    PerformancePartMaxLevel = *(DWORD*)(SelectablePart + 20);
    if (PerformancePartMaxLevel != 7)
    {
        PerformancePartLevel = PerformancePartMaxLevel
            - Physics_Upgrades_GetMaxLevel((DWORD*)(_FECarRecord + 4), PerformancePartType)
            + 6;
        CurrLanguage = GetCurrentLanguage();
        CartItemName = *((DWORD**)FEShoppingCartItem + 11);
        if (CurrLanguage == 1)
        {
            PartNameHash = FEShoppingCartItem_GetPerfPkgLevelHash(FEShoppingCartItem, PerformancePartLevel);
            PartName = GetLocalizedString(PartNameHash);
            PartCategoryNameHash = FEShoppingCartItem_GetPerfPkgCatHash(FEShoppingCartItem, PerformancePartType);
            PartCategoryName = GetLocalizedString(PartCategoryNameHash);
            FEPrintf_obj(CartItemName, "%s : %s", PartCategoryName, PartName);
            return;
        }
        PartNameHash = FEShoppingCartItem_GetPerfPkgLevelHash(FEShoppingCartItem, PerformancePartLevel);
        PartName = GetLocalizedString(PartNameHash);
        PartCategoryNameHash = FEShoppingCartItem_GetPerfPkgCatHash(FEShoppingCartItem, PerformancePartType);
        goto PrintPartName;
    }
    CurrLanguage = GetCurrentLanguage();
    CartItemName = *((DWORD**)FEShoppingCartItem + 11);
    if (CurrLanguage == 1)
    {
        Junkman = GetLocalizedString(0xEDD14807);   // PN_LEVEL_JUNKMAN
        PartCategoryNameHash = FEShoppingCartItem_GetPerfPkgCatHash(FEShoppingCartItem, PerformancePartType);
        PartCategoryName = GetLocalizedString(PartCategoryNameHash);
        FEPrintf_obj(CartItemName, "%s : %s", PartCategoryName, Junkman);
    }
    else
    {
        Junkman = GetLocalizedString(0xEDD14807);   // PN_LEVEL_JUNKMAN
        PartCategoryNameHash = FEShoppingCartItem_GetPerfPkgCatHash(FEShoppingCartItem, PerformancePartType);
        PartCategoryName = GetLocalizedString(PartCategoryNameHash);
        FEPrintf_obj(CartItemName, "%s: %s", PartCategoryName, Junkman);
    }
}