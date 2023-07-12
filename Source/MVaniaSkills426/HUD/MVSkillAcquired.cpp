// Fill out your copyright notice in the Description page of Project Settings.


#include "MVSkillAcquired.h"
#include "Widgets/Layout/Anchors.h"
#include "Layout/Margin.h"
#include "Components/SlateWrapperTypes.h"

void UMVSkillAcquired::NativeOnInitialized()
{
/*
	BackgroundBlur->SetAnchorsInViewport(FAnchors(0.f, 0.f, 1.f, 1.f));
	BackgroundBlur->BlurStrength = 5.0f;
	BackgroundBlurSlot->SetPadding(FMargin(0.f, 0.f, 0.f, 0.f));
	 
	Skill->SetAnchorsInViewport(FAnchors(0.f, 0.f, 1.f, 0.f));
	Skill->Visibility = ESlateVisibility::Visible;
*/
	Skill_BG_Image = NewObject<UImage>(this);
	Skill_BG_Image->SetColorAndOpacity(FLinearColor(0.15f, 0.15f, 0.f, 1.f));
	Skill_BG_Image->SetVisibility(ESlateVisibility::Visible);
/*
	if (UPanelWidget* ParentContainer = Cast<UPanelWidget>(GetRootWidget()))
	{
		ParentContainer->AddChild(Skill_BG_Image);
	}
	Skill_BG_Image->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
	Skill_BG_Image->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);


*/
}

/*
3 Tint 0.15 0.15 0 1
2 HAlign_Fill VAlign_Fill
1 UImage Skill_BG_Image

5 Tilling Both Both
4 Image Size 500 500 (X=500.000000,Y=500.000000)
3 M_SkillAcquired_Title
2 Bottom 15
1 Image Skill_FG_Image under Skill_Overlay
1.33 HAlign_Fill VAlign_Fill
1.66 Top 15

4 Top 20
3 HAlign_Center VAlign_Center
2 Skill_Learned_Box
1 HorizontalBox

4 Padding Bottom 50
3 Image size 200 200
2.5 Image T_Icon_DoubleJump
2 Skill_Icon_Left
1 Image under Skill_Learned_Box

10 ShadowColor A 1.0 (R=0.000000,G=0.000000,B=0.000000,A=1.000000)
9 ShadowOffset 5 5 (X=5.000000,Y=5.000000)
8 Outline Settings Outline Size 6
7 Font Size 92
6.5 Font Family FT_Gothic_Letters_Font Font'/Game/Fonts/FT_Gothic_Letters_Font.FT_Gothic_Letters_Font'
6 Color and Opacity 0.15 .15 0.0 1.0 (SpecifiedColor=(R=0.150000,G=0.150000,B=0.000000,A=1.000000),ColorUseRule=UseColor_Specified)
5 Left 80 Right 40 (Left=80.000000,Top=0.000000,Right=40.000000,Bottom=0.000000)
4 VAlign_Center
3 Text NSLOCTEXT("[56DBC8A44464235C3FA33EB4EB521FE8]", "C83DC1FC4B62B36F908F058AE147F8CE", "Learned Double Jump!")
2 Skill_Learned_Text
1 Text under Skill_Learned_Box

2 Skill_Icon_Right
1 Duplicate Skill_Icon_Left
*/