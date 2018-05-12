#pragma once
#include "Hero.h"
#include "GameState.h"

void Hero::scanAD_F(){
    AD_FromEquipment=0;
    for(GameState::ItemState &equ : package){
        //将装备栏中的装备属性累加
        AD_FromEquipment+=equ.AD;
    }

    //TODO: 计算Buff带来的影响

    
}

void Hero::scanArmor(){
    Armor=0;
    for(GameState::ItemState &equ:package){
        Armor+=equ.Armor;
    }

    //TODO: 计算Buff带来的影响

    
}

void Hero::scanAD_Break(){
    AD_Break=0;
    for(GameState::ItemState &equ:package){
        AD_Break*=((float)1+equ.AD_Break);
    }
}
bool Hero::doingAttack(){
    scanAD_F();
    scanArmor();
    scanAD_Break();
    //TODO: 触发人物攻击特效

    for(GameState::ItemState &equ:package){
        if(equ.doingAttack()){
            return true;
        }
    }
    
    //TODO: 触发Buff特效

    return false;
}

bool Hero::beingAttack(){
    scanAD_F();
    scanArmor();
    scanAD_Break();
    //TODO: 触发人物攻击特效

    for(GameState::ItemState &equ:package){
        if(equ.beingAttack()){
            return true;
        }
    }
    
    //TODO: 触发Buff特效

    return false;
}