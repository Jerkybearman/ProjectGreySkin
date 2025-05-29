// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FMapShapeSettings
{
    GENERATED_BODY()

    // 맵 그리드 열 개수
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    int32 GridColumns;

    // 맵 그리드 행 개수
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    int32 GridRows;

    // 셀 간격 (X, Y)
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    FVector2D CellSpacing;

    // 그리드 원점 위치
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    FVector GridOrigin;

    FMapShapeSettings()
        : GridColumns(7)
        , GridRows(15)
        , CellSpacing(200.f, 200.f)
        , GridOrigin(FVector::ZeroVector)
    {
    }
};

USTRUCT(BlueprintType)
struct FMapGenerationRules
{
    GENERATED_BODY()

    // 랜덤 시드 (0이면 런타임에 새로 생성)
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    int32 Seed;

    // 최소/최대 노드 개수
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    int32 MinNodesPerRow;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    int32 MaxNodesPerRow;

    // 연결 가능한 컬럼 차이
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    int32 MaxConnectionColumnDifference;

    // 기본 최대 비용
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    float DefaultMaxCost;

    // 추가 분기 허용 여부 및 개수
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    bool bAllowExtraBranches;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    int32 ExtraBranchCount;

    FMapGenerationRules()
        : Seed(0)
        , MinNodesPerRow(2)
        , MaxNodesPerRow(4)
        , MaxConnectionColumnDifference(1)
        , DefaultMaxCost(99999.f)
        , bAllowExtraBranches(true)
        , ExtraBranchCount(2)
    {
    }
};

USTRUCT(BlueprintType)
struct FMapGenerationRules
{
    GENERATED_BODY()

    // 랜덤 시드 (0이면 런타임에 새로 생성)
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    int32 Seed;

    // 최소/최대 노드 개수
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    int32 MinNodesPerRow;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    int32 MaxNodesPerRow;

    // 연결 가능한 컬럼 차이
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    int32 MaxConnectionColumnDifference;

    // 기본 최대 비용
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    float DefaultMaxCost;

    // 추가 분기 허용 여부 및 개수
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    bool bAllowExtraBranches;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    int32 ExtraBranchCount;

    FMapGenerationRules()
        : Seed(0)
        , MinNodesPerRow(2)
        , MaxNodesPerRow(4)
        , MaxConnectionColumnDifference(1)
        , DefaultMaxCost(99999.f)
        , bAllowExtraBranches(true)
        , ExtraBranchCount(2)
    {
    }
};

USTRUCT(BlueprintType)
struct FVisualizationSettings
{
    GENERATED_BODY()

    // 디버그 라인 표시
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    bool bShowDebugLines;

    // 라인 재질
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    UMaterialInterface* LineMaterial;

    // 라인 두께
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    float LineThickness;

    // 노드 정보 위젯 클래스
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapConfig")
    TSubclassOf<UUserWidget> NodeInfoWidgetClass;

    FVisualizationSettings()
        : bShowDebugLines(false)
        , LineMaterial(nullptr)
        , LineThickness(5.f)
        , NodeInfoWidgetClass(nullptr)
    {
    }
};

UCLASS()
class PROCEDURALMAPMAKER_API UUDataAsset : public UDataAsset
{
	GENERATED_BODY()
public: 
	// 맵 형태 설정
/** 맵 그리드 열, 행, 셀 간격 등을 정의 */
UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MapConfig")
FMapShapeSettings MapShapeSettings;

// 맵 생성 규칙
/** 시드, 노드 개수, 추가 분기 여부 등을 정의 */
UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MapConfig")
FMapGenerationRules MapGenerationRules;

// 노드 액터 설정
/** 생성할 노드 액터 클래스 참조 */
UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MapConfig")
FNodeActorSettings NodeActorSettings;

// 시각화 설정
/** 디버그 라인 표시 여부, 재질, 두께, 위젯 클래스 */
UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MapConfig")
FVisualizationSettings VisualizationSettings;
};
};
