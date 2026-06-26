// === DECOMPILED C ===


/* WARNING: Removing unreachable block (ram,0x00237290) */
/* WARNING: Removing unreachable block (ram,0x00237264) */
/* WARNING: Removing unreachable block (ram,0x00237de4) */
/* WARNING: Removing unreachable block (ram,0x00237a14) */
/* WARNING: Removing unreachable block (ram,0x00237e10) */
/* WARNING: Removing unreachable block (ram,0x0023897c) */
/* WARNING: Removing unreachable block (ram,0x00238e2c) */
/* WARNING: Removing unreachable block (ram,0x00238e40) */
/* WARNING: Removing unreachable block (ram,0x00238744) */

void DoBehavior_Camera_Unk(void)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  vec4 vec;
  vec4 vec_00;
  vec4 vec_01;
  vec4 vec_02;
  vec4 vec_03;
  vec4 vec_04;
  vec4 vec_05;
  vec4 vec_06;
  undefined2 uVar6;
  moby *pmVar7;
  moby *pmVar8;
  char cVar9;
  short sVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  long lVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  uint uVar17;
  int iVar18;
  undefined8 unaff_s0;
  ulong uVar19;
  uint uVar20;
  undefined4 *puVar21;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  undefined8 unaff_s8;
  undefined8 unaff_retaddr;
  undefined4 uVar22;
  float fVar23;
  float_conflict fVar24;
  float fVar25;
  float fVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  float fVar29;
  undefined4 in_stack_fffffec0;
  undefined4 in_stack_fffffec4;
  undefined4 in_stack_fffffec8;
  float in_stack_fffffecc;
  float fStack_130;
  float fStack_12c;
  undefined4 uStack_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  undefined1 uStack_118;
  undefined1 uStack_117;
  undefined2 uStack_116;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  undefined4 uStack_108;
  float fStack_100;
  float fStack_fc;
  undefined4 uStack_f8;
  undefined1 auStack_f0 [16];
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  float fStack_d4;
  undefined4 uStack_d0;
  int iStack_cc;
  uint uStack_c8;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  pmVar7 = hero.pMoby;
  uStack_70 = (undefined4)unaff_s5;
  uStack_6c = (undefined4)((ulong)unaff_s5 >> 0x20);
  uStack_30 = (undefined4)unaff_retaddr;
  uStack_2c = (undefined4)((ulong)unaff_retaddr >> 0x20);
  uStack_40 = (undefined4)unaff_s8;
  uStack_3c = (undefined4)((ulong)unaff_s8 >> 0x20);
  uStack_50 = (undefined4)unaff_s7;
  uStack_4c = (undefined4)((ulong)unaff_s7 >> 0x20);
  uStack_60 = (undefined4)unaff_s6;
  uStack_5c = (undefined4)((ulong)unaff_s6 >> 0x20);
  uStack_80 = (undefined4)unaff_s4;
  uStack_7c = (undefined4)((ulong)unaff_s4 >> 0x20);
  uStack_90 = (undefined4)unaff_s3;
  uStack_8c = (undefined4)((ulong)unaff_s3 >> 0x20);
  uStack_a0 = (undefined4)unaff_s2;
  uStack_9c = (undefined4)((ulong)unaff_s2 >> 0x20);
  uStack_b0 = (undefined4)unaff_s1;
  uStack_ac = (undefined4)((ulong)unaff_s1 >> 0x20);
  uStack_c0 = (undefined4)unaff_s0;
  uStack_bc = (undefined4)((ulong)unaff_s0 >> 0x20);
  iStack_cc = hero.field8166_0x2088;
  uStack_c8 = (uint)(byte)(hero.pMoby)->field_0x53;
  fVar26 = (float)hero._232_4_;
  switch(hero.state) {
  case HERO_STATE_IDLE:
  case HERO_STATE_LOOK:
  case HERO_STATE_SKID:
  case HERO_STATE_CROUCH:
  case HERO_STATE_LEDGE_GRAB:
  case HERO_STATE_TARGETING:
  case HERO_STATE_GUN_WAITING:
  case HERO_STATE_WALLOPER_ATTACK:
  case HERO_STATE_LAVA_JUMP|HERO_STATE_QUICK_TURN:
  case HERO_STATE_MAGNE_JUMP:
  case HERO_STATE_CUT_SCENE:
  case HERO_STATE_WADE:
  case HERO_STATE_ROCKET_HOVER:
    if (hero._8361_1_ != '\0') {
      FUN_0022ac40(0xf,0x1e);
    }
    fVar26 = 0.0;
    FUN_00233850(0x3f000000,momentumMultiplyer + momentumMultiplyer);
    FUN_00236a68(0x406ccccd,fVar26);
    FUN_00231f70(0x3f800000,0);
    if (((hero.state == HERO_STATE_LOOK) || (hero.state == HERO_STATE_GUN_WAITING)) &&
       (hero._8357_1_ != '\0')) {
      FUN_002215e0(0x13f4c0,&stack0xfffffec0,0x167450);
      hero._384_4_ = DAT_00167258;
      TurnWithCameraCheck(DAT_0015ed64,DAT_0015ed64 * fVar26,momentumMultiplyer * 174.53293,0);
      if ((0 < iGpffff8a88) && (lVar14 = FastDecTimer(&iGpffff8a88), lVar14 != 0)) {
        uVar27 = uGpffff82a4;
        if (DAT_001418d8 != -1) {
          DAT_001418d8 = DAT_001418d8 + 1;
          uVar27 = DAT_0015eea4;
        }
        iVar12 = FUN_00220e30(uVar27);
        uVar17 = uGpffff8184;
        if ((int)(uint)DAT_001418da < iVar12 / 600) {
          iVar12 = FUN_00220e30(uGpffff82a4);
          DAT_001418da = (ushort)(iVar12 / 600);
          uVar17 = Level;
        }
        iGpffff8a88 = -1;
        DAT_001418dc = DAT_001418dc | 1 << (uVar17 & 0x1f) | 0x80000000;
        iGpffff8a8c = iGpffff8a8c + 1;
      }
    }
    if ((hero.state == HERO_STATE_SKID) && (lVar14 = FUN_00242858(), lVar14 != 0))
    goto LAB_0023c3f8;
    if (((hero.state == HERO_STATE_CROUCH) || (hero.state == HERO_STATE_LEDGE_GRAB)) &&
       (((0.2 < (float)hero._8860_4_ || ((hero.pMoby)->field_0x53 == '\x0e')) ||
        ((hero.pMoby)->field_0x53 == '\x0f')))) {
      if (hero.state == HERO_STATE_CROUCH) {
        TurnWithCameraCheck(DAT_0015ed64 * 0.002,DAT_0015ed64 * 0.07,momentumMultiplyer * 6.981317,0
                           );
      }
      else if (hero.state == HERO_STATE_LEDGE_GRAB) {
        FUN_002324f8();
      }
      fVar26 = (float)FUN_00221128(hero._388_4_);
      if (momentumMultiplyer * 0.34906584 < fVar26) {
        cVar9 = ((float)hero._388_4_ < 0.0) + '\x0e';
        if ((hero.pMoby)->field_0x53 != cVar9) {
          iVar12 = FUN_00220e30(5);
          FUN_00247a90((float)iVar12,cVar9,0);
        }
        fVar26 = (float)FUN_00221128(hero._388_4_);
        hero._2704_4_ = fVar26 / (momentumMultiplyer * 3.3161256);
        if ((float)hero._2704_4_ < 0.55) {
          hero._2704_4_ = 0x3f0ccccd;
        }
        if (2.5 < (float)hero._2704_4_) {
          hero._2704_4_ = 0x40200000;
        }
      }
      else if ((float)hero._388_4_ == 0.0) {
        uVar19 = 0xd;
        if (hero.state == HERO_STATE_LEDGE_GRAB) {
          uVar19 = FUN_00226f10(0);
        }
        if ((byte)(hero.pMoby)->field_0x53 != uVar19) {
          iVar12 = FUN_00220e30(7);
          FUN_00247a90((float)iVar12,uVar19,0);
        }
      }
    }
    hero._400_4_ = 0;
    if (hero.state == HERO_STATE_SKID) {
      fVar26 = (float)hero._364_4_ + 1.0;
      if (1.0 < (float)hero._364_4_ + 1.0) {
        fVar26 = 1.0;
      }
      fVar26 = DAT_0015ed70 * 12.0 * fVar26;
      hero._8848_4_ = fVar26;
      if (((hero.pMoby)->field_0x52 == (hero.pMoby)->field_0x53) &&
         ((hero.pMoby)->field_0x52 != '\x14')) {
        fVar29 = (float)hero._356_4_ / fVar26;
        iVar12 = FUN_00220e30(5);
        if ((fVar29 <= (float)iVar12) || (5.5 <= (float)(byte)(hero.pMoby)->field_0x51)) {
          if (6.5 < (float)(byte)(hero.pMoby)->field_0x51) {
            hero._2704_4_ = 0x3f800000;
          }
        }
        else {
          FUN_0022a620(0x41500000,fVar29,0x3f000000,0xbf800000);
          if (1.1 < (float)hero._2704_4_) {
            hero._2704_4_ = 0x3f8ccccd;
          }
        }
      }
    }
    else if (hero.state == HERO_STATE_CROUCH) {
      fVar26 = fGpffff8170 * 6.48;
    }
    else {
      fVar26 = fGpffff8170 * 12.6;
    }
    uVar27 = 0;
    FUN_002326e8(0,fVar26);
    FUN_00221170(0x13f430);
    FUN_00236678(fVar26);
    if ((hero._4839_1_ != '\0') && (DAT_0013d4dc != '\0')) {
      fVar26 = fGpffff8170;
      if (0.2 < (float)hero._732_4_) goto LAB_0023c3a4;
      FUN_00248b68(fGpffff8170 * 54.0,0x13f430,0x13f430);
      fVar26 = (float)hero._232_4_;
      if (hero._764_4_ != 0) {
        hero.pos.x = hero._672_4_;
        hero.pos.z = hero._676_4_;
        hero.pos.y = hero._680_4_;
        hero.pos.w = hero._684_4_;
        hero._782_2_ = 0;
        hero._732_4_ = uVar27;
      }
      break;
    }
    FUN_00232978(0);
    if (hero._782_2_ != 0) goto LAB_0023c2e4;
    uVar15 = 0x13f430;
    fVar26 = 54.0;
    fVar29 = DAT_0015ed70;
    goto LAB_0023c3b4;
  case HERO_STATE_WALK:
  case HERO_STATE_ZIP:
    bVar1 = false;
    if ((hero._4836_1_ != '\0') && ((float)hero._8868_4_ < 0.25)) {
      bVar1 = true;
    }
    if ((hero._8361_1_ != '\0') || (fVar26 = fGpffff816c, bVar1)) {
      if (momentumMultiplyer < (float)hero._356_4_) {
        FUN_0022ad38(0,2);
      }
      if (momentumMultiplyer * 0.5 < (float)hero._356_4_) {
        FUN_0022af48(2,4);
      }
      FUN_0022b140(5,2);
      fVar26 = momentumMultiplyer;
    }
    if (((float)hero._356_4_ < fVar26 * 0.3) && (0.85 < (float)hero._8860_4_)) {
      hero._952_2_ = 1;
    }
    fVar26 = (float)FUN_00221128(hero._392_4_);
    if (((fVar26 < 0.05235988) || (hero._8360_1_ != '\0')) || (hero.field8166_0x2088 == 1)) {
      hero._952_2_ = 0;
    }
    if (hero._958_2_ != 0) {
      fVar26 = (float)FUN_00221128(hero._392_4_);
      if (0.06981317 <= fVar26) {
        if (hero._8360_1_ != '\0') {
          hero._958_2_ = 0;
        }
      }
      else {
        hero._958_2_ = 0;
      }
    }
    FUN_00232290();
    if (0.0 < (float)hero._2352_4_) {
      FUN_00233850(0x3f333333);
      fVar26 = (float)FUN_002338e8(&stack0xfffffec0);
      fVar26 = (float)hero._400_4_ + fVar26;
      hero._400_4_ = momentumMultiplyer * 0.7;
      if ((float)hero._400_4_ <= fVar26) {
        hero._400_4_ = fVar26;
      }
      FUN_00221170(0x13fc70);
    }
    fVar26 = 1.0;
    if ((hero.field8166_0x2088 == 1) && (hero._958_2_ == 0)) {
      TurnWithCameraCheck(DAT_0015ed64 * 0.008,DAT_0015ed64 * 0.15,momentumMultiplyer * 9.948377,0);
    }
    else {
      if (hero._8360_1_ == '\0') {
        if ((float)hero._8860_4_ < 0.8) {
          bVar1 = 0.5235988 < (float)hero._392_4_;
          goto code_r0x0023a5dc;
        }
      }
      else {
        fVar26 = 1.0 - (float)hero._392_4_ * 0.55;
        bVar1 = fVar26 < 0.0;
code_r0x0023a5dc:
        if (bVar1) {
          fVar26 = 0.0;
        }
      }
      if (DAT_0017c244 < (float)hero._8860_4_) {
        DoTurn();
      }
      else {
        TurnWithCameraCheck(DAT_0015ed64 * 0.005 * ((float)hero._8860_4_ + 0.35),DAT_0015ed64 * 0.1,
                            momentumMultiplyer * 4.712389 * ((float)hero._8860_4_ + 0.35),0);
      }
    }
    FUN_00235638();
    FUN_00235e60();
    fVar29 = 8.5;
    if (hero._958_2_ != 0) {
      fVar23 = 2.6179938 - (float)hero._392_4_;
      if (1.0 < 2.6179938 - (float)hero._392_4_) {
        fVar23 = 1.0;
      }
      if (fVar23 < 0.2) {
        fVar23 = 0.2;
      }
      fVar29 = 17.0;
      hero._400_4_ = (float)hero._400_4_ * fVar23;
    }
    FUN_002326e8(DAT_0015ed70 * 7.5 * fVar26,DAT_0015ed70 * fVar29);
    if ((hero._952_2_ == 0) || (hero._776_2_ != 0)) {
      FUN_00232738(0x47c34f80);
    }
    else {
      FUN_00232738(hero._384_4_);
    }
    FUN_00232978(1);
    if (hero._500_2_ != 0) {
      FUN_00236a68(0x40a00000,0x3e4ccccd);
    }
    if (hero._782_2_ != 0) {
      uVar15 = 0x13f470;
      fVar26 = 25.0;
LAB_0023c2f4:
      FUN_00248b68(fGpffff8170 * fVar26,0x13f430,uVar15);
      FUN_00232820();
      goto LAB_0023c3f8;
    }
    uVar15 = 0x13f430;
    fVar26 = 54.0;
    fVar29 = DAT_0015ed70;
    goto LAB_0023c3b4;
  case HERO_STATE_FALL:
  case HERO_STATE_RECOIL:
    FUN_00232290();
    if (hero._452_4_ == 0) {
      FUN_00234b40();
    }
    FUN_00235638();
    FUN_00233850(0x3f333333,momentumMultiplyer * 0.0);
    goto LAB_0023b034;
  case HERO_STATE_JUMP:
  case HERO_STATE_RUN_JUMP:
  case HERO_STATE_LONG_JUMP:
  case HERO_STATE_FLIP_JUMP:
  case HERO_STATE_JINK_JUMP:
  case HERO_STATE_ROCKET_JUMP:
  case HERO_STATE_DOUBLE_JUMP:
  case HERO_STATE_HELI_JUMP:
  case HERO_STATE_CHARGE_JUMP:
  case HERO_STATE_WALL_JUMP:
  case HERO_STATE_WATER_JUMP:
  case HERO_STATE_VISIBOMB:
  case HERO_STATE_LAVA_JUMP|HERO_STATE_CROUCH:
  case 0x49:
  case 0x4c:
  case 0x5e:
  case HERO_STATE_QUICKSAND_JUMP:
    if (((hero.state == HERO_STATE_VISIBOMB) && (hero._8920_2_ == 0)) &&
       ((hero._4520_4_ == 3 && (lVar14 = FUN_00231f18(0x41200000), lVar14 != 0)))) {
      FUN_00236738(4,0);
    }
    if ((hero._1192_2_ == 0) || (hero._4834_1_ == '\0')) {
      if (hero._1048_4_ != 0) {
        FUN_00231f70(fGpffff816c * 5.7,0);
      }
      FUN_00231f70(hero._1060_4_,0);
    }
    else {
      hero._400_4_ = hero._404_4_;
    }
    if (hero.state == HERO_STATE_WATER_JUMP) {
      iVar12 = FUN_00220e30(0x14);
      if ((hero._408_4_ == iVar12) && (FUN_0022b3a8(3,0x10,1), PTR_DAT_001612d0 != (undefined *)0x0)
         ) {
        FUN_002b82a8(hero.pos.x,hero.pos.z,0x3ecccccd,0x3eb33333,PTR_DAT_001612d0,DAT_001612d8,0);
      }
      if ((4.0 <= (float)hero._2728_4_) && ((float)hero._2728_4_ <= 7.0)) {
        FUN_0022b140(7,0);
      }
    }
    if (hero._408_4_ == hero._1056_4_) {
      hero._1024_4_ = hero.pos.x;
      hero._1028_4_ = hero.pos.z;
      hero._1032_4_ = hero.pos.y;
      hero._1036_4_ = hero.pos.w;
    }
    if ((hero._1048_4_ == 0) &&
       (((((((int)hero._1056_4_ <= (int)hero._408_4_ || (hero.state == HERO_STATE_FLIP_JUMP)) ||
           (hero.state == HERO_STATE_CHARGE_JUMP)) ||
          ((hero.state == HERO_STATE_JINK_JUMP || (hero.state == HERO_STATE_WALL_JUMP)))) ||
         (hero.state == HERO_STATE_VISIBOMB)) || (hero.state == 0x4c)))) {
      FUN_00234b40();
      if (hero.state == HERO_STATE_WATER_JUMP) {
        vec_03.z = (float)in_stack_fffffec4;
        vec_03.x = (float)in_stack_fffffec0;
        vec_03.y = (float)in_stack_fffffec8;
        vec_03.w = in_stack_fffffecc;
        fVar26 = (float)vector_length(vec_03);
        if (momentumMultiplyer * 3.7 < fVar26) {
          fVar26 = momentumMultiplyer * 3.7;
        }
        FUN_00221460(fVar26,0x13f430,0x13f430);
      }
    }
    else {
      TurnWithCameraCheck(fGpffff8164 * 0.015,fGpffff8164 * 0.2,momentumMultiplyer * 15.009831,0);
      uVar27 = hero._404_4_;
      if (1 < (int)hero._1048_4_) {
        hero._404_4_ = (float)hero._404_4_ * 0.4;
      }
      FUN_00232738(0x47c34f80);
      hero._404_4_ = uVar27;
      if (hero._1048_4_ != 1) {
        FUN_002326e8(hero._1152_4_,hero._1156_4_);
      }
      if (hero._776_2_ != 0) {
        hero._404_4_ = 0;
      }
      fVar26 = momentumMultiplyer;
      if (hero._1048_4_ != 0) {
        if ((g_Pad.handsOffStick != 0) && (hero._778_2_ != 0)) {
          hero._404_4_ = 0;
        }
        fVar26 = fGpffff816c;
        if (hero._1048_4_ != 0) {
          FUN_00236678(hero._1156_4_);
          fVar26 = momentumMultiplyer;
        }
      }
      FUN_00233850(0x3f000000,fVar26 + fVar26);
      if ((hero.state == HERO_STATE_RUN_JUMP) &&
         (iVar12 = FUN_00220e30(4), (int)hero._408_4_ < hero._1056_4_ + iVar12)) {
        FUN_00248da0(fGpffff8170 * 16.0 * (float)(int)hero._408_4_,0x13f430,0x13f430);
      }
      if ((hero.state == HERO_STATE_LONG_JUMP) &&
         (iVar12 = FUN_00220e30(0x22), (int)hero._408_4_ < iVar12)) {
        FUN_00248da0(fGpffff8170 * 53.0 * (float)(int)hero._408_4_,0x13f430,0x13f430);
      }
      iVar12 = FUN_00220e30(10);
      if (((int)hero._408_4_ < iVar12) && (0.2 < (float)hero._8860_4_)) {
        fVar26 = hero.pos.x;
        fVar29 = hero.pos.z;
        fVar23 = hero.pos.y;
        fVar25 = hero.pos.w;
        FUN_00248ea8(0x3f000000,&stack0xfffffec0,&stack0xfffffec0);
        fStack_130 = fVar26;
        fStack_12c = fVar29;
        uStack_128 = fVar23;
        fStack_124 = fVar25;
        fVar26 = (float)FUN_002216f8(hero.rot.y);
        fStack_130 = fStack_130 + fVar26 * 0.85;
        fVar26 = (float)FUN_00221710(hero.rot.y);
        fStack_12c = fStack_12c + fVar26 * 0.85;
        lVar14 = FUN_00211870(&stack0xfffffec0,&fStack_130,4,hero.pMoby,0);
        if (lVar14 != 0) {
          hero._1188_2_ = 1;
        }
      }
    }
    if (((float)hero._1040_4_ < (float)hero._728_4_) &&
       (hero._1040_4_ = (float)hero._1040_4_ + fGpffff816c * 6.0,
       (float)hero._728_4_ < (float)hero._1040_4_)) {
      hero._1040_4_ = hero._728_4_;
    }
    if (hero.pos.y < (float)hero._1040_4_) {
      hero._1040_4_ = hero.pos.y;
    }
    if (((((int)hero._1056_4_ < (int)hero._408_4_) &&
         (fVar26 = (float)FUN_00249110(0x13f430), fVar26 < 0.001)) &&
        ((hero._1052_2_ == 0 || ((int)hero._980_4_ < (int)hero._408_4_)))) &&
       (hero._1054_2_ = 1, (float)hero._1016_4_ != 0.0)) {
      hero._1184_4_ = hero._1016_4_;
    }
    if (hero._8356_1_ == '\0') {
      FUN_00235638();
    }
    if ((hero.state == HERO_STATE_CHARGE_JUMP) || (hero.state == HERO_STATE_ROCKET_JUMP)) {
      iVar12 = FUN_00220e30(0xc);
      FUN_00277508(0x1409c0,(uint)(iVar12 < (int)hero._408_4_) << 1);
    }
    if (((hero.state == HERO_STATE_CHARGE_JUMP) &&
        (iVar12 = FUN_00220e30(8), iVar12 < (int)hero._408_4_)) && ((float)hero._2728_4_ < 28.0)) {
      FUN_00248cf8(0x3f4ccccd,0,0x3e99999a,&stack0xfffffec0);
      iVar12 = FUN_00214468(0x3f666666,&stack0xfffffec0,0,hero.pMoby,0);
      if ((iVar12 != 0) && (FUN_00221210(0x40e00000,&fStack_130,0x13f450), 0 < iVar12)) {
        puVar21 = &DAT_00178380;
        do {
          lVar14 = FUN_00273278(*puVar21);
          if (lVar14 != 0) {
            FUN_0026eaa8(0x3f800000,*puVar21,hero.pMoby,0x10000,0x13f3d0,&fStack_130);
          }
          iVar12 = iVar12 + -1;
          puVar21 = puVar21 + 1;
        } while (iVar12 != 0);
      }
    }
    FUN_002345f0();
    goto LAB_0023bbc0;
  case HERO_STATE_GLIDE:
    lVar14 = FUN_0022ddd8(3);
    if (lVar14 == 2) {
      if (((hero._8744_4_ != -1) &&
          ((moby *)(&PTR_DAT_0013e5d8)[hero._8744_4_ * 0x1c] == hero.pMoby)) &&
         ((&DAT_0013e5c4)[hero._8744_4_ * 0x70] != '\0')) {
        FUN_002a1348(hero._8744_4_);
      }
      hero._8744_4_ = 0xffffffff;
      FUN_00236798(3,hero.pMoby,2);
      fVar26 = fGpffff816c;
    }
    else {
      if (((hero._8740_4_ != -1) &&
          ((moby *)(&PTR_DAT_0013e5d8)[hero._8740_4_ * 0x1c] == hero.pMoby)) &&
         ((&DAT_0013e5c4)[hero._8740_4_ * 0x70] != '\0')) {
        FUN_002a1348(hero._8740_4_);
      }
      hero._8740_4_ = 0xffffffff;
      FUN_00236798(4,hero.pMoby,0x12);
      fVar26 = momentumMultiplyer;
    }
    fVar29 = 3.0;
    if (hero._4520_4_ == 3) {
      fVar29 = 5.0;
    }
    FUN_00231f70(fVar26 * fVar29,0);
    TurnWithCameraCheck(DAT_0015ed64 * 0.025,DAT_0015ed64 * 0.3,momentumMultiplyer * 12.566371,0);
    FUN_002326e8(DAT_0015ed70 * 15.0,DAT_0015ed70 * 7.0);
    FUN_00232738(0x47c34f80);
    FUN_00235638();
    FUN_00248f68(0x13f430,0x13f430);
    FUN_00248b68(fVar26 * fVar29 * 0.72,0x13f430,0x13f430);
    if (hero.pos.y < (float)hero._1040_4_) {
      FUN_00270728(hero.pos.y,fGpffff816c * 4.0,0x13f760);
    }
LAB_0023bbc0:
    FUN_0022c9a0();
    goto LAB_0023c3f8;
  case HERO_STATE_COMBO_ATTACK:
    if ((hero._2716_4_ != 0) ||
       ((float)hero._2728_4_ < (float)*(int *)(&DAT_0017c0c8 + hero._2656_4_ * 0x2c))) {
      hero._4264_2_ = 2;
    }
    iVar12 = hero._2656_4_ * 0x2c;
    hero._400_4_ = 0;
    fVar26 = (float)hero._2668_4_;
    if ((hero._2644_4_ == 0) ||
       (iVar18 = FUN_00220e30(4), fVar26 = (float)hero._2668_4_, iVar18 <= (int)hero._408_4_)) {
LAB_00239924:
      hero._2668_4_ = fVar26;
      iVar18 = *(int *)(&DAT_0017c0ac + iVar12);
    }
    else {
      fVar29 = (float)FUN_00221398(hero._2644_4_ + 0x10,0x13f3d0);
      fVar29 = fVar29 - 0.5;
      if (fVar29 < 0.0) {
        fVar29 = 0.0;
      }
      if (*(int *)(&DAT_0017c0ac + iVar12) == 0) {
        fVar26 = 0.8;
        fVar23 = 4.0;
        fVar29 = fVar29 - 0.75;
      }
      else if (*(int *)(&DAT_0017c0ac + iVar12) == 1) {
        fVar26 = 1.7;
        fVar23 = 4.0;
        fVar29 = fVar29 - 0.6;
      }
      else {
        fVar26 = 1.7;
        fVar23 = 1.9;
        fVar29 = fVar29 - 1.3;
      }
      fVar25 = (float)FUN_00221128(fVar29);
      if (fVar25 < fVar26 + 3.0) {
        fVar26 = fVar29 / 0.9;
        if (fVar23 < fVar29 / 0.9) {
          fVar26 = fVar23;
        }
        if (fVar26 <= 1.0) {
          fVar26 = (float)hero._2668_4_;
        }
        goto LAB_00239924;
      }
      iVar18 = *(int *)(&DAT_0017c0ac + iVar12);
    }
    if (iVar18 == 1) {
      if ((hero._2716_4_ != 0) || ((float)hero._2728_4_ < 9.0)) {
        if (8.0 < (float)hero._2728_4_) {
          fVar26 = 3.0;
        }
        else if (7.0 < (float)hero._2728_4_) {
          fVar26 = 4.5;
        }
        else {
          fVar26 = 5.7;
        }
LAB_00239a74:
        hero._400_4_ = fGpffff816c * fVar26 * (float)hero._2668_4_;
      }
    }
    else if (iVar18 < 2) {
      if ((iVar18 == 0) && ((float)hero._2728_4_ < 18.0)) {
        hero._400_4_ = fGpffff816c * 4.4 * (float)hero._2668_4_;
      }
    }
    else if ((iVar18 == 2) && ((hero._2716_4_ != 0 || ((float)hero._2728_4_ < 12.0)))) {
      fVar26 = 3.7;
      goto LAB_00239a74;
    }
    FUN_00270728(0x3f800000,0x3e4ccccd);
    if (hero._2648_4_ == 0) {
      if (hero._2644_4_ != 0) {
        iVar12 = *(int *)(&DAT_0017c0ac + iVar12);
        goto LAB_00239ac4;
      }
      bVar1 = true;
      if (((*(int *)(&DAT_0017c0ac + iVar12) == 1) && (hero._2716_4_ == 0)) &&
         (7.0 < (float)hero._2728_4_)) {
        bVar1 = false;
      }
      fVar26 = fGpffff8170;
      if (bVar1) {
        FUN_002351d0(0x40a00000,0x3f490fdb,0x3f490fdb);
        fVar26 = DAT_0015ed70;
      }
    }
    else {
      iVar12 = *(int *)(&DAT_0017c0ac + iVar12);
LAB_00239ac4:
      fVar26 = fGpffff8164;
      if ((iVar12 == 1) && (fVar29 = FastSubRots(), fVar26 = fGpffff8164, 0.0 < fVar29)) {
        fVar26 = (float)FastDiffRots(hero._2652_4_,hero.rot.y);
        hero._2704_4_ = 1.0 / (fVar26 + 1.0);
        fVar26 = DAT_0015ed64;
      }
      hero._384_4_ = hero._2652_4_;
      TurnWithCameraCheck(fVar26 * 0.05,fVar26 * 0.2,momentumMultiplyer * 15.009831,0);
      fVar26 = fGpffff8170;
    }
    FUN_002326e8(fVar26 * 37.0,fVar26 * 28.0);
    if (hero._2648_4_ == 0) {
      FUN_00232738(0x47c34f80);
    }
    else {
      FUN_00232738(hero._2652_4_);
    }
    if (hero._782_2_ == 0) {
      FUN_00248b68(DAT_0015ed70 * 54.0,0x13f430,0x13f430);
    }
    else {
      FUN_00248b68(fGpffff8170 * 25.0,0x13f430,0x13f470);
    }
    FUN_00236a68(0x406ccccd,0);
    goto LAB_0023c3f8;
  case HERO_STATE_JUMP_ATTACK:
    if ((hero._2716_4_ != 0) ||
       ((float)hero._2728_4_ < (float)*(int *)(&DAT_0017c0c0 + hero._2656_4_ * 0x2c))) {
      hero._4264_2_ = 2;
    }
    hero._400_4_ = 0;
    if (hero._2644_4_ == 0) {
      FUN_002326e8(DAT_0015ed70 * 15.0,DAT_0015ed70 * 15.0);
      FUN_00249238(hero._404_4_,0x13f430,0x13f430);
    }
    else {
      fVar26 = (float)FUN_00221398(0x13f3d0,hero._2644_4_ + 0x10);
      if ((2.0 < fVar26) && (fVar26 < 5.0)) {
        hero._400_4_ = fGpffff816c * 4.5;
      }
      FUN_002326e8(DAT_0015ed70 * 25.0,DAT_0015ed70 * 25.0);
      fVar26 = (float)FUN_002216f8(hero.rot.y);
      hero._224_4_ = fVar26 * (float)hero._404_4_;
      fVar26 = (float)FUN_00221710(hero.rot.y);
      hero._228_4_ = fVar26 * (float)hero._404_4_;
    }
    if ((hero._2648_4_ == 0) && (hero._2644_4_ == 0)) {
      if ((float)hero._2728_4_ < 25.0) {
        FUN_002351d0(0x41000000,0x3f860a92,0x3f860a92);
      }
    }
    else {
      hero._384_4_ = hero._2652_4_;
      TurnWithCameraCheck(fGpffff8164 * 0.05,fGpffff8164 * 0.2,momentumMultiplyer * 15.009831,0);
    }
    iVar12 = FUN_00220e30(9);
    fVar29 = momentumMultiplyer * 7.7;
    fVar26 = 0.5;
    if ((float)hero._732_4_ <= 2.25) {
      fVar26 = fGpffff8170;
      if (1.8 < (float)hero._732_4_) {
        fVar26 = 0.7;
        goto LAB_00239308;
      }
    }
    else {
LAB_00239308:
      fVar29 = fVar29 * fVar26;
      fVar26 = DAT_0015ed70;
    }
    iVar18 = FUN_00220e30(0xe);
    if ((((hero._2716_4_ == 0) && (23.5 < (float)hero._2728_4_)) &&
        (uVar27 = 0, (float)hero._264_4_ < 0.0)) && (hero._782_2_ != 0)) {
      FUN_00248d80(0xbf000000,&stack0xfffffec0,&stack0xfffffec0);
      fStack_100 = (float)FUN_002216f8(hero.rot.y);
      fStack_100 = fStack_100 + fStack_100;
      fStack_fc = (float)FUN_00221710(hero.rot.y);
      fStack_fc = fStack_fc + fStack_fc;
      uStack_f8 = uVar27;
      FUN_0026e808(0x40000000,&fStack_130,hero.pMoby,0x10000,&fStack_100);
      fStack_124 = 5627.925;
      uStack_117 = 1;
      uStack_116 = 0x47;
      uStack_118 = 0;
      FUN_00214468(0x3ecccccd,&stack0xfffffec0,0x10,hero.pMoby,&fStack_130);
    }
    FUN_00231f18(0x41d80000);
    if (iVar12 <= (int)hero._408_4_) {
      fVar26 = (float)hero._232_4_;
      if ((int)hero._408_4_ <= iVar18) break;
      FUN_00248b68(fGpffff8170 * 130.0,0x13f430,0x13f430);
      fVar26 = (float)FUN_00249110(0x13f430);
      if (fVar26 < 0.0) {
        hero._2672_4_ = 0x3f800000;
      }
      fVar23 = (float)FUN_00249110(0x13f430);
      fVar29 = momentumMultiplyer * -37.0;
      goto LAB_0023b064;
    }
    fStack_d4 = (float)FUN_00249110(0x13f430);
    FUN_00270728(fVar29,fVar26 * 150.0,&fStack_d4);
    fVar29 = fStack_d4;
    goto LAB_0023b074;
  case HERO_STATE_THROW_ATTACK:
    hero._400_4_ = 0;
    if ((hero._2716_4_ != 0) ||
       ((float)hero._2728_4_ < (float)*(int *)(&DAT_0017c0c0 + hero._2656_4_ * 0x2c))) {
      hero._4264_2_ = 2;
    }
    bVar1 = false;
    if (hero.field8168_0x2090 == 1) {
      iVar12 = FUN_00220e30(0x14);
      bVar1 = true;
      if ((int)hero._8344_4_ <= iVar12) {
        bVar1 = false;
      }
    }
    if (!bVar1) {
      if ((hero._2648_4_ == 0) && (hero._2644_4_ == 0)) {
        bVar1 = true;
        if ((hero._2716_4_ == 0) && (6.0 < (float)hero._2728_4_)) {
          bVar1 = false;
        }
        if ((bVar1) && (hero._8371_1_ == '\0')) {
          FUN_002351d0(0x41600000,0x3f060a92,0x3f490fdb);
        }
      }
      else {
        if (hero._776_2_ == 0) {
          fVar26 = FastSubRots();
          fVar29 = (float)FUN_002709f8(hero._2652_4_,hero.rot.y,1);
          bVar1 = fVar29 <= 4.363323;
          if (0.0 < fVar26) {
            hero._2704_4_ = 1.0 / (fVar29 + 1.0);
          }
        }
        else {
          bVar1 = false;
        }
        hero._384_4_ = hero._2652_4_;
        TurnWithCameraCheck(DAT_0015ed64 * 0.05,DAT_0015ed64 * 0.2,momentumMultiplyer * 15.009831,
                            bVar1);
      }
    }
    fVar26 = fGpffff8170;
    if ((hero._2716_4_ == 0) &&
       (lVar14 = FUN_00231f18(0x42040000), fVar26 = fGpffff8170, lVar14 != 0)) {
      FUN_00236da0();
      fVar26 = DAT_0015ed70;
    }
    FUN_002326e8(fVar26 * 37.0,fVar26 * 28.0);
    FUN_00232738(0x47c34f80);
    if (hero._782_2_ == 0) {
      fVar26 = 54.0;
      uVar15 = 0x13f430;
      fVar29 = DAT_0015ed70;
    }
    else {
      uVar15 = 0x13f470;
      fVar26 = fGpffff8170;
      fVar29 = 25.0;
    }
    goto LAB_0023c3b4;
  case HERO_STATE_GET_HIT:
    vec_04.z = (float)in_stack_fffffec4;
    vec_04.x = (float)in_stack_fffffec0;
    vec_04.y = (float)in_stack_fffffec8;
    vec_04.w = in_stack_fffffecc;
    fVar26 = (float)vector_length(vec_04);
    fVar29 = DAT_0015ed70 * 4.0;
    if ((hero._782_2_ == 0) && (iVar12 = FUN_00220e30(10), iVar12 < (int)hero._408_4_)) {
      fVar29 = fGpffff8170 * 10.0;
    }
    fVar26 = fVar26 - fVar29;
    if (fVar26 < 0.0) {
      fVar26 = 0.0;
    }
    if (hero._4839_1_ != '\0') {
      FUN_00236a68(0x406ccccd);
    }
    FUN_00221460(fVar26,0x13f430,0x13f430);
LAB_0023c3c8:
    FUN_00248b68(0x3b83126f,0x13f430,0x13f430);
    goto LAB_0023c3f8;
  case HERO_STATE_LEDGE_IDLE:
  case HERO_STATE_LEDGE_TRAVERSE_LEFT:
    hero._384_4_ = FastAddRots(hero._1252_4_,0x40490fdb);
    TurnWithCameraCheck(DAT_0015ed64 * 0.04,DAT_0015ed64 * 0.2,momentumMultiplyer * 6.2831855,0);
    FUN_00270ac0(0,momentumMultiplyer * 4.712389,0x13f3e4,0);
    FUN_002211b8(0x13f430,0x13f820,0x13f3d0);
    FUN_002745f0(momentumMultiplyer * 4.0,0x13f430);
    FUN_00270728(hero.pos.y,momentumMultiplyer * 3.0,0x13f840);
    goto LAB_0023c3f8;
  case HERO_STATE_LEDGE_TRAVERSE_RIGHT:
  case HERO_STATE_LEDGE_JUMP:
    hero._224_4_ = 0;
    hero._228_4_ = 0;
    hero._232_4_ = 0;
    fStack_120 = hero.pos.x;
    fStack_11c = hero.pos.z;
    uStack_118 = SUB41(hero.pos.y,0);
    uStack_117 = (undefined1)((uint)hero.pos.y >> 8);
    uStack_116 = (undefined2)((uint)hero.pos.y >> 0x10);
    fStack_114 = hero.pos.w;
    uVar27 = 0xbfc90fdb;
    if (hero.state == HERO_STATE_LEDGE_TRAVERSE_RIGHT) {
      uVar27 = 0x3fc90fdb;
    }
    fVar26 = 0.3;
    uVar28 = FastAddRots(hero.rot.y,uVar27);
    fStack_100 = (float)FUN_002216f8(uVar28);
    fStack_100 = fStack_100 * fVar26;
    uVar27 = FastAddRots(hero.rot.y,uVar27);
    fStack_fc = (float)FUN_00221710(uVar27);
    fStack_fc = fStack_fc * fVar26;
    uStack_f8 = 0;
    FUN_00221188(&fStack_110,&fStack_120,&fStack_100);
    FUN_0022d090();
    fVar26 = (float)hero._232_4_;
    if (hero._1256_4_ != 0) {
      uVar27 = FastAddRots(hero._1252_4_,0x40490fdb);
      FUN_0022d090();
      hero.pos.y = (float)CONCAT22(uStack_116,CONCAT11(uStack_117,uStack_118));
      hero.pos.x = fStack_120;
      hero.pos.z = fStack_11c;
      hero.pos.w = fStack_114;
      fVar26 = (float)hero._232_4_;
      if (hero._1256_4_ != 0) {
        fStack_130 = hero._1232_4_;
        fStack_12c = hero._1236_4_;
        uStack_128 = hero._1240_4_;
        fStack_124 = hero._1244_4_;
        uVar28 = FastAddRots(hero._1252_4_,0x40490fdb);
        fVar26 = (float)FastDiffRots(uVar27,uVar28);
        if (fVar26 <= 0.5235988) {
          fVar26 = FastSubRots();
          uVar27 = FastAddRots(fVar26 * 0.5,uVar27);
          FUN_00221188(auStack_f0,&stack0xfffffec0,&fStack_130);
          FUN_00221210(0x3f000000,auStack_f0,auStack_f0);
          hero._384_4_ = uVar27;
          TurnWithCameraCheck(DAT_0015ed64 * 0.04,DAT_0015ed64 * 0.2,momentumMultiplyer * 6.2831855,
                              0);
          uStack_d0 = hero._356_4_;
          FUN_00270728((float)hero._400_4_ * momentumMultiplyer,DAT_0015ed70 * 5.0,&uStack_d0);
          FUN_002211b8(0x13f430,auStack_f0,0x13f3d0);
          iVar12 = FUN_00222160(hero._2728_4_);
          FUN_00221460(*(float *)(&DAT_001c4130 + iVar12 * 4) * 0.5,0x13f430,0x13f430);
        }
        goto LAB_0023c3f8;
      }
    }
    break;
  case HERO_STATE_ATTACK_BOUNCE:
    if ((hero._2648_4_ == 0) && (hero._2644_4_ == 0)) {
      iVar12 = FUN_00220e30(4);
      if ((int)hero._408_4_ < iVar12) {
        FUN_002351d0(0x41300000,0x3f5f66f3,0xbf800000);
      }
    }
    else {
      hero._384_4_ = hero._2652_4_;
      TurnWithCameraCheck(fGpffff8164 * 0.05,fGpffff8164 * 0.2,momentumMultiplyer * 15.009831,0);
    }
    iVar12 = FUN_00220e30(10);
    hero._400_4_ = 0;
    iVar18 = FUN_00220e30(8);
    iVar18 = iVar12 + iVar18;
    if ((iVar12 < (int)hero._408_4_) && ((int)hero._408_4_ < iVar18)) {
      hero._400_4_ = fGpffff816c * 18.0;
    }
    iVar13 = FUN_00220e30(8);
    if (hero._408_4_ == iVar13) {
      FUN_00277400(hero.pMoby,0x1409c0);
      FUN_00277428(0x1409c0,0x30,2);
      FUN_00277428(0x1409c0,0x17,4);
      FUN_00277428(0x1409c0,0xc,6);
    }
    uVar15 = 5;
    if ((int)hero._408_4_ <= iVar18) {
      uVar15 = 0;
    }
    FUN_00277508(0x1409c0,uVar15);
    if (iVar12 < (int)hero._408_4_) {
      FUN_002326e8(fGpffff8170 * 190.0,fGpffff8170 * 90.0);
    }
    if (hero._2648_4_ == 0) {
      FUN_00232738(0x47c34f80);
    }
    else {
      FUN_00232738(hero._2652_4_);
    }
    if ((((hero.state == HERO_STATE_ATTACK_BOUNCE) && (iVar12 < (int)hero._408_4_)) &&
        (iVar12 = FUN_00220e30(4), uVar27 = hero._4240_4_, (int)hero._408_4_ < iVar18 + iVar12)) &&
       (hero._4240_4_ != 0)) {
      fStack_110 = (float)FUN_002216f8(hero.rot.y);
      uVar28 = 0x3f0ccccd;
      fStack_110 = fStack_110 + fStack_110;
      fStack_10c = (float)FUN_00221710(hero.rot.y);
      fStack_10c = fStack_10c + fStack_10c;
      uStack_108 = 0x3fa66666;
      FUN_0026e808(0x40400000,&stack0xfffffec0,hero.pMoby,0x30000,&fStack_110);
      fVar26 = hero.rot.y;
      uStack_128 = (float)CONCAT22(*(undefined2 *)(uVar27 + 0xa6),0x300);
      fStack_100 = (float)FUN_002216f8(hero.rot.y);
      fStack_100 = fStack_100 * 0.8;
      fStack_fc = (float)FUN_00221710(fVar26);
      fStack_fc = fStack_fc * 0.8;
      uStack_f8 = uVar28;
      FUN_00221188(&fStack_100,&fStack_100,0x13f3d0);
      uVar15 = FUN_00214468(0x3f4ccccd,&fStack_100,0,uVar27,&stack0xfffffec0);
      FUN_00236cb8(uVar27,uVar15);
      uVar22 = FastAddRots(hero.rot.y,0xbf5f66f3);
      fStack_100 = (float)FUN_002216f8(uVar22);
      fStack_100 = fStack_100 * 0.8;
      fStack_fc = (float)FUN_00221710(uVar22);
      fStack_fc = fStack_fc * 0.8;
      uStack_f8 = uVar28;
      FUN_00221188(&fStack_100,&fStack_100,0x13f3d0);
      uVar15 = FUN_00214468(0x3f4ccccd,&fStack_100,0,hero.pMoby,&stack0xfffffec0);
      FUN_00236cb8(uVar27,uVar15);
      uVar22 = FastAddRots(hero.rot.y,0x3f5f66f3);
      fStack_100 = (float)FUN_002216f8(uVar22);
      fStack_100 = fStack_100 * 0.8;
      fStack_fc = (float)FUN_00221710(uVar22);
      fStack_fc = fStack_fc * 0.8;
      uStack_f8 = uVar28;
      FUN_00221188(&fStack_100,&fStack_100,0x13f3d0);
      uVar15 = FUN_00214468(0x3f4ccccd,&fStack_100,0,uVar27,&stack0xfffffec0);
      FUN_00236cb8(uVar27,uVar15);
    }
    iVar12 = FUN_00220e30(10);
    if (iVar12 < (int)hero._408_4_) {
      FUN_00236a68(0x406ccccd,0);
    }
    FUN_00232978(1);
    if (hero._782_2_ != 0) {
      uVar15 = 0x13f460;
      fVar26 = 24.0;
      goto LAB_0023c2f4;
    }
    fVar26 = 54.0;
    uVar15 = 0x13f430;
    fVar29 = DAT_0015ed70;
    goto LAB_0023c3b4;
  case HERO_STATE_ROCKET_STOMP:
  case HERO_STATE_DEATHSAND_SINK:
    FUN_00270728(0,DAT_0015ed70 * 24.0);
    fVar26 = (float)FUN_002216f8(hero._2664_4_);
    hero._224_4_ = fVar26 * (float)hero._404_4_;
    fVar26 = (float)FUN_00221710(hero._2664_4_);
    hero._228_4_ = fVar26 * (float)hero._404_4_;
    if (0.0 < (float)hero._732_4_) {
      hero._232_4_ = (float)hero._280_4_ - DAT_0015ed70 * 25.0;
    }
    else {
      hero._232_4_ = 0;
    }
    hero._384_4_ = FastAddRots(hero._2664_4_,0x40490fdb);
    TurnWithCameraCheck(DAT_0015ed64 * 0.05,DAT_0015ed64 * 0.2,momentumMultiplyer * 15.009831,0);
    goto LAB_0023c3f8;
  case HERO_STATE_GLOVE_ATTACK:
    hero._400_4_ = 0;
    FUN_002326e8(DAT_0015ed70 * 30.0,DAT_0015ed70 * 30.0);
    FUN_00249238(hero._404_4_,0x13f430,0x13f430);
    iVar12 = FUN_00220e30(0xc);
    fVar29 = momentumMultiplyer * 5.7;
    fVar26 = DAT_0015ed70 * 70.0;
    iVar18 = FUN_00220e30(0x21);
    if ((int)hero._408_4_ < iVar12) {
      uStack_d8 = FUN_00249110(0x13f430);
      FUN_00270728(fVar29,fVar26,&uStack_d8);
      FUN_002491b8(uStack_d8,0x13f430,0x13f430);
    }
    else if (iVar18 < (int)hero._408_4_) {
      FUN_00248b68(hero._1200_4_,0x13f430,0x13f430);
      fVar26 = (float)FUN_00249110(0x13f430);
      if (fVar26 < 0.0) {
        hero._1208_4_ = 0x3f800000;
      }
    }
    if (((float)hero._1208_4_ != 0.0) && (hero._782_2_ != 0)) {
      fStack_130 = (float)FUN_002216f8(hero.rot.y);
      fStack_12c = (float)FUN_00221710(hero.rot.y);
      uStack_128 = 0.0;
      FUN_0026e808(0x3f800000,&fStack_110,hero.pMoby,0x30000,&fStack_130);
      FUN_00214468(0x3f4ccccd,&stack0xfffffec0,0x10,hero.pMoby,&fStack_110);
    }
    if (((float)hero._1208_4_ == 0.0) || (hero._782_2_ != 0)) goto LAB_0023c3f8;
    if (hero._1220_4_ == 0) {
      DAT_00167260 = 0x3e4ccccd;
      DAT_00167268 = FUN_00220e30(0x28);
    }
    hero._1220_4_ = hero._1220_4_ + 1;
    fVar26 = (float)hero._232_4_;
    break;
  case HERO_STATE_GRAPPLE_SHOOT:
    hero._400_4_ = 0;
    if (hero._2648_4_ == 0) {
      FUN_002351d0(0x41300000,0x3f5f66f3,0xbf800000);
      fVar26 = DAT_0015ed70;
    }
    else {
      hero._384_4_ = hero._2652_4_;
      TurnWithCameraCheck(DAT_0015ed64 * 0.04,DAT_0015ed64 * 0.2,momentumMultiplyer * 15.009831,0);
      fVar26 = fGpffff8170;
    }
    FUN_002326e8(fVar26 * 30.0,fVar26 * 35.0);
    FUN_00232738(0x47c34f80);
    if (hero._782_2_ != 0) {
      hero._232_4_ = (float)hero._264_4_ - fGpffff8170 * 25.0;
      FUN_00232820();
      goto LAB_0023c3f8;
    }
    fVar26 = (float)hero._232_4_ - fGpffff8170 * 54.0;
    break;
  case HERO_STATE_SLIDE:
    if (hero._4834_1_ == '\0') {
      FUN_00233850(0x3f000000,momentumMultiplyer + momentumMultiplyer);
    }
    else {
      FUN_00233850(0x3f333333,momentumMultiplyer * 0.0);
    }
    FUN_00236a68(0x406ccccd,0);
    FUN_00231f70(0x3f800000,0);
    FUN_002326e8(DAT_0015ed70 * 12.6,DAT_0015ed70 * 12.6);
    FUN_00221170(0x13f430);
    FUN_00236678(DAT_0015ed70 * 12.6);
    if (hero._782_2_ == 0) {
      FUN_00248b68(fGpffff8170 * 54.0,0x13f430,0x13f430);
    }
    else {
      FUN_00248b68(fGpffff8170 * 25.0,0x13f430,0x13f450);
      FUN_00232820();
    }
    fVar26 = (float)hero._232_4_;
    if (((hero.pMoby)->field_0x70 & 2) != 0) {
      if ((hero.pMoby)->field_0x52 == '6') {
        uVar15 = FUN_00226f10(0);
        iVar12 = FUN_00220e30(5);
        FUN_00247a90((float)iVar12,uVar15,0);
      }
      goto LAB_0023c3f8;
    }
    break;
  case HERO_STATE_VEHICLE:
    if (Level == 0xf) {
      FUN_00236798(2,hero.pMoby,0x1d);
      uVar17 = uGpffff8184;
    }
    else {
      FUN_00236798(2,hero.pMoby,6);
      uVar17 = Level;
    }
    if (uVar17 != 0xf) {
      uVar27 = 0xbe800000;
      FUN_0022b140(4,2);
      fVar26 = -0.7;
      FUN_0026c9c8(uVar27,0x3e800000);
      FUN_0026c9c8(uVar27,0x3e800000);
      FUN_0026c9c8(0xbdcccccd,0x3ecccccd);
      FUN_00221210(0x3f666666,&fStack_130,0x13f450);
      fVar29 = (float)FUN_0026c9c8(momentumMultiplyer * fVar26,momentumMultiplyer * 0.7);
      fStack_130 = fStack_130 + fVar29;
      fVar26 = (float)FUN_0026c9c8(momentumMultiplyer * fVar26,momentumMultiplyer * 0.7);
      fStack_12c = fStack_12c + fVar26;
      fVar26 = (float)FUN_0026c9c8(momentumMultiplyer,momentumMultiplyer + momentumMultiplyer);
      uStack_128 = uStack_128 + fVar26;
      uVar27 = FUN_0026c9c8(0x4713a800,0x4793a800);
      FUN_00286cb0(uVar27,&stack0xfffffec0,&fStack_130);
    }
    fVar26 = (float)FUN_002212e8(0x13f440);
    if (momentumMultiplyer * 0.5 < fVar26) {
      hero._384_4_ = FUN_002217c0(hero._240_4_,hero._244_4_);
    }
    else {
      hero._384_4_ = hero.rot.y;
    }
    fVar29 = hero.rot.y;
    uVar27 = 0x3e4ccccd;
    TurnWithCameraCheck(fVar26 * 0.125 * DAT_0015ed64,DAT_0015ed64 * 0.2,
                        momentumMultiplyer * 4.1887903,0);
    fVar26 = (float)FastDiffRots(hero.rot.y,fVar29);
    FUN_00221170(0x13f430);
    FUN_00236678(DAT_0015ed70 * 5.0);
    hero._232_4_ = DAT_0015ed70 * -40.0;
    fVar29 = (float)hero._264_4_ - DAT_0015ed70 * 50.0;
    if (fVar29 <= (float)hero._232_4_) {
      hero._232_4_ = fVar29;
    }
    if (momentumMultiplyer * 1.3962634 < fVar26) {
      fVar26 = momentumMultiplyer * 1.3962634;
    }
    fVar26 = fVar26 * 9.0;
    TurnTowardAngle(fVar26 * 0.5,0x3be56042,0x3e2e147b,momentumMultiplyer * 1.2217305,&hero.rot.x,
                    (float *)&hero.field_0x9e4,0);
    iVar12 = FUN_00220e30(100);
    if (iVar12 < (int)hero._408_4_) {
      TurnTowardAngle(-(float)hero._2516_4_,fGpffff8164 * 0.035,fGpffff8164 * 0.3,
                      momentumMultiplyer * 1.9198622,&hero.rot.z,(float *)&hero.field_0x9e8,0);
    }
    FUN_0022b5e0(0x3c1374bc,0x3e6147ae);
    FUN_0022b5f8(0x3d23d70a,uVar27);
    FUN_0022b610(0x3ca3d70a,uVar27);
    DAT_0017ac18 = fVar26 * 2.1;
    DAT_0017ac10 = fVar26 * 3.5;
    fVar26 = (float)hero._232_4_;
    break;
  case HERO_STATE_IDLEUNDER:
  case HERO_STATE_CHARGEUNDER:
  case HERO_STATE_SWIMSURF:
    if (hero.state == HERO_STATE_SWIMSURF) {
      FUN_00236798(5,hero.pMoby,0x13);
    }
    else {
      if (((hero._8748_4_ != -1) &&
          ((moby *)(&PTR_DAT_0013e5d8)[hero._8748_4_ * 0x1c] == hero.pMoby)) &&
         ((&DAT_0013e5c4)[hero._8748_4_ * 0x70] != '\0')) {
        FUN_002a1348(hero._8748_4_);
      }
      hero._8748_4_ = 0xffffffff;
    }
    if (hero._2314_2_ != 0) {
      FastDecTimer((short *)&hero.field_0x90a);
      iVar12 = (int)((uint)(ushort)hero._2314_2_ << 0x10) >> 0x12;
      if (8 < iVar12) {
        iVar12 = 8;
      }
      FUN_0022b140(iVar12,0);
    }
    if (((hero.state == HERO_STATE_IDLEUNDER) && (hero._2716_4_ == 0)) &&
       ((0.0 < (float)hero._2728_4_ && ((float)hero._2728_4_ < 10.0)))) {
      FUN_0022b140(4,1);
    }
    if (((hero.state == HERO_STATE_CHARGEUNDER) && (hero.field8168_0x2090 == 0x35)) &&
       (iVar12 = FUN_00220e30(0xf), (int)hero._408_4_ < iVar12)) {
      iVar12 = FUN_00220e30(0x14);
      FUN_0022b140((iVar12 - hero._408_4_) / 3 + 1,1);
    }
    if (hero.field8166_0x2088 == 1) {
      if (hero._408_4_ == 1) {
        FUN_0022b3a8(3,0x10,0);
        if (PTR_DAT_001612d0 != (undefined *)0x0) {
          FUN_002b82a8(hero.pos.x,hero.pos.z,0x3ecccccd,0xbe99999a,PTR_DAT_001612d0,uGpffffa6d8,0);
        }
        hero._2314_2_ = FUN_00220e30(0x46);
      }
      iVar18 = hero._2272_4_ + 1;
      hero._2272_4_ = iVar18;
      iVar12 = FUN_00220e30(0x28);
      if (iVar12 < iVar18) {
        hero.field8166_0x2088 = 0;
      }
    }
    fVar26 = 0.0;
    fVar24 = g_Pad.analog[0xb];
    if (g_Pad.analog[0xb] <= g_Pad.analog[10]) {
      fVar24 = g_Pad.analog[10];
    }
    fVar25 = DAT_0015ed64 * 0.2;
    fVar23 = DAT_0015ed64 * 0.015;
    fVar29 = momentumMultiplyer * 0.6981317 +
             (momentumMultiplyer * 1.2217305 - momentumMultiplyer * 0.6981317) * fVar24;
    if (((g_Pad.bits & (PAD_SQUARE|PAD_CROSS)) == PAD_SQUARE) || (hero.field8166_0x2088 == 1)) {
      fVar26 = g_Pad.analog[0xb] * 1.5;
      if (1.0 < g_Pad.analog[0xb] * 1.5) {
        fVar26 = 1.0;
      }
      if (fVar26 < 0.2) {
        fVar26 = 0.2;
      }
      if (g_Pad.term_id != 0x79) {
        hero._2304_2_ = 0;
        hero._2306_2_ = hero._2306_2_ + 1;
        iVar12 = FUN_00220e30(0x14);
        fVar26 = ((float)(int)(short)hero._2306_2_ * 0.5) / (float)iVar12 + 0.5;
        if (1.0 < fVar26) {
          fVar26 = 1.0;
        }
      }
      if ((hero.field8166_0x2088 == 1) && (fVar26 < 0.35)) {
        fVar26 = 0.35;
      }
      fVar26 = fVar26 * 1.3613569;
    }
    else if ((g_Pad.bits & PAD_CROSS) == 0) {
      hero._2306_2_ = 0;
      hero._2304_2_ = 0;
    }
    else {
      fVar26 = g_Pad.analog[10] * 1.5;
      if (1.0 < g_Pad.analog[10] * 1.5) {
        fVar26 = 1.0;
      }
      if (fVar26 < 0.2) {
        fVar26 = 0.2;
      }
      if (g_Pad.term_id != 0x79) {
        hero._2306_2_ = 0;
        hero._2304_2_ = hero._2304_2_ + 1;
        iVar12 = FUN_00220e30(0x14);
        fVar26 = ((float)(int)(short)hero._2304_2_ * 0.5) / (float)iVar12 + 0.5;
        if (1.0 < fVar26) {
          fVar26 = 1.0;
        }
      }
      if ((float)(int)hero._8864_4_ < 1500.0) {
        fVar26 = 1.0;
      }
      fVar26 = fVar26 * -1.3613569;
    }
    if ((g_Pad.bits & PAD_CROSS) == 0) {
      hero._2316_2_ = 0;
      hero._2318_2_ = 0;
    }
    else {
      hero._2318_2_ = hero._2318_2_ + 1;
      if (0.75 < g_Pad.analog[10]) {
        sVar11 = hero._2316_2_ + 1;
        hero._2316_2_ = sVar11;
        sVar10 = FUN_00220e30(0x5a);
        uVar27 = DAT_0015eea4;
        if ((sVar10 < sVar11) && (uVar27 = uGpffff82a4, DAT_001418a0 != -1)) {
          DAT_001418a0 = DAT_001418a0 + 1;
          uVar27 = DAT_0015eea4;
        }
        iVar12 = FUN_00220e30(uVar27);
        uVar17 = uGpffff8184;
        if ((int)(uint)DAT_001418a2 < iVar12 / 600) {
          iVar12 = FUN_00220e30(uGpffff82a4);
          DAT_001418a2 = (ushort)(iVar12 / 600);
          uVar17 = Level;
        }
        DAT_001418a4 = DAT_001418a4 | 1 << (uVar17 & 0x1f) | 0x80000000;
      }
      else {
        hero._2316_2_ = 0;
      }
    }
    if (((g_Pad.bitsOn & PAD_CROSS) != 0) &&
       (iVar18 = (int)PTR_DAT_0015f5cc - hero._2324_4_, iVar12 = FUN_00220e30(0x46),
       hero._2324_4_ = uGpffff89cc, iVar18 < iVar12)) {
      hero._2320_4_ = hero._2320_4_ + 1;
      hero._2324_4_ = PTR_DAT_0015f5cc;
    }
    uVar6 = hero._2318_2_;
    sVar11 = FUN_00220e30(0x46);
    if (sVar11 < (short)uVar6) {
      hero._2320_4_ = 0;
    }
    if ((g_Pad.bits & PAD_SQUARE) != 0) {
      hero._2320_4_ = 0;
    }
    if (hero.state == HERO_STATE_CHARGEUNDER) {
      fVar26 = 0.0;
    }
    TurnTowardAngle(fVar26,fVar23,fVar25,fVar29,&hero.rot.z,(float *)&hero.field_0x8e8,0);
    fVar26 = FastSubRots();
    FUN_00231f70(0x3f800000,0);
    TurnWithCameraCheck(DAT_0015ed64 * 0.007,DAT_0015ed64 * 0.08,momentumMultiplyer * 5.2359877,0);
    hero._2284_4_ = hero._388_4_;
    FastDecTimer(0x13fc44);
    if (hero.field8166_0x2088 == 1) {
      fVar29 = 6.0;
code_r0x00238004:
      hero._400_4_ = fGpffff816c * fVar29;
    }
    else {
      if (hero.state != HERO_STATE_SWIMSURF) {
        fVar29 = 3.0;
        goto code_r0x00238004;
      }
      if ((g_Pad.bits & (PAD_R1|PAD_R2)) == 0) {
        hero._400_4_ = fGpffff816c * 7.0 * 0.4;
      }
      else {
        hero._400_4_ = fGpffff816c * 7.0;
      }
    }
    fVar29 = (float)hero._8860_4_;
    if ((((g_Pad.bits & (PAD_SQUARE|PAD_CROSS)) != 0) || (hero.field8166_0x2088 == 1)) &&
       ((float)hero._8860_4_ < 1.0)) {
      fVar29 = 1.0;
    }
    if (0.15 < (float)hero._8860_4_) {
      fVar23 = 0.35;
      if (hero.state == HERO_STATE_SWIMSURF) {
        fVar23 = 0.4;
      }
      if (fVar29 < fVar23) {
        fVar29 = fVar23;
      }
    }
    if ((hero.state != HERO_STATE_SWIMSURF) || ((g_Pad.bits & (PAD_R1|PAD_R2)) == 0)) {
      hero._400_4_ = (float)hero._400_4_ * fVar29;
    }
    lVar14 = FastDecTimer(0x13fc40);
    if (lVar14 != 0) {
      FUN_002645a8(hero.pMoby,4,&stack0xfffffec0);
      fStack_11c = 0.0;
      uStack_118 = 0;
      uStack_117 = 0;
      uStack_116 = 0;
      fStack_114 = 0.0;
      fStack_120 = 0.4;
      FUN_002215e0(&fStack_120,&fStack_120,&(hero.pMoby)->rMtx);
      FUN_00221188(&stack0xfffffec0,&stack0xfffffec0,&fStack_120);
      fStack_130 = hero._256_4_;
      fStack_12c = hero._260_4_;
      uStack_128 = (float)hero._264_4_;
      fStack_124 = (float)hero._268_4_;
      FUN_00221410(momentumMultiplyer * 1.5,&fStack_120,&fStack_120);
      FUN_00221188(&fStack_130,&fStack_130,&fStack_120);
      uStack_128 = uStack_128 + momentumMultiplyer + momentumMultiplyer;
      FUN_002840e0(0x46c4e000,0xbf800000,&stack0xfffffec0,&fStack_130);
      iVar12 = FUN_0026c930(100);
      if ((float)iVar12 < 40.0) {
        uVar15 = FUN_00220e30(4);
        uVar27 = 0xb;
      }
      else {
        uVar15 = FUN_00220e30(0x28);
        uVar27 = 0x5a;
      }
      uVar16 = FUN_00220e30(uVar27);
      hero._2288_4_ = FUN_0026c970(uVar15,uVar16);
    }
    fVar29 = DAT_0015ed70;
    if (hero.state == HERO_STATE_SWIMSURF) {
      sVar11 = FastDecTimer((short *)&hero.field_0x8f8);
      uVar27 = hero._4480_4_;
      if (((sVar11 != 0) && (hero._4480_4_ != 0)) && (*(short *)(hero._4480_4_ + 0xa6) == 0x261)) {
        uVar28 = 0;
        uVar20 = 0;
        uVar17 = 0;
        do {
          FUN_002645a8(uVar27,uVar20 + ((int)(uVar20 + uVar17) >> 1) * -2,&stack0xfffffec0);
          fStack_11c = 0.0;
          uStack_118 = 0;
          uStack_117 = 0;
          uStack_116 = 0;
          fStack_114 = 0.0;
          fStack_120 = -0.15;
          FUN_002215e0(&fStack_120,&fStack_120,&(hero.pMoby)->rMtx);
          FUN_00221188(&stack0xfffffec0,&stack0xfffffec0,&fStack_120);
          FUN_0026c9c8(uVar28,0x3cf5c28f);
          FUN_0026c9c8(uVar28,0x3cf5c28f);
          FUN_0026c9c8(uVar28,0x3cf5c28f);
          fStack_130 = hero._256_4_;
          fStack_12c = hero._260_4_;
          uStack_128 = (float)hero._264_4_;
          fStack_124 = (float)hero._268_4_;
          uVar20 = uVar20 + 1;
          FUN_00277bf0(momentumMultiplyer * -0.75,hero.rot.y,hero.rot.z,&fStack_130,&fStack_130);
          iVar12 = FUN_00220e30(5);
          hero._2296_2_ =
               FUN_00222160(((momentumMultiplyer * 7.0 - (float)hero._404_4_) /
                            (momentumMultiplyer * 7.0)) * (float)iVar12);
          uVar22 = FUN_0026c9c8(0x45c4e000,0x4613a800);
          FUN_002840e0(uVar22,0xbf800000,&stack0xfffffec0,&fStack_130);
          uVar17 = uVar20 >> 0x1f;
        } while ((int)uVar20 < 4);
      }
      fVar29 = fGpffff8170;
      if (hero.state != HERO_STATE_SWIMSURF) goto LAB_0023842c;
      FUN_002326e8(fGpffff8170 * 13.0,fGpffff8170 * 8.0);
    }
    else {
LAB_0023842c:
      FUN_002326e8(fVar29 * 7.0,fVar29 * 4.0);
    }
    uVar27 = FastAddRots(-hero.rot.z,0);
    if (hero.state == HERO_STATE_SWIMSURF) {
      FUN_00277b50(hero._404_4_,hero.rot.y,uVar27,0x13f430);
    }
    else if (hero.state == HERO_STATE_IDLEUNDER) {
      fVar29 = (float)FUN_0022a718(0x17c440,0x1e);
      fVar29 = (float)hero._404_4_ * fVar29 * 5.0;
      if (((hero.field8168_0x2090 == 0x35) &&
          (iVar12 = FUN_00220e30(0xf), (int)hero._408_4_ < iVar12)) && (fVar29 < fGpffff816c * 4.5))
      {
        fVar29 = fGpffff816c * 4.5;
      }
      FUN_00277b50(fVar29,hero.rot.y,uVar27);
    }
    else if (hero.state == HERO_STATE_CHARGEUNDER) {
      uStack_e0 = FUN_002212e8(0x13f4a0);
      if (hero.field8168_0x2090 == 0x35) {
        FUN_00270728(0,DAT_0015ed70 * 8.0,&uStack_e0);
      }
      else {
        FUN_00270728(0,DAT_0015ed70 * 4.0,&uStack_e0);
      }
      FUN_00221410(uStack_e0,0x13f4a0,0x13f4a0);
      hero._224_4_ = hero._336_4_;
      hero._228_4_ = hero._340_4_;
      hero._232_4_ = hero._344_4_;
      hero._236_4_ = hero._348_4_;
    }
    FUN_00232978(0);
    fVar29 = (float)FUN_002216f8(uVar27);
    fVar29 = (float)hero._2284_4_ * fVar29 * -7.0;
    TurnTowardAngle(fVar29,0x3be56042,0x3e2e147b,momentumMultiplyer * 1.2217305,&hero.rot.x,
                    (float *)&hero.field_0x8e4,0);
    FUN_0022b5e0(0x3c1374bc,0x3e6147ae);
    FUN_0022b5f8(0x3d23d70a,0x3e4ccccd);
    FUN_0022b610(0x3ca3d70a,0x3e4ccccd);
    DAT_0017ac14 = fVar26 * 47.0;
    DAT_0017ac18 = fVar29 * 1.5;
    DAT_0017ac10 = fVar29 * 1.4;
    if (0.87266463 < DAT_0017ac14) {
      DAT_0017ac14 = 0.87266463;
    }
    else if (DAT_0017ac14 < -0.87266463) {
      DAT_0017ac14 = -0.87266463;
    }
    DAT_0017ae24 = fVar26 * 40.0;
    DAT_0017ae28 = fVar29 * 1.1;
    DAT_0017af14 = 0x3cf5c28f;
    DAT_0017af18 = 0x3e6147ae;
    DAT_0017ae64 = 0x3cf5c28f;
    DAT_0017ae68 = 0x3e6147ae;
    fVar26 = (float)hero._232_4_;
    DAT_0017aed4 = DAT_0017ae24;
    DAT_0017aed8 = DAT_0017ae28;
    break;
  case HERO_STATE_IDLESURF:
  case HERO_STATE_BOLT_CRANK:
    fVar26 = fGpffff816c;
    if (hero.state == HERO_STATE_BOLT_CRANK) {
      FUN_0022ac40(0xf,0x1e);
      fVar26 = momentumMultiplyer;
    }
    if (fVar26 * 1.5 < (float)hero._356_4_) {
      FUN_0022af48(4,0xc);
    }
    if ((hero.state == HERO_STATE_IDLESURF) && (momentumMultiplyer < (float)hero._356_4_)) {
      FUN_0022ad38(0,1);
    }
    if (hero._2314_2_ != 0) {
      hero._2314_2_ = hero._2314_2_ - 1;
      iVar12 = (int)((uint)(ushort)hero._2314_2_ << 0x10) >> 0x13;
      if (6 < iVar12) {
        iVar12 = 6;
      }
      FUN_0022b140(iVar12,0);
    }
    hero._2704_4_ = 0x3f19999a;
    FUN_00231f70(momentumMultiplyer * 3.0,0);
    if ((g_Pad.handsOffStick == 0) &&
       (fVar26 = momentumMultiplyer * 3.0 * 0.5, (float)hero._400_4_ < fVar26)) {
      hero._400_4_ = fVar26;
    }
    TurnWithCameraCheck(DAT_0015ed64 * 0.007,DAT_0015ed64 * 0.08,momentumMultiplyer * 5.2359877,0);
    FastDecTimer(0x13f9e8);
    if (hero.state == HERO_STATE_IDLESURF) {
      if ((g_Pad.handsOffStick != 0) && (hero._1688_4_ != 0)) {
        hero._400_4_ = fGpffff816c * 3.0;
      }
      fVar26 = (float)FUN_00221128(hero._392_4_);
      if (0.7853982 < fVar26) {
        hero._400_4_ = 0;
      }
      FUN_002326e8(DAT_0015ed70 * 4.0,DAT_0015ed70 * 5.0);
      fVar26 = (float)FUN_0022a718(0x17c440,0x1e);
      fVar29 = (float)hero._404_4_ * fVar26 * 5.5;
      fVar26 = (float)FUN_002216f8(hero.rot.y);
      hero._224_4_ = fVar26 * fVar29;
      fVar26 = (float)FUN_00221710(hero.rot.y);
      hero._228_4_ = fVar26 * fVar29;
      hero._232_4_ = 0;
    }
    else {
      hero._404_4_ = 0;
      FUN_00221170(0x13f430);
    }
    fVar26 = fGpffff8170;
    if ((((hero.state == HERO_STATE_IDLESURF) && (hero._2716_4_ == 0)) &&
        (0.0 < (float)hero._2728_4_)) && (fVar26 = DAT_0015ed70, (float)hero._2728_4_ < 10.0)) {
      FUN_0022b140(4,1);
      fVar26 = DAT_0015ed70;
    }
    FUN_00236678(fVar26 * 4.2);
    goto LAB_00238d04;
  case 0x40:
  case HERO_STATE_JUMP_TO_POS:
    FUN_00221170(0x13f430);
    goto LAB_0023c3f8;
  case 0x53:
  case 0x57:
  case 0x59:
    fVar26 = 12.6;
    FUN_00236a68(0x406ccccd,0);
    FUN_00231f70(0x3f800000,0);
    hero._400_4_ = 0;
    FUN_002326e8(0,DAT_0015ed70 * fVar26);
    FUN_00221170(0x13f430);
    FUN_00236678(DAT_0015ed70 * fVar26);
    FUN_00232978(0);
    if (hero._782_2_ != 0) {
      fVar26 = 25.0;
      uVar15 = 0x13f470;
      goto LAB_0023c2f4;
    }
    uVar15 = 0x13f430;
    fVar26 = fGpffff8170;
    fVar29 = 54.0;
    goto LAB_0023c3b4;
  case 0x54:
    fVar26 = (float)FastDiffRots(hero.rot.y,hero._384_4_);
    FUN_00231f70(momentumMultiplyer * 1.5,0);
    fVar29 = momentumMultiplyer * 1.5 * 0.55;
    if ((float)hero._400_4_ < fVar29) {
      hero._400_4_ = fVar29;
    }
    fVar26 = 1.0 - fVar26 * 0.3;
    if (fVar26 < 0.0) {
      fVar26 = 0.0;
    }
    TurnWithCameraCheck(DAT_0015ed64 * 0.035 * ((float)hero._8860_4_ + 0.35),DAT_0015ed64 * 0.1,
                        momentumMultiplyer * 2.268928 * ((float)hero._8860_4_ + 0.35),0);
    FUN_002326e8(DAT_0015ed70 * 7.5 * fVar26,DAT_0015ed70 * 8.5);
    if ((hero._952_2_ == 0) || (hero._776_2_ != 0)) {
      FUN_00232738(0x47c34f80);
    }
    else {
      FUN_00232738(hero._384_4_);
    }
    FUN_00232978(1);
    if (hero._782_2_ != 0) {
LAB_0023c2e4:
      uVar15 = 0x13f470;
      fVar26 = 25.0;
      goto LAB_0023c2f4;
    }
    fVar26 = 54.0;
    uVar15 = 0x13f430;
    fVar29 = DAT_0015ed70;
    goto LAB_0023c3b4;
  case 0x55:
    FUN_00231f70(momentumMultiplyer * 1.5,0);
    fVar26 = fGpffff8170;
    if (hero._452_4_ == 0) {
      FUN_00234b40();
      fVar26 = DAT_0015ed70;
    }
    FUN_00248b68(fVar26 * 21.0,0x13f430,0x13f430);
    fVar26 = momentumMultiplyer * -15.0;
    if (momentumMultiplyer * -15.0 <= (float)hero._232_4_) goto LAB_0023c3f8;
    break;
  case 0x56:
    vec_06.z = (float)in_stack_fffffec4;
    vec_06.x = (float)in_stack_fffffec0;
    vec_06.y = (float)in_stack_fffffec8;
    vec_06.w = in_stack_fffffecc;
    fVar26 = (float)vector_length(vec_06);
    if (hero._782_2_ == 0) {
      fVar23 = -0.07999998;
      fVar29 = DAT_0015ed60;
    }
    else {
      fVar23 = -0.00999999;
      fVar29 = fGpffff8160;
    }
    FUN_00221510(fVar29 * fVar23 * fVar26 + fVar26,0x13f430,0x13f430);
    hero._232_4_ = 0;
    fVar26 = DAT_0015ed70;
    if (hero._782_2_ == 0) goto LAB_0023c3c8;
LAB_0023c3a4:
    uVar15 = 0x13f460;
    fVar29 = 24.0;
    goto LAB_0023c3b4;
  case 0x58:
    hero._400_4_ = momentumMultiplyer * 5.5;
    hero._384_4_ = hero._748_4_;
    FUN_00234358(DAT_0015ed70 * 25.0);
    uVar15 = 0x13f470;
    fVar26 = DAT_0015ed70;
    fVar29 = 18.0;
    goto LAB_0023c3b4;
  case HERO_STATE_NPC:
  case HERO_STATE_WALK_TO_POS:
    FUN_00221170(0x13f430);
    fVar26 = (float)hero._232_4_;
    break;
  case HERO_STATE_SKID_TO_POS:
    FUN_002211b8(&stack0xfffffec0,0x140990,0x13f3d0);
    hero._384_4_ = FUN_002217c0(in_stack_fffffec0,in_stack_fffffec4);
    vec_05.z = (float)in_stack_fffffec4;
    vec_05.x = (float)in_stack_fffffec0;
    vec_05.y = (float)in_stack_fffffec8;
    vec_05.w = in_stack_fffffecc;
    fVar26 = (float)vector_length(vec_05);
    if (0.2 < fVar26) {
      hero._8860_4_ = 0x3f800000;
      hero._384_4_ = FUN_002217c0(in_stack_fffffec0,in_stack_fffffec4);
      fVar29 = DAT_0017c240;
      if (DAT_0017c244 <= fVar26) {
        fVar29 = DAT_0017c250;
      }
      hero._400_4_ = fVar29 * momentumMultiplyer;
      if (hero._8356_1_ == '\x03') {
        fVar29 = 1.5;
        fVar26 = fGpffff816c;
      }
      else {
        if (hero._8356_1_ != '\x01') goto LAB_0023bd90;
        fVar29 = 0.9;
        fVar26 = momentumMultiplyer;
      }
      hero._400_4_ = fVar26 * fVar29;
    }
    else {
      hero._8860_4_ = 0x3f000000;
      hero._384_4_ = hero._5708_4_;
      hero._400_4_ = 0;
    }
LAB_0023bd90:
    if (hero._8356_1_ == '\x03') {
      fVar29 = 0.3;
      fVar23 = 5.5850534;
      fVar25 = DAT_0015ed64 * 0.03;
      fVar26 = DAT_0015ed64;
LAB_0023be68:
      TurnWithCameraCheck(fVar25,fVar26 * fVar29,momentumMultiplyer * fVar23,0);
LAB_0023be88:
      fVar29 = fGpffff8170;
      if (hero._8356_1_ == '\0') {
        FUN_00235638();
        fVar29 = DAT_0015ed70;
      }
    }
    else {
      fVar26 = fGpffff8164;
      if (hero._8356_1_ == '\x01') {
        fVar29 = 0.3;
        fVar23 = 7.8539815;
        fVar25 = fGpffff8164 * 0.03;
        goto LAB_0023be68;
      }
      fVar29 = fGpffff8170;
      if (hero._8356_1_ == '\0') {
        if (hero.field8166_0x2088 == 1) {
          fVar29 = 0.15;
          fVar25 = fGpffff8164 * 0.016;
          fVar23 = 9.948377;
          goto LAB_0023be68;
        }
        DoTurn();
        goto LAB_0023be88;
      }
    }
    FUN_002326e8(fVar29 * 7.5 * 1.0,fVar29 * 8.5);
    FUN_00232738(0x47c34f80);
    if (hero._8356_1_ == '\0') {
      FUN_00232978(1);
    }
    if (hero._782_2_ != 0) {
      uVar15 = 0x13f450;
      fVar26 = 25.0;
      goto LAB_0023c2f4;
    }
    uVar15 = 0x13f430;
    fVar26 = 54.0;
    fVar29 = DAT_0015ed70;
    goto LAB_0023c3b4;
  case HERO_STATE_IDLE_TO_POS:
    FUN_002211b8(&stack0xfffffec0,0x140990,0x13f3d0);
    fVar26 = (float)FUN_002212a8(&stack0xfffffec0,0x13f4a0);
    if (fVar26 < 0.0) {
      FUN_00221170(0x13f4a0);
    }
    uVar15 = 0x13f430;
    FUN_00221170(0x13f430);
    FUN_00236678(DAT_0015ed70 * 12.0);
    FUN_00232978(0);
    if (hero._782_2_ != 0) {
      fVar26 = 25.0;
      uVar15 = 0x13f450;
      goto LAB_0023c2f4;
    }
    fVar26 = fGpffff8170;
    fVar29 = 54.0;
    goto LAB_0023c3b4;
  case HERO_STATE_DROWN:
  case HERO_STATE_SKATE:
    uStack_dc = FUN_002212e8(0x13f4a0);
    FUN_00270728(0,DAT_0015ed70 * 4.0,&uStack_dc);
    FUN_00221410(uStack_dc,0x13f4a0,0x13f4a0);
    hero._224_4_ = hero._336_4_;
    hero._228_4_ = hero._340_4_;
    hero._232_4_ = hero._344_4_;
    hero._236_4_ = hero._348_4_;
    lVar14 = FastDecTimer(0x13fc40);
    if (lVar14 == 2) {
      FUN_002645a8(hero.pMoby,4,&stack0xfffffec0);
      fStack_11c = 0.0;
      uStack_118 = 0;
      uStack_117 = 0;
      uStack_116 = 0;
      fStack_114 = 0.0;
      fStack_120 = 0.4;
      FUN_002215e0(&fStack_120,&fStack_120,&(hero.pMoby)->rMtx);
      FUN_00221188(&stack0xfffffec0,&stack0xfffffec0,&fStack_120);
      fStack_130 = hero._256_4_;
      fStack_12c = hero._260_4_;
      uStack_128 = (float)hero._264_4_;
      fStack_124 = (float)hero._268_4_;
      FUN_00221410(momentumMultiplyer * 1.5,&fStack_120,&fStack_120);
      FUN_00221188(&fStack_130,&fStack_130,&fStack_120);
      uStack_128 = uStack_128 + momentumMultiplyer + momentumMultiplyer;
      FUN_002840e0(0x46c4e000,0xbf800000,&stack0xfffffec0,&fStack_130);
      iVar12 = FUN_00220e30(0x28);
      if ((int)hero._408_4_ < iVar12) {
        uVar15 = FUN_00220e30(2);
        uVar16 = FUN_00220e30(5);
        iVar12 = FUN_0026c970(uVar15,uVar16);
        hero._2288_4_ = iVar12 + (int)hero._408_4_ / 5;
      }
      else {
        iVar12 = FUN_00220e30(0x46);
        if (iVar12 < (int)hero._408_4_) {
          uVar15 = FUN_00220e30(10);
          uVar16 = FUN_00220e30(0x14);
          hero._2288_4_ = FUN_0026c970(uVar15,uVar16);
        }
      }
    }
    if (0.0 < (float)hero._2300_4_) {
      hero._2300_4_ = 0;
    }
    FUN_00270728(-(momentumMultiplyer * 1.5),DAT_0015ed70 * 1.5,0x13fc4c);
    hero._232_4_ = hero._2300_4_;
    fVar26 = (float)hero._232_4_;
    break;
  case HERO_STATE_GET_HIT_UNDER:
    FUN_0022ac40(0xf,0x1e);
    hero._232_4_ = 0;
    vec_01.z = (float)in_stack_fffffec4;
    vec_01.x = (float)in_stack_fffffec0;
    vec_01.y = (float)in_stack_fffffec8;
    vec_01.w = in_stack_fffffecc;
    fVar26 = (float)vector_length(vec_01);
    FUN_00221510(DAT_0015ed60 * -0.07999998 * fVar26 + fVar26,0x13f430,0x13f430);
LAB_00238d04:
    FUN_00232978(0);
    FUN_00240c78();
    goto LAB_0023c3f8;
  case HERO_STATE_DEATH_FALL:
    iVar12 = 10 - (int)hero._408_4_ / 3;
    if (8 < iVar12) {
      iVar12 = 8;
    }
    FUN_0022b140(iVar12,0);
    hero._232_4_ = 0;
    vec_00.z = (float)in_stack_fffffec4;
    vec_00.x = (float)in_stack_fffffec0;
    vec_00.y = (float)in_stack_fffffec8;
    vec_00.w = in_stack_fffffecc;
    fVar26 = (float)vector_length(vec_00);
    FUN_00221510(DAT_0015ed60 * -0.07999998 * fVar26 + fVar26,0x13f430,0x13f430);
    FUN_00232978(0);
    goto LAB_0023c3f8;
  case HERO_STATE_DEATH_FALL|HERO_STATE_LOOK:
    hero._8364_1_ = 1;
    FUN_00270728(hero._2384_4_,DAT_0015ed70 * 8.726646,0x13fc98);
    FUN_00270728(hero._2388_4_,DAT_0015ed70 * 8.726646,0x13fc9c);
    FUN_0022a8d8(hero._2376_4_,hero._2380_4_,0);
    vec_02.z = (float)in_stack_fffffec4;
    vec_02.x = (float)in_stack_fffffec0;
    vec_02.y = (float)in_stack_fffffec8;
    vec_02.w = in_stack_fffffecc;
    fVar26 = (float)vector_length(vec_02);
    FUN_00221510(DAT_0015ed60 * -0.100000024 * fVar26 + fVar26,0x13f430,0x13f430);
LAB_0023b034:
    FUN_00248b68(hero._2368_4_,0x13f430,0x13f430);
    fVar23 = (float)FUN_00249110(0x13f430);
    fVar29 = -(momentumMultiplyer * 50.0);
LAB_0023b064:
    fVar26 = (float)hero._232_4_;
    if (fVar23 < fVar29) {
LAB_0023b074:
      FUN_002491b8(fVar29,0x13f430,0x13f430);
      goto LAB_0023c3f8;
    }
    break;
  case HERO_STATE_JUMP_BOUNCE:
    hero._400_4_ = momentumMultiplyer * 5.5;
    hero._384_4_ = hero._748_4_;
    FUN_00234358(DAT_0015ed70 * 25.0);
    uVar15 = 0x13f470;
    fVar26 = DAT_0015ed70;
    fVar29 = 18.0;
LAB_0023c3b4:
    FUN_00248b68(fVar26 * fVar29,0x13f430,uVar15);
    goto LAB_0023c3f8;
  case HERO_STATE_ELECTRIC_DEATH:
    if (hero._1700_4_ == 0) {
      lVar14 = FUN_00263390(0x52a);
      fVar23 = hero.pos.w;
      fVar29 = hero.pos.y;
      fVar26 = hero.pos.z;
      iVar12 = (int)lVar14;
      hero._1700_4_ = iVar12;
      if (lVar14 != 0) {
        *(float *)(iVar12 + 0x10) = hero.pos.x;
        *(float *)(iVar12 + 0x14) = fVar26;
        *(float *)(iVar12 + 0x18) = fVar29;
        *(float *)(iVar12 + 0x1c) = fVar23;
        fVar23 = hero.rot.w;
        fVar29 = hero.rot.y;
        fVar26 = hero.rot.z;
        *(float *)(iVar12 + 0x40) = hero.rot.x;
        *(float *)(iVar12 + 0x44) = fVar26;
        *(float *)(iVar12 + 0x48) = fVar29;
        *(float *)(iVar12 + 0x4c) = fVar23;
        *(undefined2 *)(iVar12 + 0x32) = 0x40;
        *(undefined1 *)(hero._1700_4_ + 0x31) = 1;
        *(undefined1 *)(hero._1700_4_ + 0x30) = 0;
        *(undefined1 *)(hero._1700_4_ + 0x23) = 0;
        *(ushort *)(hero._1700_4_ + 0x34) = *(ushort *)(hero._1700_4_ + 0x34) | 0x800;
        FUN_00265bd8(hero._1700_4_);
        FUN_002a1618(0,0,hero._1700_4_);
        if (hero._1700_4_ != 0) goto LAB_00237800;
      }
    }
    else {
LAB_00237800:
      cVar9 = FUN_00222160(fGpffff8160 * 5.0);
      *(char *)(hero._1700_4_ + 0x23) = *(char *)(hero._1700_4_ + 0x23) + cVar9;
      if (0x80 < *(byte *)(hero._1700_4_ + 0x23)) {
        *(undefined1 *)(hero._1700_4_ + 0x23) = 0x80;
      }
      pmVar8 = hero.pMoby;
      uVar27 = hero._1700_4_;
      uVar2 = ((hero.pMoby)->pos).x;
      uVar3 = ((hero.pMoby)->pos).z;
      uVar4 = ((hero.pMoby)->pos).y;
      uVar5 = ((hero.pMoby)->pos).w;
      *(undefined4 *)(hero._1700_4_ + 0x10) = uVar2;
      *(undefined4 *)(uVar27 + 0x14) = uVar3;
      *(undefined4 *)(uVar27 + 0x18) = uVar4;
      *(undefined4 *)(uVar27 + 0x1c) = uVar5;
      uVar15 = *(undefined8 *)&pmVar8->field_0x40;
      uVar16 = *(undefined8 *)&pmVar8->field_0x48;
      *(int *)(uVar27 + 0x40) = (int)uVar15;
      *(int *)(uVar27 + 0x44) = (int)((ulong)uVar15 >> 0x20);
      *(int *)(uVar27 + 0x48) = (int)uVar16;
      *(int *)(uVar27 + 0x4c) = (int)((ulong)uVar16 >> 0x20);
      FUN_00265bd8();
    }
    hero._232_4_ = 0;
    vec.z = (float)in_stack_fffffec4;
    vec.x = (float)in_stack_fffffec0;
    vec.y = (float)in_stack_fffffec8;
    vec.w = in_stack_fffffecc;
    fVar26 = (float)vector_length(vec);
    FUN_00221510(DAT_0015ed60 * -0.07999998 * fVar26 + fVar26,0x13f430,0x13f430);
    FUN_00240c78();
    goto LAB_0023c3f8;
  case HERO_STATE_ELECTRIC_DEATH_UNDER:
    FUN_00236798(4,hero.pMoby,0x12);
    bVar1 = 0.7 < (float)hero._732_4_;
    fVar29 = momentumMultiplyer * 4.0;
    fVar26 = momentumMultiplyer * 5.75;
    if (bVar1) {
      fVar26 = fVar29;
    }
    FUN_00231f70((float)hero._8860_4_ * fVar26,0);
    if (0.2 < (float)hero._8860_4_) {
      if ((g_Pad.bits & (PAD_R2|PAD_L2)) == 0) {
        TurnWithCameraCheck(fGpffff8164 * 0.027,fGpffff8164 * 0.3,
                            momentumMultiplyer * 5.934119 * (float)hero._8860_4_,0);
        goto LAB_0023b178;
      }
LAB_0023b18c:
      uVar27 = hero._384_4_;
      hero._384_4_ = DAT_00167258;
      TurnWithCameraCheck(fGpffff8164 * 0.017,fGpffff8164 * 0.3,momentumMultiplyer * 4.712389,0);
      hero._384_4_ = uVar27;
    }
    else {
LAB_0023b178:
      if ((g_Pad.bits & (PAD_R2|PAD_L2)) != 0) goto LAB_0023b18c;
    }
    fVar26 = 7.0;
    if ((float)hero._8860_4_ < 0.2) {
      fVar26 = 3.5;
    }
    FUN_00234358(DAT_0015ed70 * fVar26);
    FUN_00235638();
    FUN_00232978(1);
    if (!bVar1) {
      FUN_00270780((float)hero._728_4_ + 0.17,DAT_0015ed64 * 0.02,DAT_0015ed64 * 0.35,
                   momentumMultiplyer * 2.5,0x13f3d8,0x13f654);
      goto LAB_0023c3f8;
    }
    FUN_00248f68(0x13f430,0x13f430);
    FUN_00248b68(fVar29 * 0.72,0x13f430,0x13f430);
    hero._772_4_ = hero._232_4_;
    fVar26 = (float)hero._232_4_;
  }
  hero._232_4_ = fVar26;
LAB_0023c3f8:
  if (iStack_cc != hero.field8166_0x2088) {
    hero._416_4_ = 0;
  }
  if (uStack_c8 != (byte)pmVar7->field_0x53) {
    hero._420_4_ = 0;
  }
  return;
}



// === ASSEMBLY ===

002370b8: c0 fe bd 27           addiu sp, sp, -0x140
002370bc: 14 00 02 3c           lui v0, 0x14
002370c0: d0 00 b5 7f           sq s5, 0xd0 ( sp )
002370c4: 10 01 bf 7f           sq ra, 0x110 ( sp )
002370c8: 2d a8 40 00           move s5, v0
002370cc: 00 01 be 7f           sq s8, 0x100 ( sp )
002370d0: 50 f3 42 24           addiu v0, v0, -0xcb0
002370d4: f0 00 b7 7f           sq s7, 0xf0 ( sp )
002370d8: e0 00 b6 7f           sq s6, 0xe0 ( sp )
002370dc: c0 00 b4 7f           sq s4, 0xc0 ( sp )
002370e0: b0 00 b3 7f           sq s3, 0xb0 ( sp )
002370e4: a0 00 b2 7f           sq s2, 0xa0 ( sp )
002370e8: 90 00 b1 7f           sq s1, 0x90 ( sp )
002370ec: 80 00 b0 7f           sq s0, 0x80 ( sp )
002370f0: 38 01 b7 e7           swc1 f23, 0x138 ( sp )
002370f4: 30 01 b6 e7           swc1 f22, 0x130 ( sp )
002370f8: 28 01 b5 e7           swc1 f21, 0x128 ( sp )
002370fc: 20 01 b4 e7           swc1 f20, 0x120 ( sp )
00237100: 84 20 44 8c           lw a0, 0x2084 ( v0 )
00237104: 80 20 5e 8c           lw s8, 0x2080 ( v0 )
00237108: 88 20 42 8c           lw v0, 0x2088 ( v0 )
0023710c: 83 00 83 2c           sltiu v1, a0, 0x83
00237110: 74 00 a2 af           sw v0, 0x74 ( sp )
00237114: 53 00 c2 93           lbu v0, 0x53 ( s8 )
00237118: b5 14 60 10           beq v1, zero, 0023c3f0
0023711c: 78 00 a2 af           _sw v0, 0x78 ( sp )
00237120: 21 00 02 3c           lui v0, 0x21
00237124: 80 18 04 00           sll v1, a0, 0x2
00237128: 80 8e 42 24           addiu v0, v0, -0x7180
0023712c: 21 18 62 00           addu v1, v1, v0
00237130: 00 00 64 8c           lw a0, 0x0 ( v1 )
00237134: 08 00 80 00           jr a0
00237138: 00 00 00 00           _nop 
0023713c: 50 f3 b1 26           addiu s1, s5, -0xcb0
00237140: a9 20 22 92           lbu v0, 0x20a9 ( s1 )
00237144: 03 00 40 10           beq v0, zero, 00237154
00237148: 0f 00 04 24           _li a0, 0xf
0023714c: 10 ab 08 0c           jal 0022ac40
00237150: 1e 00 05 24           _li a1, 0x1e
00237154: 16 00 01 3c           lui at, 0x16
00237158: 6c ed 2d c4           lwc1 f13, -0x1294 ( at )
0023715c: 01 00 12 24           li s2, 0x1
00237160: 00 3f 01 3c           lui at, 0x3f00
00237164: 00 60 81 44           mtc1 at, f12
00237168: 80 3f 01 3c           lui at, 0x3f80
0023716c: 00 a0 81 44           mtc1 at, f20
00237170: 00 a8 80 44           clear f21
00237174: 14 ce 08 0c           jal 00233850
00237178: 40 6b 0d 46           _add.S f13, f13, f13
0023717c: 6c 40 01 3c           lui at, 0x406c
00237180: cd cc 21 34           ori at, at, 0xcccd
00237184: 00 60 81 44           mtc1 at, f12
00237188: 9a da 08 0c           jal 00236a68
0023718c: 46 ab 00 46           _mov.S f13, f21
00237190: 06 a3 00 46           mov.S f12, f20
00237194: dc c7 08 0c           jal 00231f70
00237198: 2d 20 00 00           _move a0, zero
0023719c: 84 20 23 8e           lw v1, 0x2084 ( s1 )
002371a0: 03 00 72 10           beq v1, s2, 002371b0
002371a4: 1e 00 02 24           _li v0, 0x1e
002371a8: 4b 00 62 14           bne v1, v0, 002372d8
002371ac: 50 f3 b0 26           _addiu s0, s5, -0xcb0
002371b0: a5 20 22 92           lbu v0, 0x20a5 ( s1 )
002371b4: 47 00 40 10           beq v0, zero, 002372d4
002371b8: a9 24 00 70           _clear a0
002371bc: 16 00 10 3c           lui s0, 0x16
002371c0: 00 00 a4 7f           sq a0, 0x0 ( sp )
002371c4: 50 74 10 26           addiu s0, s0, 0x7450
002371c8: 00 00 b4 e7           swc1 f20, 0x0 ( sp )
002371cc: 70 01 24 26           addiu a0, s1, 0x170
002371d0: 2d 28 a0 03           move a1, sp
002371d4: 78 85 08 0c           jal 002215e0
002371d8: 2d 30 00 02           _move a2, s0
002371dc: 16 00 01 3c           lui at, 0x16
002371e0: 64 ed 2c c4           lwc1 f12, -0x129c ( at )
002371e4: 2d 20 00 00           move a0, zero
002371e8: 16 00 01 3c           lui at, 0x16
002371ec: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
002371f0: 2e 43 01 3c           lui at, 0x432e
002371f4: 6e 88 21 34           ori at, at, 0x886e
002371f8: 00 70 81 44           mtc1 at, f14
002371fc: 42 63 15 46           mul.S f13, f12, f21
00237200: 08 fe 00 c6           lwc1 f0, -0x1f8 ( s0 )
00237204: 82 0b 0e 46           mul.S f14, f1, f14
00237208: 24 c9 08 0c           jal 00232490
0023720c: 80 01 20 e6           _swc1 f0, 0x180 ( s1 )
00237210: 88 8a 82 8f           lw v0, -0x7578 ( gp )
00237214: 30 00 40 58           blezl v0, 002372d8
00237218: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023721c: 88 8a 84 27           addiu a0, gp, -0x7578
00237220: 9e 83 08 0c           jal 00220e78
00237224: 00 00 00 00           _nop 
00237228: 2a 00 40 10           beq v0, zero, 002372d4
0023722c: 14 00 03 3c           _lui v1, 0x14
00237230: fe ff 02 34           ori v0, zero, 0xfffe
00237234: 48 18 71 24           addiu s1, v1, 0x1848
00237238: 90 00 23 96           lhu v1, 0x90 ( s1 )
0023723c: 2b 10 43 00           sltu v0, v0, v1
00237240: 05 00 40 14           bne v0, zero, 00237258
00237244: a4 82 84 8f           _lw a0, -0x7d5c ( gp )
00237248: 01 00 62 24           addiu v0, v1, 0x1
0023724c: 90 00 22 a6           sh v0, 0x90 ( s1 )
00237250: 16 00 04 3c           lui a0, 0x16
00237254: a4 ee 84 8c           lw a0, -0x115c ( a0 )
00237258: 8c 83 08 0c           jal 00220e30
0023725c: 58 02 10 24           _li s0, 0x258
00237260: 1a 00 50 00           div v0, s0
00237264: 01 00 00 52           beql s0, zero, 0023726c
00237268: cd 01 00 00           _break 0x7
0023726c: 92 00 23 96           lhu v1, 0x92 ( s1 )
00237270: 12 10 00 00           mflo v0
00237274: 2a 18 62 00           slt v1, v1, v0
00237278: 0b 00 60 10           beq v1, zero, 002372a8
0023727c: 84 81 83 8f           _lw v1, -0x7e7c ( gp )
00237280: 8c 83 08 0c           jal 00220e30
00237284: a4 82 84 8f           _lw a0, -0x7d5c ( gp )
00237288: 1a 00 50 00           div v0, s0
0023728c: 58 02 03 24           li v1, 0x258
00237290: 01 00 60 50           beql v1, zero, 00237298
00237294: cd 01 00 00           _break 0x7
00237298: 12 10 00 00           mflo v0
0023729c: 92 00 22 a6           sh v0, 0x92 ( s1 )
002372a0: 16 00 03 3c           lui v1, 0x16
002372a4: 84 ed 63 8c           lw v1, -0x127c ( v1 )
002372a8: 00 80 06 3c           lui a2, 0x8000
002372ac: 94 00 22 8e           lw v0, 0x94 ( s1 )
002372b0: ff ff 05 24           li a1, -0x1
002372b4: 04 18 72 00           sllv v1, s2, v1
002372b8: 8c 8a 84 8f           lw a0, -0x7574 ( gp )
002372bc: 25 10 43 00           or v0, v0, v1
002372c0: 88 8a 85 af           sw a1, -0x7578 ( gp )
002372c4: 25 10 46 00           or v0, v0, a2
002372c8: 01 00 84 24           addiu a0, a0, 0x1
002372cc: 94 00 22 ae           sw v0, 0x94 ( s1 )
002372d0: 8c 8a 84 af           sw a0, -0x7574 ( gp )
002372d4: 50 f3 b0 26           addiu s0, s5, -0xcb0
002372d8: 03 00 03 24           li v1, 0x3
002372dc: 84 20 02 8e           lw v0, 0x2084 ( s0 )
002372e0: 06 00 43 54           bnel v0, v1, 002372fc
002372e4: 84 20 03 8e           _lw v1, 0x2084 ( s0 )
002372e8: 16 0a 09 0c           jal 00242858
002372ec: 00 00 00 00           _nop 
002372f0: 40 14 40 14           bne v0, zero, 0023c3f4
002372f4: 50 f3 a3 26           _addiu v1, s5, -0xcb0
002372f8: 84 20 03 8e           lw v1, 0x2084 ( s0 )
002372fc: 04 00 02 24           li v0, 0x4
00237300: 03 00 62 10           beq v1, v0, 00237310
00237304: 17 00 02 24           _li v0, 0x17
00237308: 83 00 62 54           bnel v1, v0, 00237518
0023730c: 50 f3 b0 26           _addiu s0, s5, -0xcb0
00237310: 9c 22 01 c6           lwc1 f1, 0x229c ( s0 )
00237314: 4c 3e 01 3c           lui at, 0x3e4c
00237318: cd cc 21 34           ori at, at, 0xcccd
0023731c: 00 00 81 44           mtc1 at, f0
00237320: 00 00 00 00           nop 
00237324: 34 00 01 46           c.lt.S f0, f1
00237328: 00 00 00 00           nop 
0023732c: 09 00 01 45           bc1t 00237354
00237330: 50 f3 a2 26           _addiu v0, s5, -0xcb0
00237334: 80 20 02 8e           lw v0, 0x2080 ( s0 )
00237338: 0e 00 03 24           li v1, 0xe
0023733c: 53 00 44 90           lbu a0, 0x53 ( v0 )
00237340: 03 00 83 10           beq a0, v1, 00237350
00237344: 0f 00 02 24           _li v0, 0xf
00237348: 73 00 82 14           bne a0, v0, 00237518
0023734c: 50 f3 b0 26           _addiu s0, s5, -0xcb0
00237350: 50 f3 a2 26           addiu v0, s5, -0xcb0
00237354: 04 00 03 24           li v1, 0x4
00237358: 84 20 44 8c           lw a0, 0x2084 ( v0 )
0023735c: 15 00 83 14           bne a0, v1, 002373b4
00237360: 17 00 02 24           _li v0, 0x17
00237364: 16 00 01 3c           lui at, 0x16
00237368: 64 ed 21 c4           lwc1 f1, -0x129c ( at )
0023736c: 2d 20 00 00           move a0, zero
00237370: 03 3b 01 3c           lui at, 0x3b03
00237374: 6f 12 21 34           ori at, at, 0x126f
00237378: 00 60 81 44           mtc1 at, f12
0023737c: 8f 3d 01 3c           lui at, 0x3d8f
00237380: 29 5c 21 34           ori at, at, 0x5c29
00237384: 00 68 81 44           mtc1 at, f13
00237388: 16 00 01 3c           lui at, 0x16
0023738c: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
00237390: 02 0b 0c 46           mul.S f12, f1, f12
00237394: df 40 01 3c           lui at, 0x40df
00237398: f3 66 21 34           ori at, at, 0x66f3
0023739c: 00 70 81 44           mtc1 at, f14
002373a0: 42 0b 0d 46           mul.S f13, f1, f13
002373a4: 24 c9 08 0c           jal 00232490
002373a8: 82 03 0e 46           _mul.S f14, f0, f14
002373ac: 05 00 00 10           b 002373c4
002373b0: 50 f3 b1 26           _addiu s1, s5, -0xcb0
002373b4: 03 00 82 14           bne a0, v0, 002373c4
002373b8: 50 f3 b1 26           _addiu s1, s5, -0xcb0
002373bc: 3e c9 08 0c           jal 002324f8
002373c0: 00 00 00 00           _nop 
002373c4: 4a 84 08 0c           jal 00221128
002373c8: 84 01 2c c6           _lwc1 f12, 0x184 ( s1 )
002373cc: 16 00 01 3c           lui at, 0x16
002373d0: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
002373d4: b2 3e 01 3c           lui at, 0x3eb2
002373d8: c2 b8 21 34           ori at, at, 0xb8c2
002373dc: 00 10 81 44           mtc1 at, f2
002373e0: 00 00 00 00           nop 
002373e4: 42 08 02 46           mul.S f1, f1, f2
002373e8: 34 08 00 46           c.lt.S f1, f0
002373ec: 00 00 00 00           nop 
002373f0: 30 00 00 45           bc1f 002374b4
002373f4: 84 01 21 c6           _lwc1 f1, 0x184 ( s1 )
002373f8: 00 00 80 44           clear f0
002373fc: 00 00 00 00           nop 
00237400: 34 08 00 46           c.lt.S f1, f0
00237404: 00 00 00 00           nop 
00237408: 02 00 01 45           bc1t 00237414
0023740c: 01 00 04 24           _li a0, 0x1
00237410: 2d 20 00 00           move a0, zero
00237414: 80 20 23 8e           lw v1, 0x2080 ( s1 )
00237418: 0e 00 90 24           addiu s0, a0, 0xe
0023741c: 53 00 62 90           lbu v0, 0x53 ( v1 )
00237420: 09 00 50 10           beq v0, s0, 00237448
00237424: 00 00 00 00           _nop 
00237428: 8c 83 08 0c           jal 00220e30
0023742c: 05 00 04 24           _li a0, 0x5
00237430: 00 60 82 44           mtc1 v0, f12
00237434: 00 00 00 00           nop 
00237438: 20 63 80 46           cvt.s.W f12, f12
0023743c: 2d 20 00 02           move a0, s0
00237440: a4 1e 09 0c           jal 00247a90
00237444: 2d 28 00 00           _move a1, zero
00237448: 4a 84 08 0c           jal 00221128
0023744c: 84 01 2c c6           _lwc1 f12, 0x184 ( s1 )
00237450: 16 00 01 3c           lui at, 0x16
00237454: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
00237458: 54 40 01 3c           lui at, 0x4054
0023745c: 67 3b 21 34           ori at, at, 0x3b67
00237460: 00 10 81 44           mtc1 at, f2
00237464: 0c 3f 01 3c           lui at, 0x3f0c
00237468: cd cc 21 34           ori at, at, 0xcccd
0023746c: 00 18 81 44           mtc1 at, f3
00237470: 42 08 02 46           mul.S f1, f1, f2
00237474: 03 00 01 46           div.S f0, f0, f1
00237478: 34 00 03 46           c.lt.S f0, f3
0023747c: 00 00 00 00           nop 
00237480: 02 00 00 45           bc1f 0023748c
00237484: 90 0a 20 e6           _swc1 f0, 0xa90 ( s1 )
00237488: 90 0a 23 e6           swc1 f3, 0xa90 ( s1 )
0023748c: 90 0a 20 c6           lwc1 f0, 0xa90 ( s1 )
00237490: 20 40 01 3c           lui at, 0x4020
00237494: 00 08 81 44           mtc1 at, f1
00237498: 00 00 00 00           nop 
0023749c: 34 08 00 46           c.lt.S f1, f0
002374a0: 00 00 00 00           nop 
002374a4: 1b 00 03 45           bc1tl 00237514
002374a8: 90 0a 21 e6           _swc1 f1, 0xa90 ( s1 )
002374ac: 1a 00 00 10           b 00237518
002374b0: 50 f3 b0 26           _addiu s0, s5, -0xcb0
002374b4: 00 00 80 44           clear f0
002374b8: 00 00 00 00           nop 
002374bc: 32 08 00 46           c.eq.S f1, f0
002374c0: 00 00 00 00           nop 
002374c4: 13 00 00 45           bc1f 00237514
002374c8: 17 00 02 24           _li v0, 0x17
002374cc: 84 20 23 8e           lw v1, 0x2084 ( s1 )
002374d0: 04 00 62 14           bne v1, v0, 002374e4
002374d4: 0d 00 10 24           _li s0, 0xd
002374d8: c4 9b 08 0c           jal 00226f10
002374dc: 2d 20 00 00           _move a0, zero
002374e0: 2d 80 40 00           move s0, v0
002374e4: 80 20 22 8e           lw v0, 0x2080 ( s1 )
002374e8: 53 00 43 90           lbu v1, 0x53 ( v0 )
002374ec: 0a 00 70 50           beql v1, s0, 00237518
002374f0: 50 f3 b0 26           _addiu s0, s5, -0xcb0
002374f4: 8c 83 08 0c           jal 00220e30
002374f8: 07 00 04 24           _li a0, 0x7
002374fc: 00 60 82 44           mtc1 v0, f12
00237500: 00 00 00 00           nop 
00237504: 20 63 80 46           cvt.s.W f12, f12
00237508: 2d 20 00 02           move a0, s0
0023750c: a4 1e 09 0c           jal 00247a90
00237510: 2d 28 00 00           _move a1, zero
00237514: 50 f3 b0 26           addiu s0, s5, -0xcb0
00237518: 03 00 02 24           li v0, 0x3
0023751c: 84 20 03 8e           lw v1, 0x2084 ( s0 )
00237520: 4d 00 62 14           bne v1, v0, 00237658
00237524: 90 01 00 ae           _sw zero, 0x190 ( s0 )
00237528: 80 3f 01 3c           lui at, 0x3f80
0023752c: 00 08 81 44           mtc1 at, f1
00237530: 6c 01 00 c6           lwc1 f0, 0x16c ( s0 )
00237534: 00 03 01 46           add.S f12, f0, f1
00237538: 34 08 0c 46           c.lt.S f1, f12
0023753c: 00 00 00 00           nop 
00237540: 01 00 03 45           bc1tl 00237548
00237544: 06 0b 00 46           _mov.S f12, f1
00237548: 16 00 01 3c           lui at, 0x16
0023754c: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
00237550: 40 41 01 3c           lui at, 0x4140
00237554: 00 08 81 44           mtc1 at, f1
00237558: 80 20 03 8e           lw v1, 0x2080 ( s0 )
0023755c: 02 00 01 46           mul.S f0, f0, f1
00237560: 02 05 0c 46           mul.S f20, f0, f12
00237564: 90 22 14 e6           swc1 f20, 0x2290 ( s0 )
00237568: 52 00 64 90           lbu a0, 0x52 ( v1 )
0023756c: 53 00 62 90           lbu v0, 0x53 ( v1 )
00237570: 46 00 82 14           bne a0, v0, 0023768c
00237574: 14 00 02 24           _li v0, 0x14
00237578: 44 00 82 10           beq a0, v0, 0023768c
0023757c: 05 00 04 24           _li a0, 0x5
00237580: 64 01 00 c6           lwc1 f0, 0x164 ( s0 )
00237584: 8c 83 08 0c           jal 00220e30
00237588: 43 05 14 46           _div.S f21, f0, f20
0023758c: 00 00 82 44           mtc1 v0, f0
00237590: 00 00 00 00           nop 
00237594: 20 00 80 46           cvt.s.W f0, f0
00237598: 34 00 15 46           c.lt.S f0, f21
0023759c: 00 00 00 00           nop 
002375a0: 1e 00 00 45           bc1f 0023761c
002375a4: 50 f3 a4 26           _addiu a0, s5, -0xcb0
002375a8: 80 20 03 8e           lw v1, 0x2080 ( s0 )
002375ac: b0 40 01 3c           lui at, 0x40b0
002375b0: 00 08 81 44           mtc1 at, f1
002375b4: 51 00 62 90           lbu v0, 0x51 ( v1 )
002375b8: 00 00 82 44           mtc1 v0, f0
002375bc: 00 00 00 00           nop 
002375c0: 20 00 80 46           cvt.s.W f0, f0
002375c4: 34 00 01 46           c.lt.S f0, f1
002375c8: 00 00 00 00           nop 
002375cc: 13 00 00 45           bc1f 0023761c
002375d0: 00 00 00 00           _nop 
002375d4: 50 41 01 3c           lui at, 0x4150
002375d8: 00 60 81 44           mtc1 at, f12
002375dc: 00 3f 01 3c           lui at, 0x3f00
002375e0: 00 70 81 44           mtc1 at, f14
002375e4: 80 bf 01 3c           lui at, 0xbf80
002375e8: 00 78 81 44           mtc1 at, f15
002375ec: 88 a9 08 0c           jal 0022a620
002375f0: 46 ab 00 46           _mov.S f13, f21
002375f4: 8c 3f 01 3c           lui at, 0x3f8c
002375f8: cd cc 21 34           ori at, at, 0xcccd
002375fc: 00 08 81 44           mtc1 at, f1
00237600: 90 0a 00 c6           lwc1 f0, 0xa90 ( s0 )
00237604: 34 08 00 46           c.lt.S f1, f0
00237608: 00 00 00 00           nop 
0023760c: 1f 00 03 45           bc1tl 0023768c
00237610: 90 0a 01 e6           _swc1 f1, 0xa90 ( s0 )
00237614: 1d 00 00 10           b 0023768c
00237618: 00 00 00 00           _nop 
0023761c: d0 40 01 3c           lui at, 0x40d0
00237620: 00 08 81 44           mtc1 at, f1
00237624: 80 20 82 8c           lw v0, 0x2080 ( a0 )
00237628: 51 00 43 90           lbu v1, 0x51 ( v0 )
0023762c: 00 00 83 44           mtc1 v1, f0
00237630: 00 00 00 00           nop 
00237634: 20 00 80 46           cvt.s.W f0, f0
00237638: 34 08 00 46           c.lt.S f1, f0
0023763c: 00 00 00 00           nop 
00237640: 12 00 00 45           bc1f 0023768c
00237644: 00 00 00 00           _nop 
00237648: 80 3f 01 3c           lui at, 0x3f80
0023764c: 00 00 81 44           mtc1 at, f0
00237650: 0e 00 00 10           b 0023768c
00237654: 90 0a 80 e4           _swc1 f0, 0xa90 ( a0 )
00237658: 04 00 02 24           li v0, 0x4
0023765c: 06 00 62 14           bne v1, v0, 00237678
00237660: 70 81 81 c7           _lwc1 f1, -0x7e90 ( gp )
00237664: cf 40 01 3c           lui at, 0x40cf
00237668: 29 5c 21 34           ori at, at, 0x5c29
0023766c: 00 00 81 44           mtc1 at, f0
00237670: 06 00 00 10           b 0023768c
00237674: 02 0d 00 46           _mul.S f20, f1, f0
00237678: 49 41 01 3c           lui at, 0x4149
0023767c: 9a 99 21 34           ori at, at, 0x999a
00237680: 00 00 81 44           mtc1 at, f0
00237684: 00 00 00 00           nop 
00237688: 02 0d 00 46           mul.S f20, f1, f0
0023768c: 00 a8 80 44           clear f21
00237690: 46 a3 00 46           mov.S f13, f20
00237694: ba c9 08 0c           jal 002326e8
00237698: 06 ab 00 46           _mov.S f12, f21
0023769c: 14 00 02 3c           lui v0, 0x14
002376a0: 30 f4 50 24           addiu s0, v0, -0xbd0
002376a4: 2d 20 00 02           move a0, s0
002376a8: 5c 84 08 0c           jal 00221170
002376ac: 20 ff 11 26           _addiu s1, s0, -0xe0
002376b0: 9e d9 08 0c           jal 00236678
002376b4: 06 a3 00 46           _mov.S f12, f20
002376b8: e7 12 22 92           lbu v0, 0x12e7 ( s1 )
002376bc: 1c 00 40 10           beq v0, zero, 00237730
002376c0: 14 00 02 3c           _lui v0, 0x14
002376c4: dc d4 43 90           lbu v1, -0x2b24 ( v0 )
002376c8: 19 00 60 10           beq v1, zero, 00237730
002376cc: 00 00 00 00           _nop 
002376d0: dc 02 21 c6           lwc1 f1, 0x2dc ( s1 )
002376d4: 4c 3e 01 3c           lui at, 0x3e4c
002376d8: cd cc 21 34           ori at, at, 0xcccd
002376dc: 00 00 81 44           mtc1 at, f0
002376e0: 00 00 00 00           nop 
002376e4: 34 00 01 46           c.lt.S f0, f1
002376e8: 00 00 00 00           nop 
002376ec: 2d 13 01 45           bc1t 0023c3a4
002376f0: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
002376f4: 2d 20 00 02           move a0, s0
002376f8: 58 42 01 3c           lui at, 0x4258
002376fc: 00 60 81 44           mtc1 at, f12
00237700: 2d 28 00 02           move a1, s0
00237704: da 22 09 0c           jal 00248b68
00237708: 02 03 0c 46           _mul.S f12, f0, f12
0023770c: fc 02 22 8e           lw v0, 0x2fc ( s1 )
00237710: 37 13 40 10           beq v0, zero, 0023c3f0
00237714: c0 01 04 26           _addiu a0, s0, 0x1c0
00237718: a0 ff 03 26           addiu v1, s0, -0x60
0023771c: 00 00 82 78           lq v0, 0x0 ( a0 )
00237720: 00 00 62 7c           sq v0, 0x0 ( v1 )
00237724: dc 02 35 e6           swc1 f21, 0x2dc ( s1 )
00237728: 31 13 00 10           b 0023c3f0
0023772c: 0e 03 20 a6           _sh zero, 0x30e ( s1 )
00237730: 5e ca 08 0c           jal 00232978
00237734: 2d 20 00 00           _move a0, zero
00237738: 50 f3 a4 26           addiu a0, s5, -0xcb0
0023773c: 0e 03 82 84           lh v0, 0x30e ( a0 )
00237740: e8 12 40 14           bne v0, zero, 0023c2e4
00237744: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
00237748: 16 00 01 3c           lui at, 0x16
0023774c: 70 ed 2c c4           lwc1 f12, -0x1290 ( at )
00237750: e0 00 84 24           addiu a0, a0, 0xe0
00237754: 58 42 01 3c           lui at, 0x4258
00237758: 00 00 81 44           mtc1 at, f0
0023775c: 15 13 00 10           b 0023c3b4
00237760: 2d 28 80 00           _move a1, a0
00237764: 50 f3 b0 26           addiu s0, s5, -0xcb0
00237768: a4 06 02 8e           lw v0, 0x6a4 ( s0 )
0023776c: 24 00 40 14           bne v0, zero, 00237800
00237770: 60 81 80 c7           _lwc1 f0, -0x7ea0 ( gp )
00237774: e4 8c 09 0c           jal 00263390
00237778: 2a 05 04 24           _li a0, 0x52a
0023777c: 2d 30 40 00           move a2, v0
00237780: 3a 00 c0 10           beq a2, zero, 0023786c
00237784: a4 06 06 ae           _sw a2, 0x6a4 ( s0 )
00237788: 10 00 c4 24           addiu a0, a2, 0x10
0023778c: 80 00 03 26           addiu v1, s0, 0x80
00237790: 00 00 62 78           lq v0, 0x0 ( v1 )
00237794: 00 00 82 7c           sq v0, 0x0 ( a0 )
00237798: 40 00 c5 24           addiu a1, a2, 0x40
0023779c: 90 00 03 26           addiu v1, s0, 0x90
002377a0: 00 00 62 78           lq v0, 0x0 ( v1 )
002377a4: 00 00 a2 7c           sq v0, 0x0 ( a1 )
002377a8: 40 00 04 24           li a0, 0x40
002377ac: 01 00 05 24           li a1, 0x1
002377b0: 32 00 c4 a4           sh a0, 0x32 ( a2 )
002377b4: a4 06 02 8e           lw v0, 0x6a4 ( s0 )
002377b8: 31 00 45 a0           sb a1, 0x31 ( v0 )
002377bc: a4 06 03 8e           lw v1, 0x6a4 ( s0 )
002377c0: 30 00 60 a0           sb zero, 0x30 ( v1 )
002377c4: a4 06 02 8e           lw v0, 0x6a4 ( s0 )
002377c8: 23 00 40 a0           sb zero, 0x23 ( v0 )
002377cc: a4 06 03 8e           lw v1, 0x6a4 ( s0 )
002377d0: 34 00 62 94           lhu v0, 0x34 ( v1 )
002377d4: 00 08 42 34           ori v0, v0, 0x800
002377d8: 34 00 62 a4           sh v0, 0x34 ( v1 )
002377dc: f6 96 09 0c           jal 00265bd8
002377e0: a4 06 04 8e           _lw a0, 0x6a4 ( s0 )
002377e4: a4 06 06 8e           lw a2, 0x6a4 ( s0 )
002377e8: 2d 20 00 00           move a0, zero
002377ec: 86 85 0a 0c           jal 002a1618
002377f0: 2d 28 00 00           _move a1, zero
002377f4: a4 06 03 8e           lw v1, 0x6a4 ( s0 )
002377f8: 1c 00 60 10           beq v1, zero, 0023786c
002377fc: 60 81 80 c7           _lwc1 f0, -0x7ea0 ( gp )
00237800: a0 40 01 3c           lui at, 0x40a0
00237804: 00 60 81 44           mtc1 at, f12
00237808: 58 88 08 0c           jal 00222160
0023780c: 02 03 0c 46           _mul.S f12, f0, f12
00237810: a4 06 04 8e           lw a0, 0x6a4 ( s0 )
00237814: 23 00 83 90           lbu v1, 0x23 ( a0 )
00237818: 21 18 62 00           addu v1, v1, v0
0023781c: 23 00 83 a0           sb v1, 0x23 ( a0 )
00237820: a4 06 03 8e           lw v1, 0x6a4 ( s0 )
00237824: 23 00 62 90           lbu v0, 0x23 ( v1 )
00237828: 81 00 42 2c           sltiu v0, v0, 0x81
0023782c: 04 00 40 54           bnel v0, zero, 00237840
00237830: 80 20 05 8e           _lw a1, 0x2080 ( s0 )
00237834: 80 00 02 24           li v0, 0x80
00237838: 23 00 62 a0           sb v0, 0x23 ( v1 )
0023783c: 80 20 05 8e           lw a1, 0x2080 ( s0 )
00237840: a4 06 04 8e           lw a0, 0x6a4 ( s0 )
00237844: 10 00 a6 24           addiu a2, a1, 0x10
00237848: 10 00 83 24           addiu v1, a0, 0x10
0023784c: 00 00 c2 78           lq v0, 0x0 ( a2 )
00237850: 00 00 62 7c           sq v0, 0x0 ( v1 )
00237854: 40 00 a5 24           addiu a1, a1, 0x40
00237858: 40 00 83 24           addiu v1, a0, 0x40
0023785c: 00 00 a2 78           lq v0, 0x0 ( a1 )
00237860: 00 00 62 7c           sq v0, 0x0 ( v1 )
00237864: f6 96 09 0c           jal 00265bd8
00237868: 00 00 00 00           _nop 
0023786c: 50 f3 a2 26           addiu v0, s5, -0xcb0
00237870: e0 00 50 24           addiu s0, v0, 0xe0
00237874: e8 00 40 ac           sw zero, 0xe8 ( v0 )
00237878: c6 84 08 0c           jal 00221318
0023787c: 2d 20 00 02           _move a0, s0
00237880: a3 bd 01 3c           lui at, 0xbda3
00237884: 08 d7 21 34           ori at, at, 0xd708
00237888: 00 08 81 44           mtc1 at, f1
0023788c: 2d 20 00 02           move a0, s0
00237890: 16 00 01 3c           lui at, 0x16
00237894: 60 ed 2c c4           lwc1 f12, -0x12a0 ( at )
00237898: 2d 28 80 00           move a1, a0
0023789c: 02 63 01 46           mul.S f12, f12, f1
002378a0: 02 63 00 46           mul.S f12, f12, f0
002378a4: 44 85 08 0c           jal 00221510
002378a8: 00 63 00 46           _add.S f12, f12, f0
002378ac: 1e 03 09 0c           jal 00240c78
002378b0: 00 00 00 00           _nop 
002378b4: cf 12 00 10           b 0023c3f4
002378b8: 50 f3 a3 26           _addiu v1, s5, -0xcb0
002378bc: 50 f3 a5 26           addiu a1, s5, -0xcb0
002378c0: 35 00 03 24           li v1, 0x35
002378c4: 84 20 a2 8c           lw v0, 0x2084 ( a1 )
002378c8: 07 00 43 54           bnel v0, v1, 002378e8
002378cc: 2c 22 a6 8c           _lw a2, 0x222c ( a1 )
002378d0: 80 20 a5 8c           lw a1, 0x2080 ( a1 )
002378d4: 05 00 04 24           li a0, 0x5
002378d8: e6 d9 08 0c           jal 00236798
002378dc: 13 00 06 24           _li a2, 0x13
002378e0: 15 00 00 10           b 00237938
002378e4: 50 f3 b0 26           _addiu s0, s5, -0xcb0
002378e8: ff ff 02 24           li v0, -0x1
002378ec: 0e 00 c2 10           beq a2, v0, 00237928
002378f0: 14 00 02 3c           _lui v0, 0x14
002378f4: 70 00 04 24           li a0, 0x70
002378f8: 18 20 c4 00           mult a0, a2, a0
002378fc: 50 e5 42 24           addiu v0, v0, -0x1ab0
00237900: 80 20 a5 8c           lw a1, 0x2080 ( a1 )
00237904: 21 20 82 00           addu a0, a0, v0
00237908: 88 00 83 8c           lw v1, 0x88 ( a0 )
0023790c: 07 00 65 14           bne v1, a1, 0023792c
00237910: 50 f3 a3 26           _addiu v1, s5, -0xcb0
00237914: 74 00 82 90           lbu v0, 0x74 ( a0 )
00237918: 05 00 40 10           beq v0, zero, 00237930
0023791c: ff ff 02 24           _li v0, -0x1
00237920: d2 84 0a 0c           jal 002a1348
00237924: 2d 20 c0 00           _move a0, a2
00237928: 50 f3 a3 26           addiu v1, s5, -0xcb0
0023792c: ff ff 02 24           li v0, -0x1
00237930: 2c 22 62 ac           sw v0, 0x222c ( v1 )
00237934: 50 f3 b0 26           addiu s0, s5, -0xcb0
00237938: 0a 09 02 86           lh v0, 0x90a ( s0 )
0023793c: 0c 00 40 50           beql v0, zero, 00237970
00237940: 84 20 03 8e           _lw v1, 0x2084 ( s0 )
00237944: aa 83 08 0c           jal 00220ea8
00237948: 0a 09 04 26           _addiu a0, s0, 0x90a
0023794c: 0a 09 04 96           lhu a0, 0x90a ( s0 )
00237950: 08 00 03 24           li v1, 0x8
00237954: 2d 28 00 00           move a1, zero
00237958: 00 24 04 00           sll a0, a0, 0x10
0023795c: 83 24 04 00           sra a0, a0, 0x12
00237960: 09 00 82 28           slti v0, a0, 0x9
00237964: 50 ac 08 0c           jal 0022b140
00237968: 0a 20 62 00           _movz a0, v1, v0
0023796c: 84 20 03 8e           lw v1, 0x2084 ( s0 )
00237970: 33 00 02 24           li v0, 0x33
00237974: 15 00 62 54           bnel v1, v0, 002379cc
00237978: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023797c: 9c 0a 02 8e           lw v0, 0xa9c ( s0 )
00237980: 12 00 40 54           bnel v0, zero, 002379cc
00237984: 50 f3 b0 26           _addiu s0, s5, -0xcb0
00237988: a8 0a 01 c6           lwc1 f1, 0xaa8 ( s0 )
0023798c: 00 00 80 44           clear f0
00237990: 00 00 00 00           nop 
00237994: 34 00 01 46           c.lt.S f0, f1
00237998: 00 00 00 00           nop 
0023799c: 0b 00 00 45           bc1f 002379cc
002379a0: 50 f3 b0 26           _addiu s0, s5, -0xcb0
002379a4: 20 41 01 3c           lui at, 0x4120
002379a8: 00 00 81 44           mtc1 at, f0
002379ac: 00 00 00 00           nop 
002379b0: 34 08 00 46           c.lt.S f1, f0
002379b4: 00 00 00 00           nop 
002379b8: 04 00 00 45           bc1f 002379cc
002379bc: 04 00 04 24           _li a0, 0x4
002379c0: 50 ac 08 0c           jal 0022b140
002379c4: 01 00 05 24           _li a1, 0x1
002379c8: 50 f3 b0 26           addiu s0, s5, -0xcb0
002379cc: 34 00 03 24           li v1, 0x34
002379d0: 84 20 02 8e           lw v0, 0x2084 ( s0 )
002379d4: 18 00 43 54           bnel v0, v1, 00237a38
002379d8: 50 f3 b0 26           _addiu s0, s5, -0xcb0
002379dc: 90 20 03 8e           lw v1, 0x2090 ( s0 )
002379e0: 35 00 02 24           li v0, 0x35
002379e4: 14 00 62 54           bnel v1, v0, 00237a38
002379e8: 50 f3 b0 26           _addiu s0, s5, -0xcb0
002379ec: 8c 83 08 0c           jal 00220e30
002379f0: 0f 00 04 24           _li a0, 0xf
002379f4: 98 01 03 8e           lw v1, 0x198 ( s0 )
002379f8: 2a 18 62 00           slt v1, v1, v0
002379fc: 0e 00 60 50           beql v1, zero, 00237a38
00237a00: 50 f3 b0 26           _addiu s0, s5, -0xcb0
00237a04: 8c 83 08 0c           jal 00220e30
00237a08: 14 00 04 24           _li a0, 0x14
00237a0c: 98 01 04 8e           lw a0, 0x198 ( s0 )
00237a10: 03 00 03 24           li v1, 0x3
00237a14: 01 00 60 50           beql v1, zero, 00237a1c
00237a18: cd 01 00 00           _break 0x7
00237a1c: 01 00 05 24           li a1, 0x1
00237a20: 23 10 44 00           subu v0, v0, a0
00237a24: 1a 00 43 00           div v0, v1
00237a28: 12 10 00 00           mflo v0
00237a2c: 50 ac 08 0c           jal 0022b140
00237a30: 01 00 44 24           _addiu a0, v0, 0x1
00237a34: 50 f3 b0 26           addiu s0, s5, -0xcb0
00237a38: 01 00 02 24           li v0, 0x1
00237a3c: 88 20 03 8e           lw v1, 0x2088 ( s0 )
00237a40: 23 00 62 14           bne v1, v0, 00237ad0
00237a44: 14 00 02 3c           _lui v0, 0x14
00237a48: 98 01 02 8e           lw v0, 0x198 ( s0 )
00237a4c: 17 00 43 14           bne v0, v1, 00237aac
00237a50: 50 f3 b1 26           _addiu s1, s5, -0xcb0
00237a54: 03 00 04 24           li a0, 0x3
00237a58: 10 00 05 24           li a1, 0x10
00237a5c: ea ac 08 0c           jal 0022b3a8
00237a60: 2d 30 00 00           _move a2, zero
00237a64: 16 00 04 3c           lui a0, 0x16
00237a68: d0 12 84 8c           lw a0, 0x12d0 ( a0 )
00237a6c: 0b 00 80 10           beq a0, zero, 00237a9c
00237a70: d8 a6 85 8f           _lw a1, -0x5928 ( gp )
00237a74: 2d 30 00 00           move a2, zero
00237a78: 80 00 0c c6           lwc1 f12, 0x80 ( s0 )
00237a7c: cc 3e 01 3c           lui at, 0x3ecc
00237a80: cd cc 21 34           ori at, at, 0xcccd
00237a84: 00 70 81 44           mtc1 at, f14
00237a88: 99 be 01 3c           lui at, 0xbe99
00237a8c: 9a 99 21 34           ori at, at, 0x999a
00237a90: 00 78 81 44           mtc1 at, f15
00237a94: aa e0 0a 0c           jal 002b82a8
00237a98: 84 00 0d c6           _lwc1 f13, 0x84 ( s0 )
00237a9c: 8c 83 08 0c           jal 00220e30
00237aa0: 46 00 04 24           _li a0, 0x46
00237aa4: 0a 09 02 a6           sh v0, 0x90a ( s0 )
00237aa8: 50 f3 b1 26           addiu s1, s5, -0xcb0
00237aac: 28 00 04 24           li a0, 0x28
00237ab0: e0 08 30 8e           lw s0, 0x8e0 ( s1 )
00237ab4: 01 00 10 26           addiu s0, s0, 0x1
00237ab8: 8c 83 08 0c           jal 00220e30
00237abc: e0 08 30 ae           _sw s0, 0x8e0 ( s1 )
00237ac0: 2a 10 50 00           slt v0, v0, s0
00237ac4: 01 00 40 54           bnel v0, zero, 00237acc
00237ac8: 88 20 20 ae           _sw zero, 0x2088 ( s1 )
00237acc: 14 00 02 3c           lui v0, 0x14
00237ad0: 16 00 01 3c           lui at, 0x16
00237ad4: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
00237ad8: 40 c9 45 24           addiu a1, v0, -0x36c0
00237adc: 32 3f 01 3c           lui at, 0x3f32
00237ae0: c2 b8 21 34           ori at, at, 0xb8c2
00237ae4: 00 00 81 44           mtc1 at, f0
00237ae8: 28 01 a4 c4           lwc1 f4, 0x128 ( a1 )
00237aec: 2d 98 40 00           move s3, v0
00237af0: 2c 01 a3 c4           lwc1 f3, 0x12c ( a1 )
00237af4: 42 0d 00 46           mul.S f21, f1, f0
00237af8: 00 a0 80 44           clear f20
00237afc: 34 20 03 46           c.lt.S f4, f3
00237b00: 00 00 00 00           nop 
00237b04: 02 00 00 45           bc1f 00237b10
00237b08: 46 21 00 46           _mov.S f5, f4
00237b0c: 46 19 00 46           mov.S f5, f3
00237b10: 9c 3f 01 3c           lui at, 0x3f9c
00237b14: aa 61 21 34           ori at, at, 0x61aa
00237b18: 00 00 81 44           mtc1 at, f0
00237b1c: 2d 20 a0 00           move a0, a1
00237b20: 16 00 01 3c           lui at, 0x16
00237b24: 64 ed 22 c4           lwc1 f2, -0x129c ( at )
00237b28: 80 00 03 24           li v1, 0x80
00237b2c: 02 08 00 46           mul.S f0, f1, f0
00237b30: 4c 3e 01 3c           lui at, 0x3e4c
00237b34: cd cc 21 34           ori at, at, 0xcccd
00237b38: 00 30 81 44           mtc1 at, f6
00237b3c: 75 3c 01 3c           lui at, 0x3c75
00237b40: 8f c2 21 34           ori at, at, 0xc28f
00237b44: 00 08 81 44           mtc1 at, f1
00237b48: a0 01 82 dc           ld v0, 0x1a0 ( a0 )
00237b4c: 82 15 06 46           mul.S f22, f2, f6
00237b50: 01 00 15 46           sub.S f0, f0, f21
00237b54: c2 15 01 46           mul.S f23, f2, f1
00237b58: c0 00 42 30           andi v0, v0, 0xc0
00237b5c: 02 00 05 46           mul.S f0, f0, f5
00237b60: 06 00 43 10           beq v0, v1, 00237b7c
00237b64: 40 ad 00 46           _add.S f21, f21, f0
00237b68: 50 f3 b0 26           addiu s0, s5, -0xcb0
00237b6c: 01 00 03 24           li v1, 0x1
00237b70: 88 20 02 8e           lw v0, 0x2088 ( s0 )
00237b74: 3a 00 43 54           bnel v0, v1, 00237c60
00237b78: a0 01 82 8c           _lw v0, 0x1a0 ( a0 )
00237b7c: c0 3f 01 3c           lui at, 0x3fc0
00237b80: 00 00 81 44           mtc1 at, f0
00237b84: 80 3f 01 3c           lui at, 0x3f80
00237b88: 00 a0 81 44           mtc1 at, f20
00237b8c: 02 1b 00 46           mul.S f12, f3, f0
00237b90: 34 a0 0c 46           c.lt.S f20, f12
00237b94: 00 00 00 00           nop 
00237b98: 01 00 03 45           bc1tl 00237ba0
00237b9c: 06 a3 00 46           _mov.S f12, f20
00237ba0: 34 60 06 46           c.lt.S f12, f6
00237ba4: 00 00 00 00           nop 
00237ba8: 01 00 03 45           bc1tl 00237bb0
00237bac: 06 33 00 46           _mov.S f12, f6
00237bb0: dc 01 83 8c           lw v1, 0x1dc ( a0 )
00237bb4: 79 00 02 24           li v0, 0x79
00237bb8: 17 00 62 10           beq v1, v0, 00237c18
00237bbc: 50 f3 b0 26           _addiu s0, s5, -0xcb0
00237bc0: 14 00 04 24           li a0, 0x14
00237bc4: 02 09 02 96           lhu v0, 0x902 ( s0 )
00237bc8: 00 09 00 a6           sh zero, 0x900 ( s0 )
00237bcc: 01 00 42 24           addiu v0, v0, 0x1
00237bd0: 8c 83 08 0c           jal 00220e30
00237bd4: 02 09 02 a6           _sh v0, 0x902 ( s0 )
00237bd8: 02 09 03 86           lh v1, 0x902 ( s0 )
00237bdc: 00 10 82 44           mtc1 v0, f2
00237be0: 00 00 00 00           nop 
00237be4: a0 10 80 46           cvt.s.W f2, f2
00237be8: 00 3f 01 3c           lui at, 0x3f00
00237bec: 00 08 81 44           mtc1 at, f1
00237bf0: 00 00 83 44           mtc1 v1, f0
00237bf4: 00 00 00 00           nop 
00237bf8: 20 00 80 46           cvt.s.W f0, f0
00237bfc: 02 00 01 46           mul.S f0, f0, f1
00237c00: 03 00 02 46           div.S f0, f0, f2
00237c04: 00 03 01 46           add.S f12, f0, f1
00237c08: 34 a0 0c 46           c.lt.S f20, f12
00237c0c: 00 00 00 00           nop 
00237c10: 01 00 03 45           bc1tl 00237c18
00237c14: 06 a3 00 46           _mov.S f12, f20
00237c18: 50 f3 a2 26           addiu v0, s5, -0xcb0
00237c1c: 01 00 04 24           li a0, 0x1
00237c20: 88 20 43 8c           lw v1, 0x2088 ( v0 )
00237c24: 09 00 64 14           bne v1, a0, 00237c4c
00237c28: 00 00 00 00           _nop 
00237c2c: b3 3e 01 3c           lui at, 0x3eb3
00237c30: 33 33 21 34           ori at, at, 0x3333
00237c34: 00 00 81 44           mtc1 at, f0
00237c38: 00 00 00 00           nop 
00237c3c: 34 60 00 46           c.lt.S f12, f0
00237c40: 00 00 00 00           nop 
00237c44: 01 00 03 45           bc1tl 00237c4c
00237c48: 06 03 00 46           _mov.S f12, f0
00237c4c: ae 3f 01 3c           lui at, 0x3fae
00237c50: f1 40 21 34           ori at, at, 0x40f1
00237c54: 00 00 81 44           mtc1 at, f0
00237c58: 3c 00 00 10           b 00237d4c
00237c5c: 02 65 00 46           _mul.S f20, f12, f0
00237c60: 40 00 42 30           andi v0, v0, 0x40
00237c64: 38 00 40 50           beql v0, zero, 00237d48
00237c68: 02 09 00 a6           _sh zero, 0x902 ( s0 )
00237c6c: c0 3f 01 3c           lui at, 0x3fc0
00237c70: 00 00 81 44           mtc1 at, f0
00237c74: 80 3f 01 3c           lui at, 0x3f80
00237c78: 00 a0 81 44           mtc1 at, f20
00237c7c: 02 23 00 46           mul.S f12, f4, f0
00237c80: 34 a0 0c 46           c.lt.S f20, f12
00237c84: 00 00 00 00           nop 
00237c88: 01 00 03 45           bc1tl 00237c90
00237c8c: 06 a3 00 46           _mov.S f12, f20
00237c90: 34 60 06 46           c.lt.S f12, f6
00237c94: 00 00 00 00           nop 
00237c98: 01 00 03 45           bc1tl 00237ca0
00237c9c: 06 33 00 46           _mov.S f12, f6
00237ca0: dc 01 a3 8c           lw v1, 0x1dc ( a1 )
00237ca4: 79 00 02 24           li v0, 0x79
00237ca8: 16 00 62 10           beq v1, v0, 00237d04
00237cac: 14 00 04 24           _li a0, 0x14
00237cb0: 00 09 02 96           lhu v0, 0x900 ( s0 )
00237cb4: 02 09 00 a6           sh zero, 0x902 ( s0 )
00237cb8: 01 00 42 24           addiu v0, v0, 0x1
00237cbc: 8c 83 08 0c           jal 00220e30
00237cc0: 00 09 02 a6           _sh v0, 0x900 ( s0 )
00237cc4: 00 09 03 86           lh v1, 0x900 ( s0 )
00237cc8: 00 10 82 44           mtc1 v0, f2
00237ccc: 00 00 00 00           nop 
00237cd0: a0 10 80 46           cvt.s.W f2, f2
00237cd4: 00 3f 01 3c           lui at, 0x3f00
00237cd8: 00 08 81 44           mtc1 at, f1
00237cdc: 00 00 83 44           mtc1 v1, f0
00237ce0: 00 00 00 00           nop 
00237ce4: 20 00 80 46           cvt.s.W f0, f0
00237ce8: 02 00 01 46           mul.S f0, f0, f1
00237cec: 03 00 02 46           div.S f0, f0, f2
00237cf0: 00 03 01 46           add.S f12, f0, f1
00237cf4: 34 a0 0c 46           c.lt.S f20, f12
00237cf8: 00 00 00 00           nop 
00237cfc: 01 00 03 45           bc1tl 00237d04
00237d00: 06 a3 00 46           _mov.S f12, f20
00237d04: 50 f3 a2 26           addiu v0, s5, -0xcb0
00237d08: bb 44 01 3c           lui at, 0x44bb
00237d0c: 00 80 21 34           ori at, at, 0x8000
00237d10: 00 08 81 44           mtc1 at, f1
00237d14: a0 22 40 c4           lwc1 f0, 0x22a0 ( v0 )
00237d18: 20 00 80 46           cvt.s.W f0, f0
00237d1c: 34 00 01 46           c.lt.S f0, f1
00237d20: 00 00 00 00           nop 
00237d24: 03 00 00 45           bc1f 00237d34
00237d28: 00 00 00 00           _nop 
00237d2c: 80 3f 01 3c           lui at, 0x3f80
00237d30: 00 60 81 44           mtc1 at, f12
00237d34: ae bf 01 3c           lui at, 0xbfae
00237d38: f1 40 21 34           ori at, at, 0x40f1
00237d3c: 00 00 81 44           mtc1 at, f0
00237d40: 02 00 00 10           b 00237d4c
00237d44: 02 65 00 46           _mul.S f20, f12, f0
00237d48: 00 09 00 a6           sh zero, 0x900 ( s0 )
00237d4c: 40 c9 63 26           addiu v1, s3, -0x36c0
00237d50: a0 01 62 8c           lw v0, 0x1a0 ( v1 )
00237d54: 40 00 42 30           andi v0, v0, 0x40
00237d58: 3d 00 40 10           beq v0, zero, 00237e50
00237d5c: 50 f3 a2 26           _addiu v0, s5, -0xcb0
00237d60: 28 01 61 c4           lwc1 f1, 0x128 ( v1 )
00237d64: 50 f3 a3 26           addiu v1, s5, -0xcb0
00237d68: 40 3f 01 3c           lui at, 0x3f40
00237d6c: 00 00 81 44           mtc1 at, f0
00237d70: 0e 09 62 94           lhu v0, 0x90e ( v1 )
00237d74: 34 00 01 46           c.lt.S f0, f1
00237d78: 01 00 42 24           addiu v0, v0, 0x1
00237d7c: 32 00 00 45           bc1f 00237e48
00237d80: 0e 09 62 a4           _sh v0, 0x90e ( v1 )
00237d84: 0c 09 62 94           lhu v0, 0x90c ( v1 )
00237d88: 5a 00 04 24           li a0, 0x5a
00237d8c: 14 00 11 3c           lui s1, 0x14
00237d90: 01 00 42 24           addiu v0, v0, 0x1
00237d94: 00 84 02 00           sll s0, v0, 0x10
00237d98: 0c 09 62 a4           sh v0, 0x90c ( v1 )
00237d9c: 8c 83 08 0c           jal 00220e30
00237da0: 03 84 10 00           _sra s0, s0, 0x10
00237da4: 2a 10 50 00           slt v0, v0, s0
00237da8: 08 00 40 10           beq v0, zero, 00237dcc
00237dac: 48 18 24 26           _addiu a0, s1, 0x1848
00237db0: fe ff 02 34           ori v0, zero, 0xfffe
00237db4: 58 00 83 94           lhu v1, 0x58 ( a0 )
00237db8: 2b 10 43 00           sltu v0, v0, v1
00237dbc: 05 00 40 54           bnel v0, zero, 00237dd4
00237dc0: a4 82 84 8f           _lw a0, -0x7d5c ( gp )
00237dc4: 01 00 62 24           addiu v0, v1, 0x1
00237dc8: 58 00 82 a4           sh v0, 0x58 ( a0 )
00237dcc: 16 00 04 3c           lui a0, 0x16
00237dd0: a4 ee 84 8c           lw a0, -0x115c ( a0 )
00237dd4: 58 02 10 24           li s0, 0x258
00237dd8: 8c 83 08 0c           jal 00220e30
00237ddc: 48 18 31 26           _addiu s1, s1, 0x1848
00237de0: 1a 00 50 00           div v0, s0
00237de4: 01 00 00 52           beql s0, zero, 00237dec
00237de8: cd 01 00 00           _break 0x7
00237dec: 5a 00 23 96           lhu v1, 0x5a ( s1 )
00237df0: 12 10 00 00           mflo v0
00237df4: 2a 18 62 00           slt v1, v1, v0
00237df8: 0b 00 60 10           beq v1, zero, 00237e28
00237dfc: 84 81 85 8f           _lw a1, -0x7e7c ( gp )
00237e00: 8c 83 08 0c           jal 00220e30
00237e04: a4 82 84 8f           _lw a0, -0x7d5c ( gp )
00237e08: 1a 00 50 00           div v0, s0
00237e0c: 58 02 03 24           li v1, 0x258
00237e10: 01 00 60 50           beql v1, zero, 00237e18
00237e14: cd 01 00 00           _break 0x7
00237e18: 12 10 00 00           mflo v0
00237e1c: 5a 00 22 a6           sh v0, 0x5a ( s1 )
00237e20: 16 00 05 3c           lui a1, 0x16
00237e24: 84 ed a5 8c           lw a1, -0x127c ( a1 )
00237e28: 01 00 03 24           li v1, 0x1
00237e2c: 5c 00 22 8e           lw v0, 0x5c ( s1 )
00237e30: 00 80 04 3c           lui a0, 0x8000
00237e34: 04 18 a3 00           sllv v1, v1, a1
00237e38: 25 10 43 00           or v0, v0, v1
00237e3c: 25 10 44 00           or v0, v0, a0
00237e40: 05 00 00 10           b 00237e58
00237e44: 5c 00 22 ae           _sw v0, 0x5c ( s1 )
00237e48: 03 00 00 10           b 00237e58
00237e4c: 0c 09 60 a4           _sh zero, 0x90c ( v1 )
00237e50: 0c 09 40 a4           sh zero, 0x90c ( v0 )
00237e54: 0e 09 40 a4           sh zero, 0x90e ( v0 )
00237e58: 40 c9 63 26           addiu v1, s3, -0x36c0
00237e5c: a4 01 62 8c           lw v0, 0x1a4 ( v1 )
00237e60: 40 00 42 30           andi v0, v0, 0x40
00237e64: 10 00 40 10           beq v0, zero, 00237ea8
00237e68: 50 f3 b1 26           _addiu s1, s5, -0xcb0
00237e6c: 16 00 10 3c           lui s0, 0x16
00237e70: cc f5 10 8e           lw s0, -0xa34 ( s0 )
00237e74: 14 09 22 8e           lw v0, 0x914 ( s1 )
00237e78: 46 00 04 24           li a0, 0x46
00237e7c: 8c 83 08 0c           jal 00220e30
00237e80: 23 80 02 02           _subu s0, s0, v0
00237e84: 2a 80 02 02           slt s0, s0, v0
00237e88: 06 00 00 12           beq s0, zero, 00237ea4
00237e8c: cc 89 82 8f           _lw v0, -0x7634 ( gp )
00237e90: 10 09 22 8e           lw v0, 0x910 ( s1 )
00237e94: 01 00 42 24           addiu v0, v0, 0x1
00237e98: 10 09 22 ae           sw v0, 0x910 ( s1 )
00237e9c: 16 00 02 3c           lui v0, 0x16
00237ea0: cc f5 42 8c           lw v0, -0xa34 ( v0 )
00237ea4: 14 09 22 ae           sw v0, 0x914 ( s1 )
00237ea8: 50 f3 b1 26           addiu s1, s5, -0xcb0
00237eac: 46 00 04 24           li a0, 0x46
00237eb0: 8c 83 08 0c           jal 00220e30
00237eb4: 0e 09 30 86           _lh s0, 0x90e ( s1 )
00237eb8: 2a 10 50 00           slt v0, v0, s0
00237ebc: 01 00 40 54           bnel v0, zero, 00237ec4
00237ec0: 10 09 20 ae           _sw zero, 0x910 ( s1 )
00237ec4: 40 c9 70 26           addiu s0, s3, -0x36c0
00237ec8: a0 01 02 8e           lw v0, 0x1a0 ( s0 )
00237ecc: 80 00 42 30           andi v0, v0, 0x80
00237ed0: 01 00 40 54           bnel v0, zero, 00237ed8
00237ed4: 10 09 20 ae           _sw zero, 0x910 ( s1 )
00237ed8: 84 20 23 8e           lw v1, 0x2084 ( s1 )
00237edc: 34 00 02 24           li v0, 0x34
00237ee0: 04 00 62 14           bne v1, v0, 00237ef4
00237ee4: 06 a3 00 46           _mov.S f12, f20
00237ee8: 00 a0 80 44           clear f20
00237eec: 00 00 00 00           nop 
00237ef0: 06 a3 00 46           mov.S f12, f20
00237ef4: 86 b3 00 46           mov.S f14, f22
00237ef8: c6 ab 00 46           mov.S f15, f21
00237efc: e8 08 25 26           addiu a1, s1, 0x8e8
00237f00: 2d 30 00 00           move a2, zero
00237f04: 94 00 24 26           addiu a0, s1, 0x94
00237f08: 46 bb 00 46           mov.S f13, f23
00237f0c: d6 c2 09 0c           jal 00270b58
00237f10: 94 00 34 c6           _lwc1 f20, 0x94 ( s1 )
00237f14: 94 00 2c c6           lwc1 f12, 0x94 ( s1 )
00237f18: 10 88 08 0c           jal 00222040
00237f1c: 46 a3 00 46           _mov.S f13, f20
00237f20: 80 3f 01 3c           lui at, 0x3f80
00237f24: 00 60 81 44           mtc1 at, f12
00237f28: 86 05 00 46           mov.S f22, f0
00237f2c: dc c7 08 0c           jal 00231f70
00237f30: 2d 20 00 00           _move a0, zero
00237f34: 16 00 01 3c           lui at, 0x16
00237f38: 64 ed 20 c4           lwc1 f0, -0x129c ( at )
00237f3c: 2d 20 00 00           move a0, zero
00237f40: 16 00 01 3c           lui at, 0x16
00237f44: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
00237f48: e5 3b 01 3c           lui at, 0x3be5
00237f4c: 42 60 21 34           ori at, at, 0x6042
00237f50: 00 60 81 44           mtc1 at, f12
00237f54: a3 3d 01 3c           lui at, 0x3da3
00237f58: 0a d7 21 34           ori at, at, 0xd70a
00237f5c: 00 68 81 44           mtc1 at, f13
00237f60: a7 40 01 3c           lui at, 0x40a7
00237f64: 36 8d 21 34           ori at, at, 0x8d36
00237f68: 00 70 81 44           mtc1 at, f14
00237f6c: 02 03 0c 46           mul.S f12, f0, f12
00237f70: 42 03 0d 46           mul.S f13, f0, f13
00237f74: 24 c9 08 0c           jal 00232490
00237f78: 82 0b 0e 46           _mul.S f14, f1, f14
00237f7c: 84 01 20 c6           lwc1 f0, 0x184 ( s1 )
00237f80: f4 08 24 26           addiu a0, s1, 0x8f4
00237f84: 9e 83 08 0c           jal 00220e78
00237f88: ec 08 20 e6           _swc1 f0, 0x8ec ( s1 )
00237f8c: 88 20 23 8e           lw v1, 0x2088 ( s1 )
00237f90: 01 00 02 24           li v0, 0x1
00237f94: 05 00 62 54           bnel v1, v0, 00237fac
00237f98: 84 20 23 8e           _lw v1, 0x2084 ( s1 )
00237f9c: c0 40 01 3c           lui at, 0x40c0
00237fa0: 00 08 81 44           mtc1 at, f1
00237fa4: 16 00 00 10           b 00238000
00237fa8: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
00237fac: 35 00 02 24           li v0, 0x35
00237fb0: 11 00 62 14           bne v1, v0, 00237ff8
00237fb4: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
00237fb8: a0 01 02 8e           lw v0, 0x1a0 ( s0 )
00237fbc: 0a 00 42 30           andi v0, v0, 0xa
00237fc0: 05 00 40 10           beq v0, zero, 00237fd8
00237fc4: 00 00 00 00           _nop 
00237fc8: e0 40 01 3c           lui at, 0x40e0
00237fcc: 00 08 81 44           mtc1 at, f1
00237fd0: 0d 00 00 10           b 00238008
00237fd4: 02 00 01 46           _mul.S f0, f0, f1
00237fd8: e0 40 01 3c           lui at, 0x40e0
00237fdc: 00 08 81 44           mtc1 at, f1
00237fe0: cc 3e 01 3c           lui at, 0x3ecc
00237fe4: cd cc 21 34           ori at, at, 0xcccd
00237fe8: 00 10 81 44           mtc1 at, f2
00237fec: 02 00 01 46           mul.S f0, f0, f1
00237ff0: 05 00 00 10           b 00238008
00237ff4: 02 00 02 46           _mul.S f0, f0, f2
00237ff8: 40 40 01 3c           lui at, 0x4040
00237ffc: 00 08 81 44           mtc1 at, f1
00238000: 00 00 00 00           nop 
00238004: 02 00 01 46           mul.S f0, f0, f1
00238008: 90 01 20 e6           swc1 f0, 0x190 ( s1 )
0023800c: 40 c9 63 26           addiu v1, s3, -0x36c0
00238010: 50 f3 a4 26           addiu a0, s5, -0xcb0
00238014: a0 01 62 8c           lw v0, 0x1a0 ( v1 )
00238018: c0 00 42 30           andi v0, v0, 0xc0
0023801c: 05 00 40 14           bne v0, zero, 00238034
00238020: 9c 22 82 c4           _lwc1 f2, 0x229c ( a0 )
00238024: 88 20 83 8c           lw v1, 0x2088 ( a0 )
00238028: 01 00 02 24           li v0, 0x1
0023802c: 09 00 62 14           bne v1, v0, 00238054
00238030: 50 f3 a2 26           _addiu v0, s5, -0xcb0
00238034: 80 3f 01 3c           lui at, 0x3f80
00238038: 00 00 81 44           mtc1 at, f0
0023803c: 00 00 00 00           nop 
00238040: 34 10 00 46           c.lt.S f2, f0
00238044: 00 00 00 00           nop 
00238048: 01 00 03 45           bc1tl 00238050
0023804c: 86 00 00 46           _mov.S f2, f0
00238050: 50 f3 a2 26           addiu v0, s5, -0xcb0
00238054: 19 3e 01 3c           lui at, 0x3e19
00238058: 9a 99 21 34           ori at, at, 0x999a
0023805c: 00 08 81 44           mtc1 at, f1
00238060: 9c 22 40 c4           lwc1 f0, 0x229c ( v0 )
00238064: 34 08 00 46           c.lt.S f1, f0
00238068: 00 00 00 00           nop 
0023806c: 11 00 00 45           bc1f 002380b4
00238070: 50 f3 a4 26           _addiu a0, s5, -0xcb0
00238074: 84 20 43 8c           lw v1, 0x2084 ( v0 )
00238078: 35 00 02 24           li v0, 0x35
0023807c: b3 3e 01 3c           lui at, 0x3eb3
00238080: 33 33 21 34           ori at, at, 0x3333
00238084: 00 00 81 44           mtc1 at, f0
00238088: 04 00 62 14           bne v1, v0, 0023809c
0023808c: 00 00 00 00           _nop 
00238090: cc 3e 01 3c           lui at, 0x3ecc
00238094: cd cc 21 34           ori at, at, 0xcccd
00238098: 00 00 81 44           mtc1 at, f0
0023809c: 00 00 00 00           nop 
002380a0: 34 10 00 46           c.lt.S f2, f0
002380a4: 00 00 00 00           nop 
002380a8: 01 00 03 45           bc1tl 002380b0
002380ac: 86 00 00 46           _mov.S f2, f0
002380b0: 50 f3 a4 26           addiu a0, s5, -0xcb0
002380b4: 35 00 03 24           li v1, 0x35
002380b8: 84 20 82 8c           lw v0, 0x2084 ( a0 )
002380bc: 07 00 43 54           bnel v0, v1, 002380dc
002380c0: 90 01 80 c4           _lwc1 f0, 0x190 ( a0 )
002380c4: 40 c9 63 26           addiu v1, s3, -0x36c0
002380c8: a0 01 62 8c           lw v0, 0x1a0 ( v1 )
002380cc: 0a 00 42 30           andi v0, v0, 0xa
002380d0: 05 00 40 14           bne v0, zero, 002380e8
002380d4: 14 00 02 3c           _lui v0, 0x14
002380d8: 90 01 80 c4           lwc1 f0, 0x190 ( a0 )
002380dc: 02 00 02 46           mul.S f0, f0, f2
002380e0: 90 01 80 e4           swc1 f0, 0x190 ( a0 )
002380e4: 14 00 02 3c           lui v0, 0x14
002380e8: 40 fc 50 24           addiu s0, v0, -0x3c0
002380ec: 9e 83 08 0c           jal 00220e78
002380f0: 2d 20 00 02           _move a0, s0
002380f4: 4e 00 40 10           beq v0, zero, 00238230
002380f8: 10 f7 12 26           _addiu s2, s0, -0x8f0
002380fc: 2d 30 a0 03           move a2, sp
00238100: 80 20 44 8e           lw a0, 0x2080 ( s2 )
00238104: 6a 91 09 0c           jal 002645a8
00238108: 04 00 05 24           _li a1, 0x4
0023810c: 80 20 46 8e           lw a2, 0x2080 ( s2 )
00238110: a9 14 00 70           clear v0
00238114: cc 3e 01 3c           lui at, 0x3ecc
00238118: cd cc 21 34           ori at, at, 0xcccd
0023811c: 00 00 81 44           mtc1 at, f0
00238120: 20 00 b1 27           addiu s1, sp, 0x20
00238124: 20 00 a2 7f           sq v0, 0x20 ( sp )
00238128: c0 00 c6 24           addiu a2, a2, 0xc0
0023812c: 2d 20 20 02           move a0, s1
00238130: 20 00 a0 e7           swc1 f0, 0x20 ( sp )
00238134: 78 85 08 0c           jal 002215e0
00238138: 2d 28 20 02           _move a1, s1
0023813c: 2d 20 a0 03           move a0, sp
00238140: 2d 28 a0 03           move a1, sp
00238144: 62 84 08 0c           jal 00221188
00238148: 2d 30 20 02           _move a2, s1
0023814c: 10 f8 03 26           addiu v1, s0, -0x7f0
00238150: 10 00 b0 27           addiu s0, sp, 0x10
00238154: 00 00 62 78           lq v0, 0x0 ( v1 )
00238158: 00 00 02 7e           sq v0, 0x0 ( s0 )
0023815c: 16 00 01 3c           lui at, 0x16
00238160: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
00238164: 2d 20 20 02           move a0, s1
00238168: c0 3f 01 3c           lui at, 0x3fc0
0023816c: 00 60 81 44           mtc1 at, f12
00238170: 2d 28 20 02           move a1, s1
00238174: 04 85 08 0c           jal 00221410
00238178: 02 03 0c 46           _mul.S f12, f0, f12
0023817c: 2d 30 20 02           move a2, s1
00238180: 2d 20 00 02           move a0, s0
00238184: 62 84 08 0c           jal 00221188
00238188: 2d 28 00 02           _move a1, s0
0023818c: 16 00 01 3c           lui at, 0x16
00238190: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
00238194: 2d 20 a0 03           move a0, sp
00238198: 18 00 a1 c7           lwc1 f1, 0x18 ( sp )
0023819c: 2d 28 00 02           move a1, s0
002381a0: 00 00 00 46           add.S f0, f0, f0
002381a4: c4 46 01 3c           lui at, 0x46c4
002381a8: 00 e0 21 34           ori at, at, 0xe000
002381ac: 00 60 81 44           mtc1 at, f12
002381b0: 80 bf 01 3c           lui at, 0xbf80
002381b4: 00 68 81 44           mtc1 at, f13
002381b8: 40 08 00 46           add.S f1, f1, f0
002381bc: 38 10 0a 0c           jal 002840e0
002381c0: 18 00 a1 e7           _swc1 f1, 0x18 ( sp )
002381c4: 4c b2 09 0c           jal 0026c930
002381c8: 64 00 04 24           _li a0, 0x64
002381cc: 00 08 82 44           mtc1 v0, f1
002381d0: 00 00 00 00           nop 
002381d4: 60 08 80 46           cvt.s.W f1, f1
002381d8: 20 42 01 3c           lui at, 0x4220
002381dc: 00 00 81 44           mtc1 at, f0
002381e0: 00 00 00 00           nop 
002381e4: 34 08 00 46           c.lt.S f1, f0
002381e8: 00 00 00 00           nop 
002381ec: 06 00 00 45           bc1f 00238208
002381f0: 00 00 00 00           _nop 
002381f4: 8c 83 08 0c           jal 00220e30
002381f8: 04 00 04 24           _li a0, 0x4
002381fc: 2d 80 40 00           move s0, v0
00238200: 05 00 00 10           b 00238218
00238204: 0b 00 04 24           _li a0, 0xb
00238208: 8c 83 08 0c           jal 00220e30
0023820c: 28 00 04 24           _li a0, 0x28
00238210: 2d 80 40 00           move s0, v0
00238214: 5a 00 04 24           li a0, 0x5a
00238218: 8c 83 08 0c           jal 00220e30
0023821c: 00 00 00 00           _nop 
00238220: 2d 20 00 02           move a0, s0
00238224: 5c b2 09 0c           jal 0026c970
00238228: 2d 28 40 00           _move a1, v0
0023822c: f0 08 42 ae           sw v0, 0x8f0 ( s2 )
00238230: 50 f3 b0 26           addiu s0, s5, -0xcb0
00238234: 35 00 03 24           li v1, 0x35
00238238: 84 20 02 8e           lw v0, 0x2084 ( s0 )
0023823c: 79 00 43 14           bne v0, v1, 00238424
00238240: 18 00 17 3c           _lui s7, 0x18
00238244: aa 83 08 0c           jal 00220ea8
00238248: f8 08 04 26           _addiu a0, s0, 0x8f8
0023824c: 68 00 40 10           beq v0, zero, 002383f0
00238250: 50 f3 a2 26           _addiu v0, s5, -0xcb0
00238254: 80 11 14 8e           lw s4, 0x1180 ( s0 )
00238258: 64 00 80 12           beq s4, zero, 002383ec
0023825c: 61 02 02 24           _li v0, 0x261
00238260: a6 00 83 86           lh v1, 0xa6 ( s4 )
00238264: 62 00 62 14           bne v1, v0, 002383f0
00238268: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023826c: 2d 90 00 02           move s2, s0
00238270: 00 a8 80 44           clear f21
00238274: f5 3c 01 3c           lui at, 0x3cf5
00238278: 8f c2 21 34           ori at, at, 0xc28f
0023827c: 00 a0 81 44           mtc1 at, f20
00238280: 00 01 56 26           addiu s6, s2, 0x100
00238284: 2d 88 00 00           move s1, zero
00238288: 20 00 b3 27           addiu s3, sp, 0x20
0023828c: 10 00 b0 27           addiu s0, sp, 0x10
00238290: c2 2f 11 00           srl a1, s1, 0x1f
00238294: 00 00 00 00           nop 
00238298: 2d 30 a0 03           move a2, sp
0023829c: 21 28 25 02           addu a1, s1, a1
002382a0: 2d 20 80 02           move a0, s4
002382a4: 43 28 05 00           sra a1, a1, 0x1
002382a8: 40 28 05 00           sll a1, a1, 0x1
002382ac: 6a 91 09 0c           jal 002645a8
002382b0: 23 28 25 02           _subu a1, s1, a1
002382b4: 80 20 46 8e           lw a2, 0x2080 ( s2 )
002382b8: a9 24 00 70           clear a0
002382bc: 19 be 01 3c           lui at, 0xbe19
002382c0: 9a 99 21 34           ori at, at, 0x999a
002382c4: 00 00 81 44           mtc1 at, f0
002382c8: 2d 28 60 02           move a1, s3
002382cc: 20 00 a4 7f           sq a0, 0x20 ( sp )
002382d0: c0 00 c6 24           addiu a2, a2, 0xc0
002382d4: 20 00 a0 e7           swc1 f0, 0x20 ( sp )
002382d8: 78 85 08 0c           jal 002215e0
002382dc: 2d 20 60 02           _move a0, s3
002382e0: 2d 20 a0 03           move a0, sp
002382e4: 2d 28 a0 03           move a1, sp
002382e8: 62 84 08 0c           jal 00221188
002382ec: 2d 30 60 02           _move a2, s3
002382f0: 06 ab 00 46           mov.S f12, f21
002382f4: 72 b2 09 0c           jal 0026c9c8
002382f8: 46 a3 00 46           _mov.S f13, f20
002382fc: 00 00 a1 c7           lwc1 f1, 0x0 ( sp )
00238300: 06 ab 00 46           mov.S f12, f21
00238304: 46 a3 00 46           mov.S f13, f20
00238308: 40 08 00 46           add.S f1, f1, f0
0023830c: 72 b2 09 0c           jal 0026c9c8
00238310: 00 00 a1 e7           _swc1 f1, 0x0 ( sp )
00238314: 04 00 a1 c7           lwc1 f1, 0x4 ( sp )
00238318: 06 ab 00 46           mov.S f12, f21
0023831c: 46 a3 00 46           mov.S f13, f20
00238320: 40 08 00 46           add.S f1, f1, f0
00238324: 72 b2 09 0c           jal 0026c9c8
00238328: 04 00 a1 e7           _swc1 f1, 0x4 ( sp )
0023832c: 08 00 a1 c7           lwc1 f1, 0x8 ( sp )
00238330: 40 08 00 46           add.S f1, f1, f0
00238334: 08 00 a1 e7           swc1 f1, 0x8 ( sp )
00238338: 00 00 c2 7a           lq v0, 0x0 ( s6 )
0023833c: 00 00 02 7e           sq v0, 0x0 ( s0 )
00238340: 16 00 01 3c           lui at, 0x16
00238344: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
00238348: 2d 28 00 02           move a1, s0
0023834c: 40 bf 01 3c           lui at, 0xbf40
00238350: 00 60 81 44           mtc1 at, f12
00238354: 2d 20 00 02           move a0, s0
00238358: 94 00 4e c6           lwc1 f14, 0x94 ( s2 )
0023835c: 01 00 31 26           addiu s1, s1, 0x1
00238360: 02 03 0c 46           mul.S f12, f0, f12
00238364: fc de 09 0c           jal 00277bf0
00238368: 98 00 4d c6           _lwc1 f13, 0x98 ( s2 )
0023836c: 8c 83 08 0c           jal 00220e30
00238370: 05 00 04 24           _li a0, 0x5
00238374: e0 40 01 3c           lui at, 0x40e0
00238378: 00 08 81 44           mtc1 at, f1
0023837c: 00 10 82 44           mtc1 v0, f2
00238380: 00 00 00 00           nop 
00238384: a0 10 80 46           cvt.s.W f2, f2
00238388: 16 00 01 3c           lui at, 0x16
0023838c: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
00238390: 94 01 4c c6           lwc1 f12, 0x194 ( s2 )
00238394: 02 00 01 46           mul.S f0, f0, f1
00238398: 01 03 0c 46           sub.S f12, f0, f12
0023839c: 03 63 00 46           div.S f12, f12, f0
002383a0: 58 88 08 0c           jal 00222160
002383a4: 02 63 02 46           _mul.S f12, f12, f2
002383a8: c4 45 01 3c           lui at, 0x45c4
002383ac: 00 e0 21 34           ori at, at, 0xe000
002383b0: 00 60 81 44           mtc1 at, f12
002383b4: 13 46 01 3c           lui at, 0x4613
002383b8: 00 a8 21 34           ori at, at, 0xa800
002383bc: 00 68 81 44           mtc1 at, f13
002383c0: 72 b2 09 0c           jal 0026c9c8
002383c4: f8 08 42 a6           _sh v0, 0x8f8 ( s2 )
002383c8: 80 bf 01 3c           lui at, 0xbf80
002383cc: 00 68 81 44           mtc1 at, f13
002383d0: 06 03 00 46           mov.S f12, f0
002383d4: 2d 20 a0 03           move a0, sp
002383d8: 38 10 0a 0c           jal 002840e0
002383dc: 2d 28 00 02           _move a1, s0
002383e0: 04 00 23 2a           slti v1, s1, 0x4
002383e4: ac ff 60 14           bne v1, zero, 00238298
002383e8: c2 2f 11 00           _srl a1, s1, 0x1f
002383ec: 50 f3 a2 26           addiu v0, s5, -0xcb0
002383f0: 35 00 04 24           li a0, 0x35
002383f4: 84 20 43 8c           lw v1, 0x2084 ( v0 )
002383f8: 0c 00 64 14           bne v1, a0, 0023842c
002383fc: 70 81 8d c7           _lwc1 f13, -0x7e90 ( gp )
00238400: 50 41 01 3c           lui at, 0x4150
00238404: 00 60 81 44           mtc1 at, f12
00238408: 00 41 01 3c           lui at, 0x4100
0023840c: 00 00 81 44           mtc1 at, f0
00238410: 02 6b 0c 46           mul.S f12, f13, f12
00238414: ba c9 08 0c           jal 002326e8
00238418: 42 6b 00 46           _mul.S f13, f13, f0
0023841c: 0b 00 00 10           b 0023844c
00238420: 50 f3 b0 26           _addiu s0, s5, -0xcb0
00238424: 16 00 01 3c           lui at, 0x16
00238428: 70 ed 2d c4           lwc1 f13, -0x1290 ( at )
0023842c: e0 40 01 3c           lui at, 0x40e0
00238430: 00 60 81 44           mtc1 at, f12
00238434: 80 40 01 3c           lui at, 0x4080
00238438: 00 00 81 44           mtc1 at, f0
0023843c: 02 6b 0c 46           mul.S f12, f13, f12
00238440: ba c9 08 0c           jal 002326e8
00238444: 42 6b 00 46           _mul.S f13, f13, f0
00238448: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023844c: 00 a0 80 44           clear f20
00238450: 94 00 0c c6           lwc1 f12, 0x94 ( s0 )
00238454: 35 00 11 24           li s1, 0x35
00238458: 46 a3 00 46           mov.S f13, f20
0023845c: fe 87 08 0c           jal 00221ff8
00238460: 07 63 00 46           _neg.S f12, f12
00238464: 84 20 03 8e           lw v1, 0x2084 ( s0 )
00238468: 08 00 71 14           bne v1, s1, 0023848c
0023846c: 46 05 00 46           _mov.S f21, f0
00238470: 98 00 0d c6           lwc1 f13, 0x98 ( s0 )
00238474: e0 00 04 26           addiu a0, s0, 0xe0
00238478: 94 01 0c c6           lwc1 f12, 0x194 ( s0 )
0023847c: d4 de 09 0c           jal 00277b50
00238480: 86 ab 00 46           _mov.S f14, f21
00238484: 47 00 00 10           b 002385a4
00238488: 00 00 00 00           _nop 
0023848c: 33 00 02 24           li v0, 0x33
00238490: 22 00 62 14           bne v1, v0, 0023851c
00238494: 34 00 02 24           _li v0, 0x34
00238498: 18 00 04 3c           lui a0, 0x18
0023849c: 1e 00 05 24           li a1, 0x1e
002384a0: c6 a9 08 0c           jal 0022a718
002384a4: 40 c4 84 24           _addiu a0, a0, -0x3bc0
002384a8: 94 01 01 c6           lwc1 f1, 0x194 ( s0 )
002384ac: a0 40 01 3c           lui at, 0x40a0
002384b0: 00 10 81 44           mtc1 at, f2
002384b4: 42 08 00 46           mul.S f1, f1, f0
002384b8: 90 20 02 8e           lw v0, 0x2090 ( s0 )
002384bc: 0f 00 51 14           bne v0, s1, 002384fc
002384c0: 02 0d 02 46           _mul.S f20, f1, f2
002384c4: 8c 83 08 0c           jal 00220e30
002384c8: 0f 00 04 24           _li a0, 0xf
002384cc: 98 01 03 8e           lw v1, 0x198 ( s0 )
002384d0: 2a 18 62 00           slt v1, v1, v0
002384d4: 09 00 60 10           beq v1, zero, 002384fc
002384d8: 6c 81 81 c7           _lwc1 f1, -0x7e94 ( gp )
002384dc: 90 40 01 3c           lui at, 0x4090
002384e0: 00 00 81 44           mtc1 at, f0
002384e4: 00 00 00 00           nop 
002384e8: 42 08 00 46           mul.S f1, f1, f0
002384ec: 34 a0 01 46           c.lt.S f20, f1
002384f0: 00 00 00 00           nop 
002384f4: 01 00 03 45           bc1tl 002384fc
002384f8: 06 0d 00 46           _mov.S f20, f1
002384fc: 14 00 04 3c           lui a0, 0x14
00238500: 06 a3 00 46           mov.S f12, f20
00238504: 30 f4 84 24           addiu a0, a0, -0xbd0
00238508: 86 ab 00 46           mov.S f14, f21
0023850c: d4 de 09 0c           jal 00277b50
00238510: b8 ff 8d c4           _lwc1 f13, -0x48 ( a0 )
00238514: 23 00 00 10           b 002385a4
00238518: 00 00 00 00           _nop 
0023851c: 21 00 62 14           bne v1, v0, 002385a4
00238520: 00 00 00 00           _nop 
00238524: ba 84 08 0c           jal 002212e8
00238528: 50 01 04 26           _addiu a0, s0, 0x150
0023852c: 90 20 02 8e           lw v0, 0x2090 ( s0 )
00238530: 0b 00 51 14           bne v0, s1, 00238560
00238534: 60 00 a0 e7           _swc1 f0, 0x60 ( sp )
00238538: 16 00 01 3c           lui at, 0x16
0023853c: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
00238540: 06 a3 00 46           mov.S f12, f20
00238544: 00 41 01 3c           lui at, 0x4100
00238548: 00 68 81 44           mtc1 at, f13
0023854c: 60 00 a4 27           addiu a0, sp, 0x60
00238550: ca c1 09 0c           jal 00270728
00238554: 42 03 0d 46           _mul.S f13, f0, f13
00238558: 0a 00 00 10           b 00238584
0023855c: 14 00 10 3c           _lui s0, 0x14
00238560: 16 00 01 3c           lui at, 0x16
00238564: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
00238568: 06 a3 00 46           mov.S f12, f20
0023856c: 80 40 01 3c           lui at, 0x4080
00238570: 00 68 81 44           mtc1 at, f13
00238574: 60 00 a4 27           addiu a0, sp, 0x60
00238578: ca c1 09 0c           jal 00270728
0023857c: 42 03 0d 46           _mul.S f13, f0, f13
00238580: 14 00 10 3c           lui s0, 0x14
00238584: 60 00 ac c7           lwc1 f12, 0x60 ( sp )
00238588: a0 f4 10 26           addiu s0, s0, -0xb60
0023858c: 2d 20 00 02           move a0, s0
00238590: 04 85 08 0c           jal 00221410
00238594: 2d 28 00 02           _move a1, s0
00238598: 90 ff 03 26           addiu v1, s0, -0x70
0023859c: 00 00 02 7a           lq v0, 0x0 ( s0 )
002385a0: 00 00 62 7c           sq v0, 0x0 ( v1 )
002385a4: 4c 3e 01 3c           lui at, 0x3e4c
002385a8: cd cc 21 34           ori at, at, 0xcccd
002385ac: 00 a0 81 44           mtc1 at, f20
002385b0: 5e ca 08 0c           jal 00232978
002385b4: 2d 20 00 00           _move a0, zero
002385b8: be 85 08 0c           jal 002216f8
002385bc: 06 ab 00 46           _mov.S f12, f21
002385c0: 50 f3 a4 26           addiu a0, s5, -0xcb0
002385c4: e0 c0 01 3c           lui at, 0xc0e0
002385c8: 00 18 81 44           mtc1 at, f3
002385cc: ec 08 81 c4           lwc1 f1, 0x8ec ( a0 )
002385d0: e4 08 85 24           addiu a1, a0, 0x8e4
002385d4: 16 00 01 3c           lui at, 0x16
002385d8: 6c ed 22 c4           lwc1 f2, -0x1294 ( at )
002385dc: 90 00 84 24           addiu a0, a0, 0x90
002385e0: 42 08 00 46           mul.S f1, f1, f0
002385e4: 9c 3f 01 3c           lui at, 0x3f9c
002385e8: aa 61 21 34           ori at, at, 0x61aa
002385ec: 00 78 81 44           mtc1 at, f15
002385f0: 2e 3e 01 3c           lui at, 0x3e2e
002385f4: 7b 14 21 34           ori at, at, 0x147b
002385f8: 00 70 81 44           mtc1 at, f14
002385fc: 2d 30 00 00           move a2, zero
00238600: c2 13 0f 46           mul.S f15, f2, f15
00238604: e5 3b 01 3c           lui at, 0x3be5
00238608: 42 60 21 34           ori at, at, 0x6042
0023860c: 00 68 81 44           mtc1 at, f13
00238610: 42 0d 03 46           mul.S f21, f1, f3
00238614: d6 c2 09 0c           jal 00270b58
00238618: 06 ab 00 46           _mov.S f12, f21
0023861c: 13 3c 01 3c           lui at, 0x3c13
00238620: bc 74 21 34           ori at, at, 0x74bc
00238624: 00 60 81 44           mtc1 at, f12
00238628: 61 3e 01 3c           lui at, 0x3e61
0023862c: ae 47 21 34           ori at, at, 0x47ae
00238630: 00 68 81 44           mtc1 at, f13
00238634: 78 ad 08 0c           jal 0022b5e0
00238638: 00 00 00 00           _nop 
0023863c: 23 3d 01 3c           lui at, 0x3d23
00238640: 0a d7 21 34           ori at, at, 0xd70a
00238644: 00 60 81 44           mtc1 at, f12
00238648: 7e ad 08 0c           jal 0022b5f8
0023864c: 46 a3 00 46           _mov.S f13, f20
00238650: a3 3c 01 3c           lui at, 0x3ca3
00238654: 0a d7 21 34           ori at, at, 0xd70a
00238658: 00 60 81 44           mtc1 at, f12
0023865c: 84 ad 08 0c           jal 0022b610
00238660: 46 a3 00 46           _mov.S f13, f20
00238664: 3c 42 01 3c           lui at, 0x423c
00238668: 00 10 81 44           mtc1 at, f2
0023866c: 00 ab e2 26           addiu v0, s7, -0x5500
00238670: c0 3f 01 3c           lui at, 0x3fc0
00238674: 00 08 81 44           mtc1 at, f1
00238678: 82 b0 02 46           mul.S f2, f22, f2
0023867c: b3 3f 01 3c           lui at, 0x3fb3
00238680: 33 33 21 34           ori at, at, 0x3333
00238684: 00 00 81 44           mtc1 at, f0
00238688: 5f 3f 01 3c           lui at, 0x3f5f
0023868c: f3 66 21 34           ori at, at, 0x66f3
00238690: 00 18 81 44           mtc1 at, f3
00238694: 42 a8 01 46           mul.S f1, f21, f1
00238698: 02 a8 00 46           mul.S f0, f21, f0
0023869c: 34 18 02 46           c.lt.S f3, f2
002386a0: 14 01 42 e4           swc1 f2, 0x114 ( v0 )
002386a4: 18 01 41 e4           swc1 f1, 0x118 ( v0 )
002386a8: 03 00 00 45           bc1f 002386b8
002386ac: 10 01 40 e4           _swc1 f0, 0x110 ( v0 )
002386b0: 09 00 00 10           b 002386d8
002386b4: 14 01 43 e4           _swc1 f3, 0x114 ( v0 )
002386b8: 5f bf 01 3c           lui at, 0xbf5f
002386bc: f3 66 21 34           ori at, at, 0x66f3
002386c0: 00 00 81 44           mtc1 at, f0
002386c4: 00 00 00 00           nop 
002386c8: 34 10 00 46           c.lt.S f2, f0
002386cc: 00 00 00 00           nop 
002386d0: 01 00 03 45           bc1tl 002386d8
002386d4: 14 01 40 e4           _swc1 f0, 0x114 ( v0 )
002386d8: 20 42 01 3c           lui at, 0x4220
002386dc: 00 08 81 44           mtc1 at, f1
002386e0: 00 ab e2 26           addiu v0, s7, -0x5500
002386e4: 8c 3f 01 3c           lui at, 0x3f8c
002386e8: cd cc 21 34           ori at, at, 0xcccd
002386ec: 00 00 81 44           mtc1 at, f0
002386f0: 42 b0 01 46           mul.S f1, f22, f1
002386f4: f5 3c 01 3c           lui at, 0x3cf5
002386f8: 8f c2 21 34           ori at, at, 0xc28f
002386fc: 00 18 81 44           mtc1 at, f3
00238700: 02 a8 00 46           mul.S f0, f21, f0
00238704: 61 3e 01 3c           lui at, 0x3e61
00238708: ae 47 21 34           ori at, at, 0x47ae
0023870c: 00 10 81 44           mtc1 at, f2
00238710: 14 04 43 e4           swc1 f3, 0x414 ( v0 )
00238714: 18 04 42 e4           swc1 f2, 0x418 ( v0 )
00238718: d8 03 40 e4           swc1 f0, 0x3d8 ( v0 )
0023871c: d4 03 41 e4           swc1 f1, 0x3d4 ( v0 )
00238720: 64 03 43 e4           swc1 f3, 0x364 ( v0 )
00238724: 68 03 42 e4           swc1 f2, 0x368 ( v0 )
00238728: 24 03 41 e4           swc1 f1, 0x324 ( v0 )
0023872c: 30 0f 00 10           b 0023c3f0
00238730: 28 03 40 e4           _swc1 f0, 0x328 ( v0 )
00238734: 50 f3 b0 26           addiu s0, s5, -0xcb0
00238738: 03 00 02 24           li v0, 0x3
0023873c: 98 01 03 8e           lw v1, 0x198 ( s0 )
00238740: 0a 00 04 24           li a0, 0xa
00238744: 01 00 40 50           beql v0, zero, 0023874c
00238748: cd 01 00 00           _break 0x7
0023874c: 08 00 06 24           li a2, 0x8
00238750: 1a 00 62 00           div v1, v0
00238754: 2d 28 00 00           move a1, zero
00238758: e0 00 11 26           addiu s1, s0, 0xe0
0023875c: 12 18 00 00           mflo v1
00238760: 23 20 83 00           subu a0, a0, v1
00238764: 09 00 82 28           slti v0, a0, 0x9
00238768: 50 ac 08 0c           jal 0022b140
0023876c: 0a 20 c2 00           _movz a0, a2, v0
00238770: 2d 20 20 02           move a0, s1
00238774: c6 84 08 0c           jal 00221318
00238778: e8 00 00 ae           _sw zero, 0xe8 ( s0 )
0023877c: 16 00 01 3c           lui at, 0x16
00238780: 60 ed 2c c4           lwc1 f12, -0x12a0 ( at )
00238784: 2d 20 20 02           move a0, s1
00238788: a3 bd 01 3c           lui at, 0xbda3
0023878c: 08 d7 21 34           ori at, at, 0xd708
00238790: 00 08 81 44           mtc1 at, f1
00238794: 2d 28 80 00           move a1, a0
00238798: 02 63 01 46           mul.S f12, f12, f1
0023879c: 02 63 00 46           mul.S f12, f12, f0
002387a0: 44 85 08 0c           jal 00221510
002387a4: 00 63 00 46           _add.S f12, f12, f0
002387a8: 5e ca 08 0c           jal 00232978
002387ac: 2d 20 00 00           _move a0, zero
002387b0: 10 0f 00 10           b 0023c3f4
002387b4: 50 f3 a3 26           _addiu v1, s5, -0xcb0
002387b8: 1e 00 05 24           li a1, 0x1e
002387bc: 10 ab 08 0c           jal 0022ac40
002387c0: 0f 00 04 24           _li a0, 0xf
002387c4: 50 f3 a2 26           addiu v0, s5, -0xcb0
002387c8: e0 00 50 24           addiu s0, v0, 0xe0
002387cc: e8 00 40 ac           sw zero, 0xe8 ( v0 )
002387d0: c6 84 08 0c           jal 00221318
002387d4: 2d 20 00 02           _move a0, s0
002387d8: a3 bd 01 3c           lui at, 0xbda3
002387dc: 08 d7 21 34           ori at, at, 0xd708
002387e0: 00 08 81 44           mtc1 at, f1
002387e4: 2d 20 00 02           move a0, s0
002387e8: 16 00 01 3c           lui at, 0x16
002387ec: 60 ed 2c c4           lwc1 f12, -0x12a0 ( at )
002387f0: 2d 28 80 00           move a1, a0
002387f4: 02 63 01 46           mul.S f12, f12, f1
002387f8: 02 63 00 46           mul.S f12, f12, f0
002387fc: 44 85 08 0c           jal 00221510
00238800: 00 63 00 46           _add.S f12, f12, f0
00238804: 3f 01 00 10           b 00238d04
00238808: 00 00 00 00           _nop 
0023880c: 14 00 02 3c           lui v0, 0x14
00238810: a0 f4 50 24           addiu s0, v0, -0xb60
00238814: ba 84 08 0c           jal 002212e8
00238818: 2d 20 00 02           _move a0, s0
0023881c: 16 00 01 3c           lui at, 0x16
00238820: 70 ed 21 c4           lwc1 f1, -0x1290 ( at )
00238824: 64 00 a4 27           addiu a0, sp, 0x64
00238828: 80 40 01 3c           lui at, 0x4080
0023882c: 00 68 81 44           mtc1 at, f13
00238830: 00 60 80 44           clear f12
00238834: 42 0b 0d 46           mul.S f13, f1, f13
00238838: ca c1 09 0c           jal 00270728
0023883c: 64 00 a0 e7           _swc1 f0, 0x64 ( sp )
00238840: 64 00 ac c7           lwc1 f12, 0x64 ( sp )
00238844: 2d 20 00 02           move a0, s0
00238848: 04 85 08 0c           jal 00221410
0023884c: 2d 28 00 02           _move a1, s0
00238850: 90 ff 03 26           addiu v1, s0, -0x70
00238854: 00 00 02 7a           lq v0, 0x0 ( s0 )
00238858: 00 00 62 7c           sq v0, 0x0 ( v1 )
0023885c: 9e 83 08 0c           jal 00220e78
00238860: a0 07 04 26           _addiu a0, s0, 0x7a0
00238864: 02 00 03 24           li v1, 0x2
00238868: 5a 00 43 54           bnel v0, v1, 002389d4
0023886c: 50 f3 b0 26           _addiu s0, s5, -0xcb0
00238870: b0 fe 12 26           addiu s2, s0, -0x150
00238874: 2d 30 a0 03           move a2, sp
00238878: 80 20 44 8e           lw a0, 0x2080 ( s2 )
0023887c: 6a 91 09 0c           jal 002645a8
00238880: 04 00 05 24           _li a1, 0x4
00238884: 80 20 46 8e           lw a2, 0x2080 ( s2 )
00238888: a9 14 00 70           clear v0
0023888c: cc 3e 01 3c           lui at, 0x3ecc
00238890: cd cc 21 34           ori at, at, 0xcccd
00238894: 00 00 81 44           mtc1 at, f0
00238898: 20 00 b1 27           addiu s1, sp, 0x20
0023889c: 20 00 a2 7f           sq v0, 0x20 ( sp )
002388a0: c0 00 c6 24           addiu a2, a2, 0xc0
002388a4: 2d 20 20 02           move a0, s1
002388a8: 20 00 a0 e7           swc1 f0, 0x20 ( sp )
002388ac: 78 85 08 0c           jal 002215e0
002388b0: 2d 28 20 02           _move a1, s1
002388b4: 2d 20 a0 03           move a0, sp
002388b8: 2d 28 a0 03           move a1, sp
002388bc: 62 84 08 0c           jal 00221188
002388c0: 2d 30 20 02           _move a2, s1
002388c4: b0 ff 03 26           addiu v1, s0, -0x50
002388c8: 10 00 b0 27           addiu s0, sp, 0x10
002388cc: 00 00 62 78           lq v0, 0x0 ( v1 )
002388d0: 00 00 02 7e           sq v0, 0x0 ( s0 )
002388d4: 16 00 01 3c           lui at, 0x16
002388d8: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
002388dc: 2d 20 20 02           move a0, s1
002388e0: c0 3f 01 3c           lui at, 0x3fc0
002388e4: 00 60 81 44           mtc1 at, f12
002388e8: 2d 28 20 02           move a1, s1
002388ec: 04 85 08 0c           jal 00221410
002388f0: 02 03 0c 46           _mul.S f12, f0, f12
002388f4: 2d 30 20 02           move a2, s1
002388f8: 2d 20 00 02           move a0, s0
002388fc: 62 84 08 0c           jal 00221188
00238900: 2d 28 00 02           _move a1, s0
00238904: 16 00 01 3c           lui at, 0x16
00238908: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023890c: 2d 20 a0 03           move a0, sp
00238910: 18 00 a1 c7           lwc1 f1, 0x18 ( sp )
00238914: 2d 28 00 02           move a1, s0
00238918: 00 00 00 46           add.S f0, f0, f0
0023891c: c4 46 01 3c           lui at, 0x46c4
00238920: 00 e0 21 34           ori at, at, 0xe000
00238924: 00 60 81 44           mtc1 at, f12
00238928: 80 bf 01 3c           lui at, 0xbf80
0023892c: 00 68 81 44           mtc1 at, f13
00238930: 40 08 00 46           add.S f1, f1, f0
00238934: 38 10 0a 0c           jal 002840e0
00238938: 18 00 a1 e7           _swc1 f1, 0x18 ( sp )
0023893c: 8c 83 08 0c           jal 00220e30
00238940: 28 00 04 24           _li a0, 0x28
00238944: 98 01 43 8e           lw v1, 0x198 ( s2 )
00238948: 2a 18 62 00           slt v1, v1, v0
0023894c: 11 00 60 10           beq v1, zero, 00238994
00238950: 00 00 00 00           _nop 
00238954: 8c 83 08 0c           jal 00220e30
00238958: 02 00 04 24           _li a0, 0x2
0023895c: 2d 80 40 00           move s0, v0
00238960: 8c 83 08 0c           jal 00220e30
00238964: 05 00 04 24           _li a0, 0x5
00238968: 2d 20 00 02           move a0, s0
0023896c: 5c b2 09 0c           jal 0026c970
00238970: 2d 28 40 00           _move a1, v0
00238974: 98 01 44 8e           lw a0, 0x198 ( s2 )
00238978: 05 00 03 24           li v1, 0x5
0023897c: 01 00 60 50           beql v1, zero, 00238984
00238980: cd 01 00 00           _break 0x7
00238984: 1a 00 83 00           div a0, v1
00238988: 12 20 00 00           mflo a0
0023898c: 0f 00 00 10           b 002389cc
00238990: 21 10 44 00           _addu v0, v0, a0
00238994: 8c 83 08 0c           jal 00220e30
00238998: 46 00 04 24           _li a0, 0x46
0023899c: 98 01 43 8e           lw v1, 0x198 ( s2 )
002389a0: 2a 10 43 00           slt v0, v0, v1
002389a4: 0b 00 40 10           beq v0, zero, 002389d4
002389a8: 50 f3 b0 26           _addiu s0, s5, -0xcb0
002389ac: 8c 83 08 0c           jal 00220e30
002389b0: 0a 00 04 24           _li a0, 0xa
002389b4: 2d 80 40 00           move s0, v0
002389b8: 8c 83 08 0c           jal 00220e30
002389bc: 14 00 04 24           _li a0, 0x14
002389c0: 2d 20 00 02           move a0, s0
002389c4: 5c b2 09 0c           jal 0026c970
002389c8: 2d 28 40 00           _move a1, v0
002389cc: f0 08 42 ae           sw v0, 0x8f0 ( s2 )
002389d0: 50 f3 b0 26           addiu s0, s5, -0xcb0
002389d4: 00 08 80 44           clear f1
002389d8: fc 08 00 c6           lwc1 f0, 0x8fc ( s0 )
002389dc: 34 08 00 46           c.lt.S f1, f0
002389e0: 00 00 00 00           nop 
002389e4: 01 00 03 45           bc1tl 002389ec
002389e8: fc 08 01 e6           _swc1 f1, 0x8fc ( s0 )
002389ec: 16 00 01 3c           lui at, 0x16
002389f0: 6c ed 2c c4           lwc1 f12, -0x1294 ( at )
002389f4: fc 08 04 26           addiu a0, s0, 0x8fc
002389f8: c0 3f 01 3c           lui at, 0x3fc0
002389fc: 00 68 81 44           mtc1 at, f13
00238a00: 16 00 01 3c           lui at, 0x16
00238a04: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
00238a08: 02 63 0d 46           mul.S f12, f12, f13
00238a0c: 42 03 0d 46           mul.S f13, f0, f13
00238a10: ca c1 09 0c           jal 00270728
00238a14: 07 63 00 46           _neg.S f12, f12
00238a18: fc 08 01 c6           lwc1 f1, 0x8fc ( s0 )
00238a1c: 74 0e 00 10           b 0023c3f0
00238a20: e8 00 01 e6           _swc1 f1, 0xe8 ( s0 )
00238a24: 50 f3 b0 26           addiu s0, s5, -0xcb0
00238a28: 37 00 03 24           li v1, 0x37
00238a2c: 84 20 02 8e           lw v0, 0x2084 ( s0 )
00238a30: 06 00 43 14           bne v0, v1, 00238a4c
00238a34: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
00238a38: 0f 00 04 24           li a0, 0xf
00238a3c: 10 ab 08 0c           jal 0022ac40
00238a40: 1e 00 05 24           _li a1, 0x1e
00238a44: 16 00 01 3c           lui at, 0x16
00238a48: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
00238a4c: c0 3f 01 3c           lui at, 0x3fc0
00238a50: 00 08 81 44           mtc1 at, f1
00238a54: 64 01 02 c6           lwc1 f2, 0x164 ( s0 )
00238a58: 02 00 01 46           mul.S f0, f0, f1
00238a5c: 34 00 02 46           c.lt.S f0, f2
00238a60: 00 00 00 00           nop 
00238a64: 03 00 00 45           bc1f 00238a74
00238a68: 04 00 04 24           _li a0, 0x4
00238a6c: d2 ab 08 0c           jal 0022af48
00238a70: 0c 00 05 24           _li a1, 0xc
00238a74: 84 20 03 8e           lw v1, 0x2084 ( s0 )
00238a78: 36 00 02 24           li v0, 0x36
00238a7c: 0b 00 62 54           bnel v1, v0, 00238aac
00238a80: 50 f3 b0 26           _addiu s0, s5, -0xcb0
00238a84: 64 01 01 c6           lwc1 f1, 0x164 ( s0 )
00238a88: 16 00 01 3c           lui at, 0x16
00238a8c: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
00238a90: 34 00 01 46           c.lt.S f0, f1
00238a94: 00 00 00 00           nop 
00238a98: 03 00 00 45           bc1f 00238aa8
00238a9c: 2d 20 00 00           _move a0, zero
00238aa0: 4e ab 08 0c           jal 0022ad38
00238aa4: 01 00 05 24           _li a1, 0x1
00238aa8: 50 f3 b0 26           addiu s0, s5, -0xcb0
00238aac: 0a 09 02 86           lh v0, 0x90a ( s0 )
00238ab0: 0a 00 40 10           beq v0, zero, 00238adc
00238ab4: 0a 09 03 96           _lhu v1, 0x90a ( s0 )
00238ab8: ff ff 62 24           addiu v0, v1, -0x1
00238abc: 2d 28 00 00           move a1, zero
00238ac0: 00 24 02 00           sll a0, v0, 0x10
00238ac4: 0a 09 02 a6           sh v0, 0x90a ( s0 )
00238ac8: c3 24 04 00           sra a0, a0, 0x13
00238acc: 06 00 03 24           li v1, 0x6
00238ad0: 07 00 82 28           slti v0, a0, 0x7
00238ad4: 50 ac 08 0c           jal 0022b140
00238ad8: 0a 20 62 00           _movz a0, v1, v0
00238adc: 16 00 01 3c           lui at, 0x16
00238ae0: 6c ed 2c c4           lwc1 f12, -0x1294 ( at )
00238ae4: 2d 20 00 00           move a0, zero
00238ae8: 40 40 01 3c           lui at, 0x4040
00238aec: 00 a0 81 44           mtc1 at, f20
00238af0: 19 3f 01 3c           lui at, 0x3f19
00238af4: 9a 99 21 34           ori at, at, 0x999a
00238af8: 00 00 81 44           mtc1 at, f0
00238afc: 02 63 14 46           mul.S f12, f12, f20
00238b00: dc c7 08 0c           jal 00231f70
00238b04: 90 0a 00 e6           _swc1 f0, 0xa90 ( s0 )
00238b08: 14 00 03 3c           lui v1, 0x14
00238b0c: 40 c9 64 24           addiu a0, v1, -0x36c0
00238b10: d4 01 82 8c           lw v0, 0x1d4 ( a0 )
00238b14: 0c 00 40 14           bne v0, zero, 00238b48
00238b18: 2d 98 60 00           _move s3, v1
00238b1c: 16 00 01 3c           lui at, 0x16
00238b20: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
00238b24: 00 3f 01 3c           lui at, 0x3f00
00238b28: 00 10 81 44           mtc1 at, f2
00238b2c: 02 00 14 46           mul.S f0, f0, f20
00238b30: 90 01 01 c6           lwc1 f1, 0x190 ( s0 )
00238b34: 02 00 02 46           mul.S f0, f0, f2
00238b38: 34 08 00 46           c.lt.S f1, f0
00238b3c: 00 00 00 00           nop 
00238b40: 01 00 03 45           bc1tl 00238b48
00238b44: 90 01 00 e6           _swc1 f0, 0x190 ( s0 )
00238b48: 16 00 01 3c           lui at, 0x16
00238b4c: 64 ed 20 c4           lwc1 f0, -0x129c ( at )
00238b50: 2d 20 00 00           move a0, zero
00238b54: 16 00 01 3c           lui at, 0x16
00238b58: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
00238b5c: e5 3b 01 3c           lui at, 0x3be5
00238b60: 42 60 21 34           ori at, at, 0x6042
00238b64: 00 60 81 44           mtc1 at, f12
00238b68: a3 3d 01 3c           lui at, 0x3da3
00238b6c: 0a d7 21 34           ori at, at, 0xd70a
00238b70: 00 68 81 44           mtc1 at, f13
00238b74: a7 40 01 3c           lui at, 0x40a7
00238b78: 36 8d 21 34           ori at, at, 0x8d36
00238b7c: 00 70 81 44           mtc1 at, f14
00238b80: 02 03 0c 46           mul.S f12, f0, f12
00238b84: 42 03 0d 46           mul.S f13, f0, f13
00238b88: 24 c9 08 0c           jal 00232490
00238b8c: 82 0b 0e 46           _mul.S f14, f1, f14
00238b90: 14 00 02 3c           lui v0, 0x14
00238b94: e8 f9 50 24           addiu s0, v0, -0x618
00238b98: 9e 83 08 0c           jal 00220e78
00238b9c: 2d 20 00 02           _move a0, s0
00238ba0: 68 f9 04 26           addiu a0, s0, -0x698
00238ba4: 36 00 03 24           li v1, 0x36
00238ba8: 84 20 82 8c           lw v0, 0x2084 ( a0 )
00238bac: 34 00 43 54           bnel v0, v1, 00238c80
00238bb0: 94 01 80 ac           _sw zero, 0x194 ( a0 )
00238bb4: 40 c9 62 26           addiu v0, s3, -0x36c0
00238bb8: d4 01 43 8c           lw v1, 0x1d4 ( v0 )
00238bbc: 0a 00 60 10           beq v1, zero, 00238be8
00238bc0: 50 f3 b0 26           _addiu s0, s5, -0xcb0
00238bc4: 98 06 82 8c           lw v0, 0x698 ( a0 )
00238bc8: 07 00 40 10           beq v0, zero, 00238be8
00238bcc: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
00238bd0: 40 40 01 3c           lui at, 0x4040
00238bd4: 00 08 81 44           mtc1 at, f1
00238bd8: 00 00 00 00           nop 
00238bdc: 02 00 01 46           mul.S f0, f0, f1
00238be0: 90 01 80 e4           swc1 f0, 0x190 ( a0 )
00238be4: 50 f3 b0 26           addiu s0, s5, -0xcb0
00238be8: 4a 84 08 0c           jal 00221128
00238bec: 88 01 0c c6           _lwc1 f12, 0x188 ( s0 )
00238bf0: 49 3f 01 3c           lui at, 0x3f49
00238bf4: db 0f 21 34           ori at, at, 0xfdb
00238bf8: 00 08 81 44           mtc1 at, f1
00238bfc: 00 00 00 00           nop 
00238c00: 34 08 00 46           c.lt.S f1, f0
00238c04: 00 00 00 00           nop 
00238c08: 01 00 03 45           bc1tl 00238c10
00238c0c: 90 01 00 ae           _sw zero, 0x190 ( s0 )
00238c10: 16 00 01 3c           lui at, 0x16
00238c14: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
00238c18: 80 40 01 3c           lui at, 0x4080
00238c1c: 00 60 81 44           mtc1 at, f12
00238c20: a0 40 01 3c           lui at, 0x40a0
00238c24: 00 68 81 44           mtc1 at, f13
00238c28: 02 03 0c 46           mul.S f12, f0, f12
00238c2c: ba c9 08 0c           jal 002326e8
00238c30: 42 03 0d 46           _mul.S f13, f0, f13
00238c34: 18 00 04 3c           lui a0, 0x18
00238c38: 1e 00 05 24           li a1, 0x1e
00238c3c: c6 a9 08 0c           jal 0022a718
00238c40: 40 c4 84 24           _addiu a0, a0, -0x3bc0
00238c44: 94 01 14 c6           lwc1 f20, 0x194 ( s0 )
00238c48: b0 40 01 3c           lui at, 0x40b0
00238c4c: 00 08 81 44           mtc1 at, f1
00238c50: 02 a5 00 46           mul.S f20, f20, f0
00238c54: 98 00 0c c6           lwc1 f12, 0x98 ( s0 )
00238c58: be 85 08 0c           jal 002216f8
00238c5c: 02 a5 01 46           _mul.S f20, f20, f1
00238c60: 98 00 0c c6           lwc1 f12, 0x98 ( s0 )
00238c64: 02 00 14 46           mul.S f0, f0, f20
00238c68: c4 85 08 0c           jal 00221710
00238c6c: e0 00 00 e6           _swc1 f0, 0xe0 ( s0 )
00238c70: 02 00 14 46           mul.S f0, f0, f20
00238c74: e8 00 00 ae           sw zero, 0xe8 ( s0 )
00238c78: 03 00 00 10           b 00238c88
00238c7c: e4 00 00 e6           _swc1 f0, 0xe4 ( s0 )
00238c80: 5c 84 08 0c           jal 00221170
00238c84: 48 fa 04 26           _addiu a0, s0, -0x5b8
00238c88: 50 f3 a4 26           addiu a0, s5, -0xcb0
00238c8c: 36 00 03 24           li v1, 0x36
00238c90: 84 20 82 8c           lw v0, 0x2084 ( a0 )
00238c94: 16 00 43 14           bne v0, v1, 00238cf0
00238c98: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
00238c9c: 9c 0a 82 8c           lw v0, 0xa9c ( a0 )
00238ca0: 13 00 40 14           bne v0, zero, 00238cf0
00238ca4: 00 00 00 00           _nop 
00238ca8: a8 0a 81 c4           lwc1 f1, 0xaa8 ( a0 )
00238cac: 00 00 80 44           clear f0
00238cb0: 00 00 00 00           nop 
00238cb4: 34 00 01 46           c.lt.S f0, f1
00238cb8: 00 00 00 00           nop 
00238cbc: 0c 00 00 45           bc1f 00238cf0
00238cc0: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
00238cc4: 20 41 01 3c           lui at, 0x4120
00238cc8: 00 00 81 44           mtc1 at, f0
00238ccc: 00 00 00 00           nop 
00238cd0: 34 08 00 46           c.lt.S f1, f0
00238cd4: 00 00 00 00           nop 
00238cd8: 03 00 00 45           bc1f 00238ce8
00238cdc: 04 00 04 24           _li a0, 0x4
00238ce0: 50 ac 08 0c           jal 0022b140
00238ce4: 01 00 05 24           _li a1, 0x1
00238ce8: 16 00 01 3c           lui at, 0x16
00238cec: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
00238cf0: 86 40 01 3c           lui at, 0x4086
00238cf4: 66 66 21 34           ori at, at, 0x6666
00238cf8: 00 60 81 44           mtc1 at, f12
00238cfc: 9e d9 08 0c           jal 00236678
00238d00: 02 03 0c 46           _mul.S f12, f0, f12
00238d04: 5e ca 08 0c           jal 00232978
00238d08: 2d 20 00 00           _move a0, zero
00238d0c: 1e 03 09 0c           jal 00240c78
00238d10: 00 00 00 00           _nop 
00238d14: b7 0d 00 10           b 0023c3f4
00238d18: 50 f3 a3 26           _addiu v1, s5, -0xcb0
00238d1c: 50 f3 a3 26           addiu v1, s5, -0xcb0
00238d20: e2 12 62 90           lbu v0, 0x12e2 ( v1 )
00238d24: 0b 00 40 10           beq v0, zero, 00238d54
00238d28: ff ff 11 24           _li s1, -0x1
00238d2c: 16 00 01 3c           lui at, 0x16
00238d30: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
00238d34: 00 68 80 44           clear f13
00238d38: 33 3f 01 3c           lui at, 0x3f33
00238d3c: 33 33 21 34           ori at, at, 0x3333
00238d40: 00 60 81 44           mtc1 at, f12
00238d44: 14 ce 08 0c           jal 00233850
00238d48: 42 03 0d 46           _mul.S f13, f0, f13
00238d4c: 07 00 00 10           b 00238d6c
00238d50: 00 00 00 00           _nop 
00238d54: 16 00 01 3c           lui at, 0x16
00238d58: 6c ed 2d c4           lwc1 f13, -0x1294 ( at )
00238d5c: 00 3f 01 3c           lui at, 0x3f00
00238d60: 00 60 81 44           mtc1 at, f12
00238d64: 14 ce 08 0c           jal 00233850
00238d68: 40 6b 0d 46           _add.S f13, f13, f13
00238d6c: 00 68 80 44           clear f13
00238d70: 6c 40 01 3c           lui at, 0x406c
00238d74: cd cc 21 34           ori at, at, 0xcccd
00238d78: 00 60 81 44           mtc1 at, f12
00238d7c: 49 41 01 3c           lui at, 0x4149
00238d80: 9a 99 21 34           ori at, at, 0x999a
00238d84: 00 a0 81 44           mtc1 at, f20
00238d88: 9a da 08 0c           jal 00236a68
00238d8c: 00 00 00 00           _nop 
00238d90: 80 3f 01 3c           lui at, 0x3f80
00238d94: 00 60 81 44           mtc1 at, f12
00238d98: dc c7 08 0c           jal 00231f70
00238d9c: 2d 20 00 00           _move a0, zero
00238da0: 16 00 01 3c           lui at, 0x16
00238da4: 70 ed 2c c4           lwc1 f12, -0x1290 ( at )
00238da8: 02 63 14 46           mul.S f12, f12, f20
00238dac: ba c9 08 0c           jal 002326e8
00238db0: 46 63 00 46           _mov.S f13, f12
00238db4: 14 00 02 3c           lui v0, 0x14
00238db8: 30 f4 50 24           addiu s0, v0, -0xbd0
00238dbc: 5c 84 08 0c           jal 00221170
00238dc0: 2d 20 00 02           _move a0, s0
00238dc4: 16 00 01 3c           lui at, 0x16
00238dc8: 70 ed 2c c4           lwc1 f12, -0x1290 ( at )
00238dcc: 9e d9 08 0c           jal 00236678
00238dd0: 02 63 14 46           _mul.S f12, f12, f20
00238dd4: 2e 02 02 86           lh v0, 0x22e ( s0 )
00238dd8: 0b 00 40 10           beq v0, zero, 00238e08
00238ddc: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
00238de0: 2d 20 00 02           move a0, s0
00238de4: c8 41 01 3c           lui at, 0x41c8
00238de8: 00 60 81 44           mtc1 at, f12
00238dec: 20 00 85 24           addiu a1, a0, 0x20
00238df0: da 22 09 0c           jal 00248b68
00238df4: 02 03 0c 46           _mul.S f12, f0, f12
00238df8: 08 ca 08 0c           jal 00232820
00238dfc: 00 00 00 00           _nop 
00238e00: 08 00 00 10           b 00238e24
00238e04: ff ff 02 24           _li v0, -0x1
00238e08: 2d 20 00 02           move a0, s0
00238e0c: 58 42 01 3c           lui at, 0x4258
00238e10: 00 60 81 44           mtc1 at, f12
00238e14: 2d 28 80 00           move a1, a0
00238e18: da 22 09 0c           jal 00248b68
00238e1c: 02 03 0c 46           _mul.S f12, f0, f12
00238e20: ff ff 02 24           li v0, -0x1
00238e24: 0b 00 22 12           beq s1, v0, 00238e54
00238e28: 50 f3 a4 26           _addiu a0, s5, -0xcb0
00238e2c: 36 00 05 24           li a1, 0x36
00238e30: 80 20 82 8c           lw v0, 0x2080 ( a0 )
00238e34: 52 00 43 90           lbu v1, 0x52 ( v0 )
00238e38: 06 00 65 10           beq v1, a1, 00238e54
00238e3c: 2d 10 00 00           _move v0, zero
00238e40: 00 60 82 44           mtc1 v0, f12
00238e44: 00 00 00 00           nop 
00238e48: 20 63 80 46           cvt.s.W f12, f12
00238e4c: 13 00 00 10           b 00238e9c
00238e50: ff ff 04 24           _li a0, -0x1
00238e54: 50 f3 a3 26           addiu v1, s5, -0xcb0
00238e58: 80 20 63 8c           lw v1, 0x2080 ( v1 )
00238e5c: 70 00 62 90           lbu v0, 0x70 ( v1 )
00238e60: 02 00 42 30           andi v0, v0, 0x2
00238e64: 62 0d 40 10           beq v0, zero, 0023c3f0
00238e68: 36 00 02 24           _li v0, 0x36
00238e6c: 52 00 63 90           lbu v1, 0x52 ( v1 )
00238e70: 60 0d 62 14           bne v1, v0, 0023c3f4
00238e74: 50 f3 a3 26           _addiu v1, s5, -0xcb0
00238e78: c4 9b 08 0c           jal 00226f10
00238e7c: 2d 20 00 00           _move a0, zero
00238e80: 2d 80 40 00           move s0, v0
00238e84: 8c 83 08 0c           jal 00220e30
00238e88: 05 00 04 24           _li a0, 0x5
00238e8c: 00 60 82 44           mtc1 v0, f12
00238e90: 00 00 00 00           nop 
00238e94: 20 63 80 46           cvt.s.W f12, f12
00238e98: 2d 20 00 02           move a0, s0
00238e9c: a4 1e 09 0c           jal 00247a90
00238ea0: 2d 28 00 00           _move a1, zero
00238ea4: 53 0d 00 10           b 0023c3f4
00238ea8: 50 f3 a3 26           _addiu v1, s5, -0xcb0
00238eac: f0 41 01 3c           lui at, 0x41f0
00238eb0: 00 00 81 44           mtc1 at, f0
00238eb4: 50 f3 b2 26           addiu s2, s5, -0xcb0
00238eb8: 16 00 01 3c           lui at, 0x16
00238ebc: 70 ed 2c c4           lwc1 f12, -0x1290 ( at )
00238ec0: e0 00 51 26           addiu s1, s2, 0xe0
00238ec4: 90 01 40 ae           sw zero, 0x190 ( s2 )
00238ec8: 02 63 00 46           mul.S f12, f12, f0
00238ecc: ba c9 08 0c           jal 002326e8
00238ed0: 46 63 00 46           _mov.S f13, f12
00238ed4: 94 01 4c c6           lwc1 f12, 0x194 ( s2 )
00238ed8: 2d 28 20 02           move a1, s1
00238edc: 8e 24 09 0c           jal 00249238
00238ee0: 2d 20 20 02           _move a0, s1
00238ee4: 8c 83 08 0c           jal 00220e30
00238ee8: 0c 00 04 24           _li a0, 0xc
00238eec: 16 00 01 3c           lui at, 0x16
00238ef0: 6c ed 23 c4           lwc1 f3, -0x1294 ( at )
00238ef4: 2d 80 40 00           move s0, v0
00238ef8: 16 00 01 3c           lui at, 0x16
00238efc: 70 ed 22 c4           lwc1 f2, -0x1290 ( at )
00238f00: 21 00 04 24           li a0, 0x21
00238f04: b6 40 01 3c           lui at, 0x40b6
00238f08: 66 66 21 34           ori at, at, 0x6666
00238f0c: 00 00 81 44           mtc1 at, f0
00238f10: 8c 42 01 3c           lui at, 0x428c
00238f14: 00 08 81 44           mtc1 at, f1
00238f18: 02 1d 00 46           mul.S f20, f3, f0
00238f1c: 8c 83 08 0c           jal 00220e30
00238f20: 42 15 01 46           _mul.S f21, f2, f1
00238f24: 2d 18 40 00           move v1, v0
00238f28: 98 01 42 8e           lw v0, 0x198 ( s2 )
00238f2c: 2a 80 50 00           slt s0, v0, s0
00238f30: 0e 00 00 12           beq s0, zero, 00238f6c
00238f34: 2a 10 62 00           _slt v0, v1, v0
00238f38: 44 24 09 0c           jal 00249110
00238f3c: 2d 20 20 02           _move a0, s1
00238f40: 06 a3 00 46           mov.S f12, f20
00238f44: 68 00 a4 27           addiu a0, sp, 0x68
00238f48: 68 00 a0 e7           swc1 f0, 0x68 ( sp )
00238f4c: ca c1 09 0c           jal 00270728
00238f50: 46 ab 00 46           _mov.S f13, f21
00238f54: 2d 20 20 02           move a0, s1
00238f58: 68 00 ac c7           lwc1 f12, 0x68 ( sp )
00238f5c: 6e 24 09 0c           jal 002491b8
00238f60: 2d 28 80 00           _move a1, a0
00238f64: 13 00 00 10           b 00238fb4
00238f68: 50 f3 b1 26           _addiu s1, s5, -0xcb0
00238f6c: 11 00 40 50           beql v0, zero, 00238fb4
00238f70: 50 f3 b1 26           _addiu s1, s5, -0xcb0
00238f74: b0 04 4c c6           lwc1 f12, 0x4b0 ( s2 )
00238f78: 2d 20 20 02           move a0, s1
00238f7c: da 22 09 0c           jal 00248b68
00238f80: 2d 28 20 02           _move a1, s1
00238f84: 44 24 09 0c           jal 00249110
00238f88: 2d 20 20 02           _move a0, s1
00238f8c: 00 08 80 44           clear f1
00238f90: 00 00 00 00           nop 
00238f94: 34 00 01 46           c.lt.S f0, f1
00238f98: 00 00 00 00           nop 
00238f9c: 05 00 00 45           bc1f 00238fb4
00238fa0: 50 f3 b1 26           _addiu s1, s5, -0xcb0
00238fa4: 80 3f 01 3c           lui at, 0x3f80
00238fa8: 00 00 81 44           mtc1 at, f0
00238fac: 00 00 00 00           nop 
00238fb0: b8 04 40 e6           swc1 f0, 0x4b8 ( s2 )
00238fb4: 00 a0 80 44           clear f20
00238fb8: b8 04 20 c6           lwc1 f0, 0x4b8 ( s1 )
00238fbc: 32 00 14 46           c.eq.S f0, f20
00238fc0: 00 00 00 00           nop 
00238fc4: 23 00 03 45           bc1tl 00239054
00238fc8: 50 f3 b1 26           _addiu s1, s5, -0xcb0
00238fcc: 0e 03 22 86           lh v0, 0x30e ( s1 )
00238fd0: 1f 00 40 10           beq v0, zero, 00239050
00238fd4: 80 00 23 26           _addiu v1, s1, 0x80
00238fd8: 00 00 62 78           lq v0, 0x0 ( v1 )
00238fdc: 00 00 a2 7f           sq v0, 0x0 ( sp )
00238fe0: 08 00 a0 c7           lwc1 f0, 0x8 ( sp )
00238fe4: 00 3f 01 3c           lui at, 0x3f00
00238fe8: 00 08 81 44           mtc1 at, f1
00238fec: 98 00 2c c6           lwc1 f12, 0x98 ( s1 )
00238ff0: 01 00 01 46           sub.S f0, f0, f1
00238ff4: be 85 08 0c           jal 002216f8
00238ff8: 08 00 a0 e7           _swc1 f0, 0x8 ( sp )
00238ffc: 98 00 2c c6           lwc1 f12, 0x98 ( s1 )
00239000: c4 85 08 0c           jal 00221710
00239004: 10 00 a0 e7           _swc1 f0, 0x10 ( sp )
00239008: 80 20 25 8e           lw a1, 0x2080 ( s1 )
0023900c: 30 00 b0 27           addiu s0, sp, 0x30
00239010: 80 3f 01 3c           lui at, 0x3f80
00239014: 00 60 81 44           mtc1 at, f12
00239018: 2d 20 00 02           move a0, s0
0023901c: 03 00 06 3c           lui a2, 0x3
00239020: 10 00 a7 27           addiu a3, sp, 0x10
00239024: 14 00 a0 e7           swc1 f0, 0x14 ( sp )
00239028: 02 ba 09 0c           jal 0026e808
0023902c: 18 00 b4 e7           _swc1 f20, 0x18 ( sp )
00239030: 80 20 26 8e           lw a2, 0x2080 ( s1 )
00239034: 2d 38 00 02           move a3, s0
00239038: 4c 3f 01 3c           lui at, 0x3f4c
0023903c: cd cc 21 34           ori at, at, 0xcccd
00239040: 00 60 81 44           mtc1 at, f12
00239044: 2d 20 a0 03           move a0, sp
00239048: 1a 51 08 0c           jal 00214468
0023904c: 10 00 05 24           _li a1, 0x10
00239050: 50 f3 b1 26           addiu s1, s5, -0xcb0
00239054: 00 08 80 44           clear f1
00239058: b8 04 20 c6           lwc1 f0, 0x4b8 ( s1 )
0023905c: 32 00 01 46           c.eq.S f0, f1
00239060: 00 00 00 00           nop 
00239064: e3 0c 01 45           bc1t 0023c3f4
00239068: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023906c: 0e 03 22 86           lh v0, 0x30e ( s1 )
00239070: e1 0c 40 14           bne v0, zero, 0023c3f8
00239074: 74 00 a4 8f           _lw a0, 0x74 ( sp )
00239078: c4 04 22 8e           lw v0, 0x4c4 ( s1 )
0023907c: 0c 00 40 14           bne v0, zero, 002390b0
00239080: 01 00 42 24           _addiu v0, v0, 0x1
00239084: 4c 3e 01 3c           lui at, 0x3e4c
00239088: cd cc 21 34           ori at, at, 0xcccd
0023908c: 00 00 81 44           mtc1 at, f0
00239090: 16 00 10 3c           lui s0, 0x16
00239094: 00 71 10 26           addiu s0, s0, 0x7100
00239098: 28 00 04 24           li a0, 0x28
0023909c: 8c 83 08 0c           jal 00220e30
002390a0: 60 01 00 e6           _swc1 f0, 0x160 ( s0 )
002390a4: 68 01 02 ae           sw v0, 0x168 ( s0 )
002390a8: c4 04 22 8e           lw v0, 0x4c4 ( s1 )
002390ac: 01 00 42 24           addiu v0, v0, 0x1
002390b0: cf 0c 00 10           b 0023c3f0
002390b4: c4 04 22 ae           _sw v0, 0x4c4 ( s1 )
002390b8: 50 f3 a5 26           addiu a1, s5, -0xcb0
002390bc: 9c 0a a2 8c           lw v0, 0xa9c ( a1 )
002390c0: 0e 00 40 14           bne v0, zero, 002390fc
002390c4: 02 00 02 24           _li v0, 0x2
002390c8: 60 0a a3 8c           lw v1, 0xa60 ( a1 )
002390cc: 2c 00 04 24           li a0, 0x2c
002390d0: 18 00 02 3c           lui v0, 0x18
002390d4: a8 0a a1 c4           lwc1 f1, 0xaa8 ( a1 )
002390d8: 18 18 64 00           mult v1, v1, a0
002390dc: a8 c0 42 24           addiu v0, v0, -0x3f58
002390e0: 21 10 43 00           addu v0, v0, v1
002390e4: 18 00 40 c4           lwc1 f0, 0x18 ( v0 )
002390e8: 20 00 80 46           cvt.s.W f0, f0
002390ec: 34 08 00 46           c.lt.S f1, f0
002390f0: 00 00 00 00           nop 
002390f4: 02 00 00 45           bc1f 00239100
002390f8: 02 00 02 24           _li v0, 0x2
002390fc: a8 10 a2 a4           sh v0, 0x10a8 ( a1 )
00239100: 50 f3 b0 26           addiu s0, s5, -0xcb0
00239104: 54 0a 05 8e           lw a1, 0xa54 ( s0 )
00239108: 2b 00 a0 10           beq a1, zero, 002391b8
0023910c: 90 01 00 ae           _sw zero, 0x190 ( s0 )
00239110: 10 00 a5 24           addiu a1, a1, 0x10
00239114: e6 84 08 0c           jal 00221398
00239118: 80 00 04 26           _addiu a0, s0, 0x80
0023911c: 46 00 00 46           mov.S f1, f0
00239120: 00 40 01 3c           lui at, 0x4000
00239124: 00 00 81 44           mtc1 at, f0
00239128: 00 00 00 00           nop 
0023912c: 34 00 01 46           c.lt.S f0, f1
00239130: 00 00 00 00           nop 
00239134: 0d 00 00 45           bc1f 0023916c
00239138: 00 00 00 00           _nop 
0023913c: a0 40 01 3c           lui at, 0x40a0
00239140: 00 00 81 44           mtc1 at, f0
00239144: 00 00 00 00           nop 
00239148: 34 08 00 46           c.lt.S f1, f0
0023914c: 00 00 00 00           nop 
00239150: 06 00 00 45           bc1f 0023916c
00239154: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
00239158: 90 40 01 3c           lui at, 0x4090
0023915c: 00 08 81 44           mtc1 at, f1
00239160: 00 00 00 00           nop 
00239164: 02 00 01 46           mul.S f0, f0, f1
00239168: 90 01 00 e6           swc1 f0, 0x190 ( s0 )
0023916c: c8 41 01 3c           lui at, 0x41c8
00239170: 00 00 81 44           mtc1 at, f0
00239174: 50 f3 b0 26           addiu s0, s5, -0xcb0
00239178: 16 00 01 3c           lui at, 0x16
0023917c: 70 ed 2c c4           lwc1 f12, -0x1290 ( at )
00239180: 02 63 00 46           mul.S f12, f12, f0
00239184: ba c9 08 0c           jal 002326e8
00239188: 46 63 00 46           _mov.S f13, f12
0023918c: be 85 08 0c           jal 002216f8
00239190: 98 00 0c c6           _lwc1 f12, 0x98 ( s0 )
00239194: 94 01 01 c6           lwc1 f1, 0x194 ( s0 )
00239198: 98 00 0c c6           lwc1 f12, 0x98 ( s0 )
0023919c: 02 00 01 46           mul.S f0, f0, f1
002391a0: c4 85 08 0c           jal 00221710
002391a4: e0 00 00 e6           _swc1 f0, 0xe0 ( s0 )
002391a8: 94 01 01 c6           lwc1 f1, 0x194 ( s0 )
002391ac: 02 00 01 46           mul.S f0, f0, f1
002391b0: 0d 00 00 10           b 002391e8
002391b4: e4 00 00 e6           _swc1 f0, 0xe4 ( s0 )
002391b8: 16 00 01 3c           lui at, 0x16
002391bc: 70 ed 2c c4           lwc1 f12, -0x1290 ( at )
002391c0: 70 41 01 3c           lui at, 0x4170
002391c4: 00 00 81 44           mtc1 at, f0
002391c8: 00 00 00 00           nop 
002391cc: 02 63 00 46           mul.S f12, f12, f0
002391d0: ba c9 08 0c           jal 002326e8
002391d4: 46 63 00 46           _mov.S f13, f12
002391d8: e0 00 04 26           addiu a0, s0, 0xe0
002391dc: 94 01 0c c6           lwc1 f12, 0x194 ( s0 )
002391e0: 8e 24 09 0c           jal 00249238
002391e4: 2d 28 80 00           _move a1, a0
002391e8: 50 f3 a3 26           addiu v1, s5, -0xcb0
002391ec: 58 0a 62 8c           lw v0, 0xa58 ( v1 )
002391f0: 04 00 40 14           bne v0, zero, 00239204
002391f4: 64 81 81 c7           _lwc1 f1, -0x7e9c ( gp )
002391f8: 54 0a 62 8c           lw v0, 0xa54 ( v1 )
002391fc: 15 00 40 50           beql v0, zero, 00239254
00239200: a8 0a 61 c4           _lwc1 f1, 0xaa8 ( v1 )
00239204: 2d 20 00 00           move a0, zero
00239208: 16 00 01 3c           lui at, 0x16
0023920c: 6c ed 22 c4           lwc1 f2, -0x1294 ( at )
00239210: 4c 3d 01 3c           lui at, 0x3d4c
00239214: cd cc 21 34           ori at, at, 0xcccd
00239218: 00 60 81 44           mtc1 at, f12
0023921c: 4c 3e 01 3c           lui at, 0x3e4c
00239220: cd cc 21 34           ori at, at, 0xcccd
00239224: 00 68 81 44           mtc1 at, f13
00239228: 70 41 01 3c           lui at, 0x4170
0023922c: 45 28 21 34           ori at, at, 0x2845
00239230: 00 70 81 44           mtc1 at, f14
00239234: 02 0b 0c 46           mul.S f12, f1, f12
00239238: 5c 0a 60 c4           lwc1 f0, 0xa5c ( v1 )
0023923c: 42 0b 0d 46           mul.S f13, f1, f13
00239240: 82 13 0e 46           mul.S f14, f2, f14
00239244: 24 c9 08 0c           jal 00232490
00239248: 80 01 60 e4           _swc1 f0, 0x180 ( v1 )
0023924c: 0f 00 00 10           b 0023928c
00239250: 00 00 00 00           _nop 
00239254: c8 41 01 3c           lui at, 0x41c8
00239258: 00 00 81 44           mtc1 at, f0
0023925c: 00 00 00 00           nop 
00239260: 34 08 00 46           c.lt.S f1, f0
00239264: 00 00 00 00           nop 
00239268: 08 00 00 45           bc1f 0023928c
0023926c: 00 00 00 00           _nop 
00239270: 86 3f 01 3c           lui at, 0x3f86
00239274: 92 0a 21 34           ori at, at, 0xa92
00239278: 00 68 81 44           mtc1 at, f13
0023927c: 00 41 01 3c           lui at, 0x4100
00239280: 00 60 81 44           mtc1 at, f12
00239284: 74 d4 08 0c           jal 002351d0
00239288: 86 6b 00 46           _mov.S f14, f13
0023928c: 8c 83 08 0c           jal 00220e30
00239290: 09 00 04 24           _li a0, 0x9
00239294: 2d 98 40 00           move s3, v0
00239298: 10 40 01 3c           lui at, 0x4010
0023929c: 00 08 81 44           mtc1 at, f1
002392a0: 50 f3 a2 26           addiu v0, s5, -0xcb0
002392a4: 16 00 01 3c           lui at, 0x16
002392a8: 6c ed 22 c4           lwc1 f2, -0x1294 ( at )
002392ac: dc 02 43 c4           lwc1 f3, 0x2dc ( v0 )
002392b0: f6 40 01 3c           lui at, 0x40f6
002392b4: 66 66 21 34           ori at, at, 0x6666
002392b8: 00 00 81 44           mtc1 at, f0
002392bc: 34 08 03 46           c.lt.S f1, f3
002392c0: 02 15 00 46           mul.S f20, f2, f0
002392c4: 00 3f 01 3c           lui at, 0x3f00
002392c8: 00 00 81 44           mtc1 at, f0
002392cc: 0e 00 03 45           bc1tl 00239308
002392d0: 02 a5 00 46           _mul.S f20, f20, f0
002392d4: e6 3f 01 3c           lui at, 0x3fe6
002392d8: 66 66 21 34           ori at, at, 0x6666
002392dc: 00 00 81 44           mtc1 at, f0
002392e0: 00 00 00 00           nop 
002392e4: 34 00 03 46           c.lt.S f0, f3
002392e8: 00 00 00 00           nop 
002392ec: 08 00 00 45           bc1f 00239310
002392f0: 70 81 81 c7           _lwc1 f1, -0x7e90 ( gp )
002392f4: 33 3f 01 3c           lui at, 0x3f33
002392f8: 33 33 21 34           ori at, at, 0x3333
002392fc: 00 00 81 44           mtc1 at, f0
00239300: 00 00 00 00           nop 
00239304: 02 a5 00 46           mul.S f20, f20, f0
00239308: 16 00 01 3c           lui at, 0x16
0023930c: 70 ed 21 c4           lwc1 f1, -0x1290 ( at )
00239310: 0e 00 04 24           li a0, 0xe
00239314: 16 43 01 3c           lui at, 0x4316
00239318: 00 00 81 44           mtc1 at, f0
0023931c: 50 f3 b1 26           addiu s1, s5, -0xcb0
00239320: 8c 83 08 0c           jal 00220e30
00239324: 82 0d 00 46           _mul.S f22, f1, f0
00239328: 2d 90 40 00           move s2, v0
0023932c: 9c 0a 22 8e           lw v0, 0xa9c ( s1 )
00239330: 3c 00 40 14           bne v0, zero, 00239424
00239334: 00 00 00 00           _nop 
00239338: a8 0a 21 c6           lwc1 f1, 0xaa8 ( s1 )
0023933c: bc 41 01 3c           lui at, 0x41bc
00239340: 00 00 81 44           mtc1 at, f0
00239344: 00 00 00 00           nop 
00239348: 34 00 01 46           c.lt.S f0, f1
0023934c: 00 00 00 00           nop 
00239350: 34 00 00 45           bc1f 00239424
00239354: 00 00 00 00           _nop 
00239358: 08 01 20 c6           lwc1 f0, 0x108 ( s1 )
0023935c: 00 a8 80 44           clear f21
00239360: 00 00 00 00           nop 
00239364: 34 00 15 46           c.lt.S f0, f21
00239368: 00 00 00 00           nop 
0023936c: 2d 00 00 45           bc1f 00239424
00239370: 00 00 00 00           _nop 
00239374: 0e 03 22 86           lh v0, 0x30e ( s1 )
00239378: 2a 00 40 10           beq v0, zero, 00239424
0023937c: 80 00 23 26           _addiu v1, s1, 0x80
00239380: 00 00 62 78           lq v0, 0x0 ( v1 )
00239384: 00 00 a2 7f           sq v0, 0x0 ( sp )
00239388: 00 bf 01 3c           lui at, 0xbf00
0023938c: 00 60 81 44           mtc1 at, f12
00239390: 2d 20 a0 03           move a0, sp
00239394: 60 23 09 0c           jal 00248d80
00239398: 2d 28 a0 03           _move a1, sp
0023939c: be 85 08 0c           jal 002216f8
002393a0: 98 00 2c c6           _lwc1 f12, 0x98 ( s1 )
002393a4: 00 00 00 46           add.S f0, f0, f0
002393a8: 98 00 2c c6           lwc1 f12, 0x98 ( s1 )
002393ac: c4 85 08 0c           jal 00221710
002393b0: 40 00 a0 e7           _swc1 f0, 0x40 ( sp )
002393b4: 00 00 00 46           add.S f0, f0, f0
002393b8: 80 20 25 8e           lw a1, 0x2080 ( s1 )
002393bc: 10 00 b0 27           addiu s0, sp, 0x10
002393c0: 00 40 01 3c           lui at, 0x4000
002393c4: 00 60 81 44           mtc1 at, f12
002393c8: 2d 20 00 02           move a0, s0
002393cc: 01 00 06 3c           lui a2, 0x1
002393d0: 44 00 a0 e7           swc1 f0, 0x44 ( sp )
002393d4: 40 00 a7 27           addiu a3, sp, 0x40
002393d8: 02 ba 09 0c           jal 0026e808
002393dc: 48 00 b5 e7           _swc1 f21, 0x48 ( sp )
002393e0: af 45 01 3c           lui at, 0x45af
002393e4: 66 df 21 34           ori at, at, 0xdf66
002393e8: 00 00 81 44           mtc1 at, f0
002393ec: 01 00 02 24           li v0, 0x1
002393f0: 80 20 26 8e           lw a2, 0x2080 ( s1 )
002393f4: 47 00 03 24           li v1, 0x47
002393f8: cc 3e 01 3c           lui at, 0x3ecc
002393fc: cd cc 21 34           ori at, at, 0xcccd
00239400: 00 60 81 44           mtc1 at, f12
00239404: 2d 38 00 02           move a3, s0
00239408: 1c 00 a0 e7           swc1 f0, 0x1c ( sp )
0023940c: 2d 20 a0 03           move a0, sp
00239410: 29 00 a2 a3           sb v0, 0x29 ( sp )
00239414: 10 00 05 24           li a1, 0x10
00239418: 2a 00 a3 a7           sh v1, 0x2a ( sp )
0023941c: 1a 51 08 0c           jal 00214468
00239420: 28 00 a0 a3           _sb zero, 0x28 ( sp )
00239424: d8 41 01 3c           lui at, 0x41d8
00239428: 00 60 81 44           mtc1 at, f12
0023942c: c6 c7 08 0c           jal 00231f18
00239430: 50 f3 b0 26           _addiu s0, s5, -0xcb0
00239434: 98 01 03 8e           lw v1, 0x198 ( s0 )
00239438: 2a 10 73 00           slt v0, v1, s3
0023943c: 0c 00 40 10           beq v0, zero, 00239470
00239440: 2a 10 43 02           _slt v0, s2, v1
00239444: e0 00 10 26           addiu s0, s0, 0xe0
00239448: 44 24 09 0c           jal 00249110
0023944c: 2d 20 00 02           _move a0, s0
00239450: 06 a3 00 46           mov.S f12, f20
00239454: 6c 00 a4 27           addiu a0, sp, 0x6c
00239458: 6c 00 a0 e7           swc1 f0, 0x6c ( sp )
0023945c: ca c1 09 0c           jal 00270728
00239460: 46 b3 00 46           _mov.S f13, f22
00239464: 2d 20 00 02           move a0, s0
00239468: 02 07 00 10           b 0023b074
0023946c: 6c 00 ac c7           _lwc1 f12, 0x6c ( sp )
00239470: df 0b 40 10           beq v0, zero, 0023c3f0
00239474: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
00239478: e0 00 11 26           addiu s1, s0, 0xe0
0023947c: 02 43 01 3c           lui at, 0x4302
00239480: 00 60 81 44           mtc1 at, f12
00239484: 2d 20 20 02           move a0, s1
00239488: 2d 28 20 02           move a1, s1
0023948c: da 22 09 0c           jal 00248b68
00239490: 02 03 0c 46           _mul.S f12, f0, f12
00239494: 44 24 09 0c           jal 00249110
00239498: 2d 20 20 02           _move a0, s1
0023949c: 00 08 80 44           clear f1
002394a0: 00 00 00 00           nop 
002394a4: 34 00 01 46           c.lt.S f0, f1
002394a8: 00 00 00 00           nop 
002394ac: 05 00 00 45           bc1f 002394c4
002394b0: 00 00 00 00           _nop 
002394b4: 80 3f 01 3c           lui at, 0x3f80
002394b8: 00 00 81 44           mtc1 at, f0
002394bc: 00 00 00 00           nop 
002394c0: 70 0a 00 e6           swc1 f0, 0xa70 ( s0 )
002394c4: 44 24 09 0c           jal 00249110
002394c8: 2d 20 20 02           _move a0, s1
002394cc: 16 00 01 3c           lui at, 0x16
002394d0: 6c ed 22 c4           lwc1 f2, -0x1294 ( at )
002394d4: 14 c2 01 3c           lui at, 0xc214
002394d8: 00 08 81 44           mtc1 at, f1
002394dc: e1 06 00 10           b 0023b064
002394e0: 02 13 01 46           _mul.S f12, f2, f1
002394e4: 50 f3 a5 26           addiu a1, s5, -0xcb0
002394e8: 9c 0a a2 8c           lw v0, 0xa9c ( a1 )
002394ec: 0e 00 40 14           bne v0, zero, 00239528
002394f0: 90 01 a0 ac           _sw zero, 0x190 ( a1 )
002394f4: 60 0a a3 8c           lw v1, 0xa60 ( a1 )
002394f8: 2c 00 04 24           li a0, 0x2c
002394fc: 18 00 02 3c           lui v0, 0x18
00239500: a8 0a a1 c4           lwc1 f1, 0xaa8 ( a1 )
00239504: 18 18 64 00           mult v1, v1, a0
00239508: a8 c0 42 24           addiu v0, v0, -0x3f58
0023950c: 21 10 43 00           addu v0, v0, v1
00239510: 18 00 40 c4           lwc1 f0, 0x18 ( v0 )
00239514: 20 00 80 46           cvt.s.W f0, f0
00239518: 34 08 00 46           c.lt.S f1, f0
0023951c: 00 00 00 00           nop 
00239520: 04 00 00 45           bc1f 00239534
00239524: 50 f3 b0 26           _addiu s0, s5, -0xcb0
00239528: 02 00 02 24           li v0, 0x2
0023952c: a8 10 a2 a4           sh v0, 0x10a8 ( a1 )
00239530: 50 f3 b0 26           addiu s0, s5, -0xcb0
00239534: 90 20 11 8e           lw s1, 0x2090 ( s0 )
00239538: 01 00 02 24           li v0, 0x1
0023953c: 07 00 22 16           bne s1, v0, 0023955c
00239540: 2d 18 00 00           _move v1, zero
00239544: 8c 83 08 0c           jal 00220e30
00239548: 14 00 04 24           _li a0, 0x14
0023954c: 98 20 03 8e           lw v1, 0x2098 ( s0 )
00239550: 2a 10 43 00           slt v0, v0, v1
00239554: 2d 18 20 02           move v1, s1
00239558: 0a 18 02 00           movz v1, zero, v0
0023955c: 5f 00 60 14           bne v1, zero, 002396dc
00239560: 50 f3 a2 26           _addiu v0, s5, -0xcb0
00239564: 58 0a 02 8e           lw v0, 0xa58 ( s0 )
00239568: 05 00 40 54           bnel v0, zero, 00239580
0023956c: 08 03 02 86           _lh v0, 0x308 ( s0 )
00239570: 54 0a 02 8e           lw v0, 0xa54 ( s0 )
00239574: 3f 00 40 50           beql v0, zero, 00239674
00239578: 9c 0a 02 8e           _lw v0, 0xa9c ( s0 )
0023957c: 08 03 02 86           lh v0, 0x308 ( s0 )
00239580: 1f 00 40 14           bne v0, zero, 00239600
00239584: 01 00 11 24           _li s1, 0x1
00239588: 5c 0a 0c c6           lwc1 f12, 0xa5c ( s0 )
0023958c: 10 88 08 0c           jal 00222040
00239590: 98 00 0d c6           _lwc1 f13, 0x98 ( s0 )
00239594: 5c 0a 0c c6           lwc1 f12, 0xa5c ( s0 )
00239598: 06 05 00 46           mov.S f20, f0
0023959c: 98 00 0d c6           lwc1 f13, 0x98 ( s0 )
002395a0: 7e c2 09 0c           jal 002709f8
002395a4: 01 00 04 24           _li a0, 0x1
002395a8: 46 00 00 46           mov.S f1, f0
002395ac: 8b 40 01 3c           lui at, 0x408b
002395b0: 58 a0 21 34           ori at, at, 0xa058
002395b4: 00 00 81 44           mtc1 at, f0
002395b8: 00 00 00 00           nop 
002395bc: 34 00 01 46           c.lt.S f0, f1
002395c0: 00 00 00 00           nop 
002395c4: 01 00 03 45           bc1tl 002395cc
002395c8: 2d 88 00 00           _move s1, zero
002395cc: 00 00 80 44           clear f0
002395d0: 00 00 00 00           nop 
002395d4: 34 00 14 46           c.lt.S f0, f20
002395d8: 00 00 00 00           nop 
002395dc: 0a 00 00 45           bc1f 00239608
002395e0: 50 f3 a2 26           _addiu v0, s5, -0xcb0
002395e4: 80 3f 01 3c           lui at, 0x3f80
002395e8: 00 00 81 44           mtc1 at, f0
002395ec: 00 00 00 00           nop 
002395f0: 40 08 00 46           add.S f1, f1, f0
002395f4: 03 00 01 46           div.S f0, f0, f1
002395f8: 03 00 00 10           b 00239608
002395fc: 90 0a 00 e6           _swc1 f0, 0xa90 ( s0 )
00239600: 2d 88 00 00           move s1, zero
00239604: 50 f3 a2 26           addiu v0, s5, -0xcb0
00239608: 5c 0a 40 c4           lwc1 f0, 0xa5c ( v0 )
0023960c: 05 00 20 12           beq s1, zero, 00239624
00239610: 80 01 40 e4           _swc1 f0, 0x180 ( v0 )
00239614: 16 00 01 3c           lui at, 0x16
00239618: 64 ed 21 c4           lwc1 f1, -0x129c ( at )
0023961c: 04 00 00 10           b 00239630
00239620: 01 00 04 24           _li a0, 0x1
00239624: 16 00 01 3c           lui at, 0x16
00239628: 64 ed 21 c4           lwc1 f1, -0x129c ( at )
0023962c: 2d 20 00 00           move a0, zero
00239630: 4c 3d 01 3c           lui at, 0x3d4c
00239634: cd cc 21 34           ori at, at, 0xcccd
00239638: 00 60 81 44           mtc1 at, f12
0023963c: 4c 3e 01 3c           lui at, 0x3e4c
00239640: cd cc 21 34           ori at, at, 0xcccd
00239644: 00 68 81 44           mtc1 at, f13
00239648: 16 00 01 3c           lui at, 0x16
0023964c: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
00239650: 02 0b 0c 46           mul.S f12, f1, f12
00239654: 70 41 01 3c           lui at, 0x4170
00239658: 45 28 21 34           ori at, at, 0x2845
0023965c: 00 70 81 44           mtc1 at, f14
00239660: 42 0b 0d 46           mul.S f13, f1, f13
00239664: 24 c9 08 0c           jal 00232490
00239668: 82 03 0e 46           _mul.S f14, f0, f14
0023966c: 1b 00 00 10           b 002396dc
00239670: 50 f3 a2 26           _addiu v0, s5, -0xcb0
00239674: 09 00 40 14           bne v0, zero, 0023969c
00239678: 01 00 03 24           _li v1, 0x1
0023967c: a8 0a 01 c6           lwc1 f1, 0xaa8 ( s0 )
00239680: c0 40 01 3c           lui at, 0x40c0
00239684: 00 00 81 44           mtc1 at, f0
00239688: 00 00 00 00           nop 
0023968c: 34 00 01 46           c.lt.S f0, f1
00239690: 00 00 00 00           nop 
00239694: 01 00 03 45           bc1tl 0023969c
00239698: 2d 18 00 00           _move v1, zero
0023969c: 0e 00 60 10           beq v1, zero, 002396d8
002396a0: 50 f3 a2 26           _addiu v0, s5, -0xcb0
002396a4: b3 20 43 90           lbu v1, 0x20b3 ( v0 )
002396a8: 0d 00 60 54           bnel v1, zero, 002396e0
002396ac: 9c 0a 43 8c           _lw v1, 0xa9c ( v0 )
002396b0: 60 41 01 3c           lui at, 0x4160
002396b4: 00 60 81 44           mtc1 at, f12
002396b8: 06 3f 01 3c           lui at, 0x3f06
002396bc: 92 0a 21 34           ori at, at, 0xa92
002396c0: 00 68 81 44           mtc1 at, f13
002396c4: 49 3f 01 3c           lui at, 0x3f49
002396c8: db 0f 21 34           ori at, at, 0xfdb
002396cc: 00 70 81 44           mtc1 at, f14
002396d0: 74 d4 08 0c           jal 002351d0
002396d4: 00 00 00 00           _nop 
002396d8: 50 f3 a2 26           addiu v0, s5, -0xcb0
002396dc: 9c 0a 43 8c           lw v1, 0xa9c ( v0 )
002396e0: 0b 00 60 14           bne v1, zero, 00239710
002396e4: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
002396e8: 04 42 01 3c           lui at, 0x4204
002396ec: 00 60 81 44           mtc1 at, f12
002396f0: c6 c7 08 0c           jal 00231f18
002396f4: 00 00 00 00           _nop 
002396f8: 05 00 40 10           beq v0, zero, 00239710
002396fc: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
00239700: 68 db 08 0c           jal 00236da0
00239704: 00 00 00 00           _nop 
00239708: 16 00 01 3c           lui at, 0x16
0023970c: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
00239710: 14 42 01 3c           lui at, 0x4214
00239714: 00 60 81 44           mtc1 at, f12
00239718: e0 41 01 3c           lui at, 0x41e0
0023971c: 00 68 81 44           mtc1 at, f13
00239720: 02 03 0c 46           mul.S f12, f0, f12
00239724: ba c9 08 0c           jal 002326e8
00239728: 42 03 0d 46           _mul.S f13, f0, f13
0023972c: c3 47 01 3c           lui at, 0x47c3
00239730: 80 4f 21 34           ori at, at, 0x4f80
00239734: 00 60 81 44           mtc1 at, f12
00239738: ce c9 08 0c           jal 00232738
0023973c: 00 00 00 00           _nop 
00239740: 50 f3 a4 26           addiu a0, s5, -0xcb0
00239744: 0e 03 82 84           lh v0, 0x30e ( a0 )
00239748: 06 00 40 10           beq v0, zero, 00239764
0023974c: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
00239750: 20 01 85 24           addiu a1, a0, 0x120
00239754: c8 41 01 3c           lui at, 0x41c8
00239758: 00 60 81 44           mtc1 at, f12
0023975c: 15 0b 00 10           b 0023c3b4
00239760: e0 00 84 24           _addiu a0, a0, 0xe0
00239764: 16 00 01 3c           lui at, 0x16
00239768: 70 ed 2c c4           lwc1 f12, -0x1290 ( at )
0023976c: e0 00 84 24           addiu a0, a0, 0xe0
00239770: 58 42 01 3c           lui at, 0x4258
00239774: 00 00 81 44           mtc1 at, f0
00239778: 0e 0b 00 10           b 0023c3b4
0023977c: 2d 28 80 00           _move a1, a0
00239780: 50 f3 a5 26           addiu a1, s5, -0xcb0
00239784: 9c 0a a2 8c           lw v0, 0xa9c ( a1 )
00239788: 0d 00 40 14           bne v0, zero, 002397c0
0023978c: 18 00 06 3c           _lui a2, 0x18
00239790: 60 0a a3 8c           lw v1, 0xa60 ( a1 )
00239794: 2c 00 04 24           li a0, 0x2c
00239798: a8 c0 c2 24           addiu v0, a2, -0x3f58
0023979c: a8 0a a1 c4           lwc1 f1, 0xaa8 ( a1 )
002397a0: 18 18 64 00           mult v1, v1, a0
002397a4: 21 10 43 00           addu v0, v0, v1
002397a8: 20 00 40 c4           lwc1 f0, 0x20 ( v0 )
002397ac: 20 00 80 46           cvt.s.W f0, f0
002397b0: 34 08 00 46           c.lt.S f1, f0
002397b4: 00 00 00 00           nop 
002397b8: 04 00 00 45           bc1f 002397cc
002397bc: 50 f3 b0 26           _addiu s0, s5, -0xcb0
002397c0: 02 00 02 24           li v0, 0x2
002397c4: a8 10 a2 a4           sh v0, 0x10a8 ( a1 )
002397c8: 50 f3 b0 26           addiu s0, s5, -0xcb0
002397cc: 2c 00 03 24           li v1, 0x2c
002397d0: 60 0a 02 8e           lw v0, 0xa60 ( s0 )
002397d4: a8 c0 c4 24           addiu a0, a2, -0x3f58
002397d8: 54 0a 05 8e           lw a1, 0xa54 ( s0 )
002397dc: 18 10 43 00           mult v0, v0, v1
002397e0: 90 01 00 ae           sw zero, 0x190 ( s0 )
002397e4: 4f 00 a0 10           beq a1, zero, 00239924
002397e8: 21 88 44 00           _addu s1, v0, a0
002397ec: 8c 83 08 0c           jal 00220e30
002397f0: 04 00 04 24           _li a0, 0x4
002397f4: 98 01 03 8e           lw v1, 0x198 ( s0 )
002397f8: 2a 18 62 00           slt v1, v1, v0
002397fc: 49 00 60 10           beq v1, zero, 00239924
00239800: 80 00 05 26           _addiu a1, s0, 0x80
00239804: 54 0a 04 8e           lw a0, 0xa54 ( s0 )
00239808: e6 84 08 0c           jal 00221398
0023980c: 10 00 84 24           _addiu a0, a0, 0x10
00239810: 00 3f 01 3c           lui at, 0x3f00
00239814: 00 08 81 44           mtc1 at, f1
00239818: 00 10 80 44           clear f2
0023981c: 01 00 01 46           sub.S f0, f0, f1
00239820: 34 00 02 46           c.lt.S f0, f2
00239824: 00 00 00 00           nop 
00239828: 01 00 03 45           bc1tl 00239830
0023982c: 06 10 00 46           _mov.S f0, f2
00239830: 04 00 23 8e           lw v1, 0x4 ( s1 )
00239834: 0a 00 60 14           bne v1, zero, 00239860
00239838: 01 00 02 24           _li v0, 0x1
0023983c: 40 3f 01 3c           lui at, 0x3f40
00239840: 00 60 81 44           mtc1 at, f12
00239844: 4c 3f 01 3c           lui at, 0x3f4c
00239848: cd cc 21 34           ori at, at, 0xcccd
0023984c: 00 a8 81 44           mtc1 at, f21
00239850: 80 40 01 3c           lui at, 0x4080
00239854: 00 b0 81 44           mtc1 at, f22
00239858: 17 00 00 10           b 002398b8
0023985c: 01 05 0c 46           _sub.S f20, f0, f12
00239860: 0b 00 62 14           bne v1, v0, 00239890
00239864: 00 00 00 00           _nop 
00239868: 19 3f 01 3c           lui at, 0x3f19
0023986c: 9a 99 21 34           ori at, at, 0x999a
00239870: 00 60 81 44           mtc1 at, f12
00239874: d9 3f 01 3c           lui at, 0x3fd9
00239878: 9a 99 21 34           ori at, at, 0x999a
0023987c: 00 a8 81 44           mtc1 at, f21
00239880: 80 40 01 3c           lui at, 0x4080
00239884: 00 b0 81 44           mtc1 at, f22
00239888: 0b 00 00 10           b 002398b8
0023988c: 01 05 0c 46           _sub.S f20, f0, f12
00239890: a6 3f 01 3c           lui at, 0x3fa6
00239894: 66 66 21 34           ori at, at, 0x6666
00239898: 00 60 81 44           mtc1 at, f12
0023989c: d9 3f 01 3c           lui at, 0x3fd9
002398a0: 9a 99 21 34           ori at, at, 0x999a
002398a4: 00 a8 81 44           mtc1 at, f21
002398a8: f3 3f 01 3c           lui at, 0x3ff3
002398ac: 33 33 21 34           ori at, at, 0x3333
002398b0: 00 b0 81 44           mtc1 at, f22
002398b4: 01 05 0c 46           sub.S f20, f0, f12
002398b8: 4a 84 08 0c           jal 00221128
002398bc: 06 a3 00 46           _mov.S f12, f20
002398c0: 40 40 01 3c           lui at, 0x4040
002398c4: 00 08 81 44           mtc1 at, f1
002398c8: 00 00 00 00           nop 
002398cc: 40 a8 01 46           add.S f1, f21, f1
002398d0: 34 00 01 46           c.lt.S f0, f1
002398d4: 00 00 00 00           nop 
002398d8: 13 00 02 45           bc1fl 00239928
002398dc: 04 00 23 8e           _lw v1, 0x4 ( s1 )
002398e0: 66 3f 01 3c           lui at, 0x3f66
002398e4: 66 66 21 34           ori at, at, 0x6666
002398e8: 00 00 81 44           mtc1 at, f0
002398ec: 00 00 00 00           nop 
002398f0: 03 a3 00 46           div.S f12, f20, f0
002398f4: 34 b0 0c 46           c.lt.S f22, f12
002398f8: 00 00 00 00           nop 
002398fc: 01 00 03 45           bc1tl 00239904
00239900: 06 b3 00 46           _mov.S f12, f22
00239904: 80 3f 01 3c           lui at, 0x3f80
00239908: 00 00 81 44           mtc1 at, f0
0023990c: 00 00 00 00           nop 
00239910: 34 00 0c 46           c.lt.S f0, f12
00239914: 00 00 00 00           nop 
00239918: 02 00 00 45           bc1f 00239924
0023991c: 50 f3 a2 26           _addiu v0, s5, -0xcb0
00239920: 6c 0a 4c e4           swc1 f12, 0xa6c ( v0 )
00239924: 04 00 23 8e           lw v1, 0x4 ( s1 )
00239928: 01 00 02 24           li v0, 0x1
0023992c: 1b 00 62 10           beq v1, v0, 0023999c
00239930: 02 00 62 28           _slti v0, v1, 0x2
00239934: 05 00 40 10           beq v0, zero, 0023994c
00239938: 02 00 02 24           _li v0, 0x2
0023993c: 07 00 60 10           beq v1, zero, 0023995c
00239940: 14 00 04 3c           _lui a0, 0x14
00239944: 4f 00 00 10           b 00239a84
00239948: 00 00 00 00           _nop 
0023994c: 39 00 62 10           beq v1, v0, 00239a34
00239950: 14 00 04 3c           _lui a0, 0x14
00239954: 4b 00 00 10           b 00239a84
00239958: 00 00 00 00           _nop 
0023995c: 50 f3 a2 26           addiu v0, s5, -0xcb0
00239960: 90 41 01 3c           lui at, 0x4190
00239964: 00 08 81 44           mtc1 at, f1
00239968: a8 0a 40 c4           lwc1 f0, 0xaa8 ( v0 )
0023996c: 34 00 01 46           c.lt.S f0, f1
00239970: 00 00 00 00           nop 
00239974: 42 00 00 45           bc1f 00239a80
00239978: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
0023997c: 8c 40 01 3c           lui at, 0x408c
00239980: cd cc 21 34           ori at, at, 0xcccd
00239984: 00 08 81 44           mtc1 at, f1
00239988: 6c 0a 42 c4           lwc1 f2, 0xa6c ( v0 )
0023998c: 02 00 01 46           mul.S f0, f0, f1
00239990: 02 00 02 46           mul.S f0, f0, f2
00239994: 3a 00 00 10           b 00239a80
00239998: 90 01 40 e4           _swc1 f0, 0x190 ( v0 )
0023999c: 50 f3 a3 26           addiu v1, s5, -0xcb0
002399a0: 9c 0a 62 8c           lw v0, 0xa9c ( v1 )
002399a4: 08 00 40 14           bne v0, zero, 002399c8
002399a8: a8 0a 61 c4           _lwc1 f1, 0xaa8 ( v1 )
002399ac: 10 41 01 3c           lui at, 0x4110
002399b0: 00 00 81 44           mtc1 at, f0
002399b4: 00 00 00 00           nop 
002399b8: 34 08 00 46           c.lt.S f1, f0
002399bc: 00 00 00 00           nop 
002399c0: 30 00 00 45           bc1f 00239a84
002399c4: 14 00 04 3c           _lui a0, 0x14
002399c8: 00 41 01 3c           lui at, 0x4100
002399cc: 00 00 81 44           mtc1 at, f0
002399d0: 00 00 00 00           nop 
002399d4: 34 00 01 46           c.lt.S f0, f1
002399d8: 00 00 00 00           nop 
002399dc: 05 00 00 45           bc1f 002399f4
002399e0: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
002399e4: 40 40 01 3c           lui at, 0x4040
002399e8: 00 08 81 44           mtc1 at, f1
002399ec: 21 00 00 10           b 00239a74
002399f0: 6c 0a 62 c4           _lwc1 f2, 0xa6c ( v1 )
002399f4: e0 40 01 3c           lui at, 0x40e0
002399f8: 00 00 81 44           mtc1 at, f0
002399fc: 00 00 00 00           nop 
00239a00: 34 00 01 46           c.lt.S f0, f1
00239a04: 00 00 00 00           nop 
00239a08: 05 00 00 45           bc1f 00239a20
00239a0c: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
00239a10: 90 40 01 3c           lui at, 0x4090
00239a14: 00 08 81 44           mtc1 at, f1
00239a18: 16 00 00 10           b 00239a74
00239a1c: 6c 0a 62 c4           _lwc1 f2, 0xa6c ( v1 )
00239a20: b6 40 01 3c           lui at, 0x40b6
00239a24: 66 66 21 34           ori at, at, 0x6666
00239a28: 00 08 81 44           mtc1 at, f1
00239a2c: 11 00 00 10           b 00239a74
00239a30: 6c 0a 62 c4           _lwc1 f2, 0xa6c ( v1 )
00239a34: 50 f3 a3 26           addiu v1, s5, -0xcb0
00239a38: 9c 0a 62 8c           lw v0, 0xa9c ( v1 )
00239a3c: 09 00 40 14           bne v0, zero, 00239a64
00239a40: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
00239a44: a8 0a 61 c4           lwc1 f1, 0xaa8 ( v1 )
00239a48: 40 41 01 3c           lui at, 0x4140
00239a4c: 00 00 81 44           mtc1 at, f0
00239a50: 00 00 00 00           nop 
00239a54: 34 08 00 46           c.lt.S f1, f0
00239a58: 00 00 00 00           nop 
00239a5c: 08 00 00 45           bc1f 00239a80
00239a60: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
00239a64: 6c 40 01 3c           lui at, 0x406c
00239a68: cd cc 21 34           ori at, at, 0xcccd
00239a6c: 00 08 81 44           mtc1 at, f1
00239a70: 6c 0a 62 c4           lwc1 f2, 0xa6c ( v1 )
00239a74: 02 00 01 46           mul.S f0, f0, f1
00239a78: 02 00 02 46           mul.S f0, f0, f2
00239a7c: 90 01 60 e4           swc1 f0, 0x190 ( v1 )
00239a80: 14 00 04 3c           lui a0, 0x14
00239a84: 80 3f 01 3c           lui at, 0x3f80
00239a88: 00 a0 81 44           mtc1 at, f20
00239a8c: e0 fd 84 24           addiu a0, a0, -0x220
00239a90: 4c 3e 01 3c           lui at, 0x3e4c
00239a94: cd cc 21 34           ori at, at, 0xcccd
00239a98: 00 68 81 44           mtc1 at, f13
00239a9c: 70 f5 90 24           addiu s0, a0, -0xa90
00239aa0: ca c1 09 0c           jal 00270728
00239aa4: 06 a3 00 46           _mov.S f12, f20
00239aa8: 58 0a 02 8e           lw v0, 0xa58 ( s0 )
00239aac: 05 00 40 54           bnel v0, zero, 00239ac4
00239ab0: 04 00 23 8e           _lw v1, 0x4 ( s1 )
00239ab4: 54 0a 02 8e           lw v0, 0xa54 ( s0 )
00239ab8: 2b 00 40 50           beql v0, zero, 00239b68
00239abc: 04 00 22 8e           _lw v0, 0x4 ( s1 )
00239ac0: 04 00 23 8e           lw v1, 0x4 ( s1 )
00239ac4: 01 00 02 24           li v0, 0x1
00239ac8: 12 00 62 14           bne v1, v0, 00239b14
00239acc: 64 81 82 c7           _lwc1 f2, -0x7e9c ( gp )
00239ad0: 5c 0a 0c c6           lwc1 f12, 0xa5c ( s0 )
00239ad4: 10 88 08 0c           jal 00222040
00239ad8: 98 00 0d c6           _lwc1 f13, 0x98 ( s0 )
00239adc: 00 08 80 44           clear f1
00239ae0: 00 00 00 00           nop 
00239ae4: 34 08 00 46           c.lt.S f1, f0
00239ae8: 00 00 00 00           nop 
00239aec: 09 00 00 45           bc1f 00239b14
00239af0: 64 81 82 c7           _lwc1 f2, -0x7e9c ( gp )
00239af4: 5c 0a 0c c6           lwc1 f12, 0xa5c ( s0 )
00239af8: 40 88 08 0c           jal 00222100
00239afc: 98 00 0d c6           _lwc1 f13, 0x98 ( s0 )
00239b00: 00 00 14 46           add.S f0, f0, f20
00239b04: 03 a0 00 46           div.S f0, f20, f0
00239b08: 90 0a 00 e6           swc1 f0, 0xa90 ( s0 )
00239b0c: 16 00 01 3c           lui at, 0x16
00239b10: 64 ed 22 c4           lwc1 f2, -0x129c ( at )
00239b14: 50 f3 a2 26           addiu v0, s5, -0xcb0
00239b18: 16 00 01 3c           lui at, 0x16
00239b1c: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
00239b20: 2d 20 00 00           move a0, zero
00239b24: 4c 3d 01 3c           lui at, 0x3d4c
00239b28: cd cc 21 34           ori at, at, 0xcccd
00239b2c: 00 60 81 44           mtc1 at, f12
00239b30: 4c 3e 01 3c           lui at, 0x3e4c
00239b34: cd cc 21 34           ori at, at, 0xcccd
00239b38: 00 68 81 44           mtc1 at, f13
00239b3c: 70 41 01 3c           lui at, 0x4170
00239b40: 45 28 21 34           ori at, at, 0x2845
00239b44: 00 70 81 44           mtc1 at, f14
00239b48: 02 13 0c 46           mul.S f12, f2, f12
00239b4c: 5c 0a 40 c4           lwc1 f0, 0xa5c ( v0 )
00239b50: 42 13 0d 46           mul.S f13, f2, f13
00239b54: 82 0b 0e 46           mul.S f14, f1, f14
00239b58: 24 c9 08 0c           jal 00232490
00239b5c: 80 01 40 e4           _swc1 f0, 0x180 ( v0 )
00239b60: 1a 00 00 10           b 00239bcc
00239b64: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
00239b68: 01 00 03 24           li v1, 0x1
00239b6c: 0c 00 43 14           bne v0, v1, 00239ba0
00239b70: 00 00 00 00           _nop 
00239b74: 9c 0a 02 8e           lw v0, 0xa9c ( s0 )
00239b78: 09 00 40 14           bne v0, zero, 00239ba0
00239b7c: 00 00 00 00           _nop 
00239b80: a8 0a 01 c6           lwc1 f1, 0xaa8 ( s0 )
00239b84: e0 40 01 3c           lui at, 0x40e0
00239b88: 00 00 81 44           mtc1 at, f0
00239b8c: 00 00 00 00           nop 
00239b90: 34 00 01 46           c.lt.S f0, f1
00239b94: 00 00 00 00           nop 
00239b98: 01 00 03 45           bc1tl 00239ba0
00239b9c: 2d 18 00 00           _move v1, zero
00239ba0: 0a 00 60 10           beq v1, zero, 00239bcc
00239ba4: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
00239ba8: 49 3f 01 3c           lui at, 0x3f49
00239bac: db 0f 21 34           ori at, at, 0xfdb
00239bb0: 00 68 81 44           mtc1 at, f13
00239bb4: a0 40 01 3c           lui at, 0x40a0
00239bb8: 00 60 81 44           mtc1 at, f12
00239bbc: 74 d4 08 0c           jal 002351d0
00239bc0: 86 6b 00 46           _mov.S f14, f13
00239bc4: 16 00 01 3c           lui at, 0x16
00239bc8: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
00239bcc: 14 42 01 3c           lui at, 0x4214
00239bd0: 00 60 81 44           mtc1 at, f12
00239bd4: e0 41 01 3c           lui at, 0x41e0
00239bd8: 00 68 81 44           mtc1 at, f13
00239bdc: 02 03 0c 46           mul.S f12, f0, f12
00239be0: ba c9 08 0c           jal 002326e8
00239be4: 42 03 0d 46           _mul.S f13, f0, f13
00239be8: 50 f3 a3 26           addiu v1, s5, -0xcb0
00239bec: 58 0a 62 8c           lw v0, 0xa58 ( v1 )
00239bf0: 05 00 40 10           beq v0, zero, 00239c08
00239bf4: 00 00 00 00           _nop 
00239bf8: ce c9 08 0c           jal 00232738
00239bfc: 5c 0a 6c c4           _lwc1 f12, 0xa5c ( v1 )
00239c00: 07 00 00 10           b 00239c20
00239c04: 50 f3 a4 26           _addiu a0, s5, -0xcb0
00239c08: c3 47 01 3c           lui at, 0x47c3
00239c0c: 80 4f 21 34           ori at, at, 0x4f80
00239c10: 00 60 81 44           mtc1 at, f12
00239c14: ce c9 08 0c           jal 00232738
00239c18: 00 00 00 00           _nop 
00239c1c: 50 f3 a4 26           addiu a0, s5, -0xcb0
00239c20: 0e 03 82 84           lh v0, 0x30e ( a0 )
00239c24: 09 00 40 10           beq v0, zero, 00239c4c
00239c28: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
00239c2c: 20 01 85 24           addiu a1, a0, 0x120
00239c30: c8 41 01 3c           lui at, 0x41c8
00239c34: 00 60 81 44           mtc1 at, f12
00239c38: e0 00 84 24           addiu a0, a0, 0xe0
00239c3c: da 22 09 0c           jal 00248b68
00239c40: 02 03 0c 46           _mul.S f12, f0, f12
00239c44: 09 00 00 10           b 00239c6c
00239c48: 00 00 00 00           _nop 
00239c4c: 16 00 01 3c           lui at, 0x16
00239c50: 70 ed 2c c4           lwc1 f12, -0x1290 ( at )
00239c54: e0 00 84 24           addiu a0, a0, 0xe0
00239c58: 58 42 01 3c           lui at, 0x4258
00239c5c: 00 00 81 44           mtc1 at, f0
00239c60: 2d 28 80 00           move a1, a0
00239c64: da 22 09 0c           jal 00248b68
00239c68: 02 63 00 46           _mul.S f12, f12, f0
00239c6c: 6c 40 01 3c           lui at, 0x406c
00239c70: cd cc 21 34           ori at, at, 0xcccd
00239c74: 00 60 81 44           mtc1 at, f12
00239c78: 00 68 80 44           clear f13
00239c7c: 9a da 08 0c           jal 00236a68
00239c80: 00 00 00 00           _nop 
00239c84: db 09 00 10           b 0023c3f4
00239c88: 50 f3 a3 26           _addiu v1, s5, -0xcb0
00239c8c: 16 00 01 3c           lui at, 0x16
00239c90: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
00239c94: 14 00 04 3c           lui a0, 0x14
00239c98: c0 41 01 3c           lui at, 0x41c0
00239c9c: 00 68 81 44           mtc1 at, f13
00239ca0: e4 f4 84 24           addiu a0, a0, -0xb1c
00239ca4: 00 a0 80 44           clear f20
00239ca8: 6c fe 90 24           addiu s0, a0, -0x194
00239cac: 42 03 0d 46           mul.S f13, f0, f13
00239cb0: ca c1 09 0c           jal 00270728
00239cb4: 06 a3 00 46           _mov.S f12, f20
00239cb8: be 85 08 0c           jal 002216f8
00239cbc: 68 0a 0c c6           _lwc1 f12, 0xa68 ( s0 )
00239cc0: 94 01 01 c6           lwc1 f1, 0x194 ( s0 )
00239cc4: 68 0a 0c c6           lwc1 f12, 0xa68 ( s0 )
00239cc8: 02 00 01 46           mul.S f0, f0, f1
00239ccc: c4 85 08 0c           jal 00221710
00239cd0: e0 00 00 e6           _swc1 f0, 0xe0 ( s0 )
00239cd4: 94 01 01 c6           lwc1 f1, 0x194 ( s0 )
00239cd8: dc 02 02 c6           lwc1 f2, 0x2dc ( s0 )
00239cdc: 02 00 01 46           mul.S f0, f0, f1
00239ce0: 34 a0 02 46           c.lt.S f20, f2
00239ce4: 00 00 00 00           nop 
00239ce8: 0a 00 00 45           bc1f 00239d14
00239cec: e4 00 00 e6           _swc1 f0, 0xe4 ( s0 )
00239cf0: 16 00 01 3c           lui at, 0x16
00239cf4: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
00239cf8: c8 41 01 3c           lui at, 0x41c8
00239cfc: 00 10 81 44           mtc1 at, f2
00239d00: 18 01 01 c6           lwc1 f1, 0x118 ( s0 )
00239d04: 02 00 02 46           mul.S f0, f0, f2
00239d08: 41 08 00 46           sub.S f1, f1, f0
00239d0c: 02 00 00 10           b 00239d18
00239d10: e8 00 01 e6           _swc1 f1, 0xe8 ( s0 )
00239d14: e8 00 14 e6           swc1 f20, 0xe8 ( s0 )
00239d18: 50 f3 b0 26           addiu s0, s5, -0xcb0
00239d1c: 49 40 01 3c           lui at, 0x4049
00239d20: db 0f 21 34           ori at, at, 0xfdb
00239d24: 00 68 81 44           mtc1 at, f13
00239d28: fe 87 08 0c           jal 00221ff8
00239d2c: 68 0a 0c c6           _lwc1 f12, 0xa68 ( s0 )
00239d30: 16 00 01 3c           lui at, 0x16
00239d34: 64 ed 21 c4           lwc1 f1, -0x129c ( at )
00239d38: 2d 20 00 00           move a0, zero
00239d3c: 16 00 01 3c           lui at, 0x16
00239d40: 6c ed 22 c4           lwc1 f2, -0x1294 ( at )
00239d44: 4c 3d 01 3c           lui at, 0x3d4c
00239d48: cd cc 21 34           ori at, at, 0xcccd
00239d4c: 00 60 81 44           mtc1 at, f12
00239d50: 4c 3e 01 3c           lui at, 0x3e4c
00239d54: cd cc 21 34           ori at, at, 0xcccd
00239d58: 00 68 81 44           mtc1 at, f13
00239d5c: 70 41 01 3c           lui at, 0x4170
00239d60: 45 28 21 34           ori at, at, 0x2845
00239d64: 00 70 81 44           mtc1 at, f14
00239d68: 02 0b 0c 46           mul.S f12, f1, f12
00239d6c: 42 0b 0d 46           mul.S f13, f1, f13
00239d70: 80 01 00 e6           swc1 f0, 0x180 ( s0 )
00239d74: 24 c9 08 0c           jal 00232490
00239d78: 82 13 0e 46           _mul.S f14, f2, f14
00239d7c: 9d 09 00 10           b 0023c3f4
00239d80: 50 f3 a3 26           _addiu v1, s5, -0xcb0
00239d84: 50 f3 b0 26           addiu s0, s5, -0xcb0
00239d88: 58 0a 02 8e           lw v0, 0xa58 ( s0 )
00239d8c: 04 00 40 14           bne v0, zero, 00239da0
00239d90: 64 81 81 c7           _lwc1 f1, -0x7e9c ( gp )
00239d94: 54 0a 02 8e           lw v0, 0xa54 ( s0 )
00239d98: 15 00 40 10           beq v0, zero, 00239df0
00239d9c: 00 00 00 00           _nop 
00239da0: 2d 20 00 00           move a0, zero
00239da4: 16 00 01 3c           lui at, 0x16
00239da8: 6c ed 22 c4           lwc1 f2, -0x1294 ( at )
00239dac: 4c 3d 01 3c           lui at, 0x3d4c
00239db0: cd cc 21 34           ori at, at, 0xcccd
00239db4: 00 60 81 44           mtc1 at, f12
00239db8: 4c 3e 01 3c           lui at, 0x3e4c
00239dbc: cd cc 21 34           ori at, at, 0xcccd
00239dc0: 00 68 81 44           mtc1 at, f13
00239dc4: 70 41 01 3c           lui at, 0x4170
00239dc8: 45 28 21 34           ori at, at, 0x2845
00239dcc: 00 70 81 44           mtc1 at, f14
00239dd0: 02 0b 0c 46           mul.S f12, f1, f12
00239dd4: 5c 0a 00 c6           lwc1 f0, 0xa5c ( s0 )
00239dd8: 42 0b 0d 46           mul.S f13, f1, f13
00239ddc: 82 13 0e 46           mul.S f14, f2, f14
00239de0: 24 c9 08 0c           jal 00232490
00239de4: 80 01 00 e6           _swc1 f0, 0x180 ( s0 )
00239de8: 11 00 00 10           b 00239e30
00239dec: 0a 00 04 24           _li a0, 0xa
00239df0: 8c 83 08 0c           jal 00220e30
00239df4: 04 00 04 24           _li a0, 0x4
00239df8: 98 01 03 8e           lw v1, 0x198 ( s0 )
00239dfc: 2a 18 62 00           slt v1, v1, v0
00239e00: 0b 00 60 50           beql v1, zero, 00239e30
00239e04: 0a 00 04 24           _li a0, 0xa
00239e08: 30 41 01 3c           lui at, 0x4130
00239e0c: 00 60 81 44           mtc1 at, f12
00239e10: 5f 3f 01 3c           lui at, 0x3f5f
00239e14: f3 66 21 34           ori at, at, 0x66f3
00239e18: 00 68 81 44           mtc1 at, f13
00239e1c: 80 bf 01 3c           lui at, 0xbf80
00239e20: 00 70 81 44           mtc1 at, f14
00239e24: 74 d4 08 0c           jal 002351d0
00239e28: 00 00 00 00           _nop 
00239e2c: 0a 00 04 24           li a0, 0xa
00239e30: 8c 83 08 0c           jal 00220e30
00239e34: 50 f3 b0 26           _addiu s0, s5, -0xcb0
00239e38: 2d 90 40 00           move s2, v0
00239e3c: 90 01 00 ae           sw zero, 0x190 ( s0 )
00239e40: 8c 83 08 0c           jal 00220e30
00239e44: 08 00 04 24           _li a0, 0x8
00239e48: 98 01 03 8e           lw v1, 0x198 ( s0 )
00239e4c: 21 a0 42 02           addu s4, s2, v0
00239e50: 2a 10 43 02           slt v0, s2, v1
00239e54: 08 00 40 10           beq v0, zero, 00239e78
00239e58: 2a 10 74 00           _slt v0, v1, s4
00239e5c: 06 00 40 10           beq v0, zero, 00239e78
00239e60: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
00239e64: 90 41 01 3c           lui at, 0x4190
00239e68: 00 08 81 44           mtc1 at, f1
00239e6c: 00 00 00 00           nop 
00239e70: 02 00 01 46           mul.S f0, f0, f1
00239e74: 90 01 00 e6           swc1 f0, 0x190 ( s0 )
00239e78: 08 00 04 24           li a0, 0x8
00239e7c: 8c 83 08 0c           jal 00220e30
00239e80: 50 f3 b1 26           _addiu s1, s5, -0xcb0
00239e84: 98 01 23 8e           lw v1, 0x198 ( s1 )
00239e88: 12 00 62 54           bnel v1, v0, 00239ed4
00239e8c: 98 01 22 8e           _lw v0, 0x198 ( s1 )
00239e90: 70 16 30 26           addiu s0, s1, 0x1670
00239e94: 80 20 24 8e           lw a0, 0x2080 ( s1 )
00239e98: 00 dd 09 0c           jal 00277400
00239e9c: 2d 28 00 02           _move a1, s0
00239ea0: 2d 20 00 02           move a0, s0
00239ea4: 30 00 05 24           li a1, 0x30
00239ea8: 0a dd 09 0c           jal 00277428
00239eac: 02 00 06 24           _li a2, 0x2
00239eb0: 2d 20 00 02           move a0, s0
00239eb4: 17 00 05 24           li a1, 0x17
00239eb8: 0a dd 09 0c           jal 00277428
00239ebc: 04 00 06 24           _li a2, 0x4
00239ec0: 2d 20 00 02           move a0, s0
00239ec4: 0c 00 05 24           li a1, 0xc
00239ec8: 0a dd 09 0c           jal 00277428
00239ecc: 06 00 06 24           _li a2, 0x6
00239ed0: 98 01 22 8e           lw v0, 0x198 ( s1 )
00239ed4: 05 00 05 24           li a1, 0x5
00239ed8: 70 16 24 26           addiu a0, s1, 0x1670
00239edc: 2a 10 82 02           slt v0, s4, v0
00239ee0: 42 dd 09 0c           jal 00277508
00239ee4: 0a 28 02 00           _movz a1, zero, v0
00239ee8: 98 01 22 8e           lw v0, 0x198 ( s1 )
00239eec: 2a 10 42 02           slt v0, s2, v0
00239ef0: 08 00 40 10           beq v0, zero, 00239f14
00239ef4: 70 81 8d c7           _lwc1 f13, -0x7e90 ( gp )
00239ef8: 3e 43 01 3c           lui at, 0x433e
00239efc: 00 60 81 44           mtc1 at, f12
00239f00: b4 42 01 3c           lui at, 0x42b4
00239f04: 00 00 81 44           mtc1 at, f0
00239f08: 02 6b 0c 46           mul.S f12, f13, f12
00239f0c: ba c9 08 0c           jal 002326e8
00239f10: 42 6b 00 46           _mul.S f13, f13, f0
00239f14: 58 0a 22 8e           lw v0, 0xa58 ( s1 )
00239f18: 05 00 40 10           beq v0, zero, 00239f30
00239f1c: 50 f3 b3 26           _addiu s3, s5, -0xcb0
00239f20: ce c9 08 0c           jal 00232738
00239f24: 5c 0a 2c c6           _lwc1 f12, 0xa5c ( s1 )
00239f28: 06 00 00 10           b 00239f44
00239f2c: 50 f3 b3 26           _addiu s3, s5, -0xcb0
00239f30: c3 47 01 3c           lui at, 0x47c3
00239f34: 80 4f 21 34           ori at, at, 0x4f80
00239f38: 00 60 81 44           mtc1 at, f12
00239f3c: ce c9 08 0c           jal 00232738
00239f40: 00 00 00 00           _nop 
00239f44: 20 00 03 24           li v1, 0x20
00239f48: 84 20 62 8e           lw v0, 0x2084 ( s3 )
00239f4c: 83 00 43 14           bne v0, v1, 0023a15c
00239f50: 0a 00 04 24           _li a0, 0xa
00239f54: 98 01 62 8e           lw v0, 0x198 ( s3 )
00239f58: 2a 10 42 02           slt v0, s2, v0
00239f5c: 7f 00 40 10           beq v0, zero, 0023a15c
00239f60: 00 00 00 00           _nop 
00239f64: 8c 83 08 0c           jal 00220e30
00239f68: 04 00 04 24           _li a0, 0x4
00239f6c: 98 01 63 8e           lw v1, 0x198 ( s3 )
00239f70: 21 10 82 02           addu v0, s4, v0
00239f74: 2a 18 62 00           slt v1, v1, v0
00239f78: 78 00 60 50           beql v1, zero, 0023a15c
00239f7c: 0a 00 04 24           _li a0, 0xa
00239f80: 90 10 72 8e           lw s2, 0x1090 ( s3 )
00239f84: 75 00 40 52           beql s2, zero, 0023a15c
00239f88: 0a 00 04 24           _li a0, 0xa
00239f8c: 98 00 6c c6           lwc1 f12, 0x98 ( s3 )
00239f90: 4c 3f 01 3c           lui at, 0x3f4c
00239f94: cd cc 21 34           ori at, at, 0xcccd
00239f98: 00 a0 81 44           mtc1 at, f20
00239f9c: be 85 08 0c           jal 002216f8
00239fa0: 80 00 71 26           _addiu s1, s3, 0x80
00239fa4: 0c 3f 01 3c           lui at, 0x3f0c
00239fa8: cd cc 21 34           ori at, at, 0xcccd
00239fac: 00 a8 81 44           mtc1 at, f21
00239fb0: 00 00 00 46           add.S f0, f0, f0
00239fb4: 98 00 6c c6           lwc1 f12, 0x98 ( s3 )
00239fb8: c4 85 08 0c           jal 00221710
00239fbc: 30 00 a0 e7           _swc1 f0, 0x30 ( sp )
00239fc0: 00 00 00 46           add.S f0, f0, f0
00239fc4: a6 3f 01 3c           lui at, 0x3fa6
00239fc8: 66 66 21 34           ori at, at, 0x6666
00239fcc: 00 08 81 44           mtc1 at, f1
00239fd0: 80 20 65 8e           lw a1, 0x2080 ( s3 )
00239fd4: 2d 20 a0 03           move a0, sp
00239fd8: 40 40 01 3c           lui at, 0x4040
00239fdc: 00 60 81 44           mtc1 at, f12
00239fe0: 30 00 a7 27           addiu a3, sp, 0x30
00239fe4: 34 00 a0 e7           swc1 f0, 0x34 ( sp )
00239fe8: 03 00 06 3c           lui a2, 0x3
00239fec: 02 ba 09 0c           jal 0026e808
00239ff0: 38 00 a1 e7           _swc1 f1, 0x38 ( sp )
00239ff4: af 45 01 3c           lui at, 0x45af
00239ff8: 66 df 21 34           ori at, at, 0xdf66
00239ffc: 00 00 81 44           mtc1 at, f0
0023a000: 03 00 02 24           li v0, 0x3
0023a004: 19 00 a2 a3           sb v0, 0x19 ( sp )
0023a008: 0c 00 a0 e7           swc1 f0, 0xc ( sp )
0023a00c: 18 00 a0 a3           sb zero, 0x18 ( sp )
0023a010: 98 00 76 c6           lwc1 f22, 0x98 ( s3 )
0023a014: a6 00 42 96           lhu v0, 0xa6 ( s2 )
0023a018: 06 b3 00 46           mov.S f12, f22
0023a01c: be 85 08 0c           jal 002216f8
0023a020: 1a 00 a2 a7           _sh v0, 0x1a ( sp )
0023a024: 02 00 14 46           mul.S f0, f0, f20
0023a028: 06 b3 00 46           mov.S f12, f22
0023a02c: c4 85 08 0c           jal 00221710
0023a030: 40 00 a0 e7           _swc1 f0, 0x40 ( sp )
0023a034: 02 00 14 46           mul.S f0, f0, f20
0023a038: 40 00 b0 27           addiu s0, sp, 0x40
0023a03c: 48 00 b5 e7           swc1 f21, 0x48 ( sp )
0023a040: 2d 20 00 02           move a0, s0
0023a044: 2d 28 00 02           move a1, s0
0023a048: 2d 30 20 02           move a2, s1
0023a04c: 62 84 08 0c           jal 00221188
0023a050: 44 00 a0 e7           _swc1 f0, 0x44 ( sp )
0023a054: 2d 38 a0 03           move a3, sp
0023a058: 2d 30 40 02           move a2, s2
0023a05c: 06 a3 00 46           mov.S f12, f20
0023a060: 2d 20 00 02           move a0, s0
0023a064: 1a 51 08 0c           jal 00214468
0023a068: 2d 28 00 00           _move a1, zero
0023a06c: 2d 28 40 00           move a1, v0
0023a070: 2e db 08 0c           jal 00236cb8
0023a074: 2d 20 40 02           _move a0, s2
0023a078: 5f bf 01 3c           lui at, 0xbf5f
0023a07c: f3 66 21 34           ori at, at, 0x66f3
0023a080: 00 68 81 44           mtc1 at, f13
0023a084: fe 87 08 0c           jal 00221ff8
0023a088: 98 00 6c c6           _lwc1 f12, 0x98 ( s3 )
0023a08c: 86 05 00 46           mov.S f22, f0
0023a090: be 85 08 0c           jal 002216f8
0023a094: 06 b3 00 46           _mov.S f12, f22
0023a098: 02 00 14 46           mul.S f0, f0, f20
0023a09c: 06 b3 00 46           mov.S f12, f22
0023a0a0: c4 85 08 0c           jal 00221710
0023a0a4: 40 00 a0 e7           _swc1 f0, 0x40 ( sp )
0023a0a8: 02 00 14 46           mul.S f0, f0, f20
0023a0ac: 48 00 b5 e7           swc1 f21, 0x48 ( sp )
0023a0b0: 2d 20 00 02           move a0, s0
0023a0b4: 2d 28 00 02           move a1, s0
0023a0b8: 2d 30 20 02           move a2, s1
0023a0bc: 62 84 08 0c           jal 00221188
0023a0c0: 44 00 a0 e7           _swc1 f0, 0x44 ( sp )
0023a0c4: 80 20 66 8e           lw a2, 0x2080 ( s3 )
0023a0c8: 2d 38 a0 03           move a3, sp
0023a0cc: 06 a3 00 46           mov.S f12, f20
0023a0d0: 2d 20 00 02           move a0, s0
0023a0d4: 1a 51 08 0c           jal 00214468
0023a0d8: 2d 28 00 00           _move a1, zero
0023a0dc: 2d 28 40 00           move a1, v0
0023a0e0: 2e db 08 0c           jal 00236cb8
0023a0e4: 2d 20 40 02           _move a0, s2
0023a0e8: 5f 3f 01 3c           lui at, 0x3f5f
0023a0ec: f3 66 21 34           ori at, at, 0x66f3
0023a0f0: 00 68 81 44           mtc1 at, f13
0023a0f4: fe 87 08 0c           jal 00221ff8
0023a0f8: 98 00 6c c6           _lwc1 f12, 0x98 ( s3 )
0023a0fc: 86 05 00 46           mov.S f22, f0
0023a100: be 85 08 0c           jal 002216f8
0023a104: 06 b3 00 46           _mov.S f12, f22
0023a108: 02 00 14 46           mul.S f0, f0, f20
0023a10c: 06 b3 00 46           mov.S f12, f22
0023a110: c4 85 08 0c           jal 00221710
0023a114: 40 00 a0 e7           _swc1 f0, 0x40 ( sp )
0023a118: 02 00 14 46           mul.S f0, f0, f20
0023a11c: 48 00 b5 e7           swc1 f21, 0x48 ( sp )
0023a120: 2d 30 20 02           move a2, s1
0023a124: 2d 20 00 02           move a0, s0
0023a128: 2d 28 00 02           move a1, s0
0023a12c: 62 84 08 0c           jal 00221188
0023a130: 44 00 a0 e7           _swc1 f0, 0x44 ( sp )
0023a134: 2d 20 00 02           move a0, s0
0023a138: 2d 28 00 00           move a1, zero
0023a13c: 06 a3 00 46           mov.S f12, f20
0023a140: 2d 30 40 02           move a2, s2
0023a144: 1a 51 08 0c           jal 00214468
0023a148: 2d 38 a0 03           _move a3, sp
0023a14c: 2d 20 40 02           move a0, s2
0023a150: 2e db 08 0c           jal 00236cb8
0023a154: 2d 28 40 00           _move a1, v0
0023a158: 0a 00 04 24           li a0, 0xa
0023a15c: 8c 83 08 0c           jal 00220e30
0023a160: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023a164: 98 01 03 8e           lw v1, 0x198 ( s0 )
0023a168: 2a 10 43 00           slt v0, v0, v1
0023a16c: 07 00 40 10           beq v0, zero, 0023a18c
0023a170: 00 00 00 00           _nop 
0023a174: 6c 40 01 3c           lui at, 0x406c
0023a178: cd cc 21 34           ori at, at, 0xcccd
0023a17c: 00 60 81 44           mtc1 at, f12
0023a180: 00 68 80 44           clear f13
0023a184: 9a da 08 0c           jal 00236a68
0023a188: 00 00 00 00           _nop 
0023a18c: 5e ca 08 0c           jal 00232978
0023a190: 01 00 04 24           _li a0, 0x1
0023a194: 0e 03 02 86           lh v0, 0x30e ( s0 )
0023a198: 06 00 40 10           beq v0, zero, 0023a1b4
0023a19c: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
0023a1a0: 10 01 05 26           addiu a1, s0, 0x110
0023a1a4: c0 41 01 3c           lui at, 0x41c0
0023a1a8: 00 60 81 44           mtc1 at, f12
0023a1ac: 51 08 00 10           b 0023c2f4
0023a1b0: e0 00 04 26           _addiu a0, s0, 0xe0
0023a1b4: 16 00 01 3c           lui at, 0x16
0023a1b8: 70 ed 2c c4           lwc1 f12, -0x1290 ( at )
0023a1bc: e0 00 04 26           addiu a0, s0, 0xe0
0023a1c0: 58 42 01 3c           lui at, 0x4258
0023a1c4: 00 00 81 44           mtc1 at, f0
0023a1c8: 7a 08 00 10           b 0023c3b4
0023a1cc: 2d 28 80 00           _move a1, a0
0023a1d0: 50 f3 a3 26           addiu v1, s5, -0xcb0
0023a1d4: 58 0a 62 8c           lw v0, 0xa58 ( v1 )
0023a1d8: 17 00 40 10           beq v0, zero, 0023a238
0023a1dc: 90 01 60 ac           _sw zero, 0x190 ( v1 )
0023a1e0: 16 00 01 3c           lui at, 0x16
0023a1e4: 64 ed 21 c4           lwc1 f1, -0x129c ( at )
0023a1e8: 2d 20 00 00           move a0, zero
0023a1ec: 16 00 01 3c           lui at, 0x16
0023a1f0: 6c ed 22 c4           lwc1 f2, -0x1294 ( at )
0023a1f4: 23 3d 01 3c           lui at, 0x3d23
0023a1f8: 0a d7 21 34           ori at, at, 0xd70a
0023a1fc: 00 60 81 44           mtc1 at, f12
0023a200: 4c 3e 01 3c           lui at, 0x3e4c
0023a204: cd cc 21 34           ori at, at, 0xcccd
0023a208: 00 68 81 44           mtc1 at, f13
0023a20c: 70 41 01 3c           lui at, 0x4170
0023a210: 45 28 21 34           ori at, at, 0x2845
0023a214: 00 70 81 44           mtc1 at, f14
0023a218: 02 0b 0c 46           mul.S f12, f1, f12
0023a21c: 5c 0a 60 c4           lwc1 f0, 0xa5c ( v1 )
0023a220: 42 0b 0d 46           mul.S f13, f1, f13
0023a224: 82 13 0e 46           mul.S f14, f2, f14
0023a228: 24 c9 08 0c           jal 00232490
0023a22c: 80 01 60 e4           _swc1 f0, 0x180 ( v1 )
0023a230: 0c 00 00 10           b 0023a264
0023a234: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
0023a238: 30 41 01 3c           lui at, 0x4130
0023a23c: 00 60 81 44           mtc1 at, f12
0023a240: 5f 3f 01 3c           lui at, 0x3f5f
0023a244: f3 66 21 34           ori at, at, 0x66f3
0023a248: 00 68 81 44           mtc1 at, f13
0023a24c: 80 bf 01 3c           lui at, 0xbf80
0023a250: 00 70 81 44           mtc1 at, f14
0023a254: 74 d4 08 0c           jal 002351d0
0023a258: 00 00 00 00           _nop 
0023a25c: 16 00 01 3c           lui at, 0x16
0023a260: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
0023a264: f0 41 01 3c           lui at, 0x41f0
0023a268: 00 60 81 44           mtc1 at, f12
0023a26c: 0c 42 01 3c           lui at, 0x420c
0023a270: 00 68 81 44           mtc1 at, f13
0023a274: 02 03 0c 46           mul.S f12, f0, f12
0023a278: ba c9 08 0c           jal 002326e8
0023a27c: 42 03 0d 46           _mul.S f13, f0, f13
0023a280: c3 47 01 3c           lui at, 0x47c3
0023a284: 80 4f 21 34           ori at, at, 0x4f80
0023a288: 00 60 81 44           mtc1 at, f12
0023a28c: ce c9 08 0c           jal 00232738
0023a290: 00 00 00 00           _nop 
0023a294: 50 f3 a3 26           addiu v1, s5, -0xcb0
0023a298: 0e 03 62 84           lh v0, 0x30e ( v1 )
0023a29c: 0a 00 40 10           beq v0, zero, 0023a2c8
0023a2a0: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
0023a2a4: c8 41 01 3c           lui at, 0x41c8
0023a2a8: 00 10 81 44           mtc1 at, f2
0023a2ac: 08 01 61 c4           lwc1 f1, 0x108 ( v1 )
0023a2b0: 02 00 02 46           mul.S f0, f0, f2
0023a2b4: 41 08 00 46           sub.S f1, f1, f0
0023a2b8: 08 ca 08 0c           jal 00232820
0023a2bc: e8 00 61 e4           _swc1 f1, 0xe8 ( v1 )
0023a2c0: 4c 08 00 10           b 0023c3f4
0023a2c4: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023a2c8: 58 42 01 3c           lui at, 0x4258
0023a2cc: 00 10 81 44           mtc1 at, f2
0023a2d0: e8 00 61 c4           lwc1 f1, 0xe8 ( v1 )
0023a2d4: 02 00 02 46           mul.S f0, f0, f2
0023a2d8: 41 08 00 46           sub.S f1, f1, f0
0023a2dc: 44 08 00 10           b 0023c3f0
0023a2e0: e8 00 61 e4           _swc1 f1, 0xe8 ( v1 )
0023a2e4: 50 f3 a3 26           addiu v1, s5, -0xcb0
0023a2e8: e4 12 62 90           lbu v0, 0x12e4 ( v1 )
0023a2ec: 09 00 40 10           beq v0, zero, 0023a314
0023a2f0: 2d 20 00 00           _move a0, zero
0023a2f4: a4 22 61 c4           lwc1 f1, 0x22a4 ( v1 )
0023a2f8: 80 3e 01 3c           lui at, 0x3e80
0023a2fc: 00 00 81 44           mtc1 at, f0
0023a300: 00 00 00 00           nop 
0023a304: 34 08 00 46           c.lt.S f1, f0
0023a308: 00 00 00 00           nop 
0023a30c: 01 00 03 45           bc1tl 0023a314
0023a310: 01 00 04 24           _li a0, 0x1
0023a314: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023a318: a9 20 02 92           lbu v0, 0x20a9 ( s0 )
0023a31c: 04 00 40 54           bnel v0, zero, 0023a330
0023a320: 64 01 01 c6           _lwc1 f1, 0x164 ( s0 )
0023a324: 1b 00 80 10           beq a0, zero, 0023a394
0023a328: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
0023a32c: 64 01 01 c6           lwc1 f1, 0x164 ( s0 )
0023a330: 16 00 01 3c           lui at, 0x16
0023a334: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023a338: 34 00 01 46           c.lt.S f0, f1
0023a33c: 00 00 00 00           nop 
0023a340: 05 00 00 45           bc1f 0023a358
0023a344: 2d 20 00 00           _move a0, zero
0023a348: 4e ab 08 0c           jal 0022ad38
0023a34c: 02 00 05 24           _li a1, 0x2
0023a350: 16 00 01 3c           lui at, 0x16
0023a354: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023a358: 00 3f 01 3c           lui at, 0x3f00
0023a35c: 00 08 81 44           mtc1 at, f1
0023a360: 64 01 02 c6           lwc1 f2, 0x164 ( s0 )
0023a364: 02 00 01 46           mul.S f0, f0, f1
0023a368: 34 00 02 46           c.lt.S f0, f2
0023a36c: 00 00 00 00           nop 
0023a370: 03 00 00 45           bc1f 0023a380
0023a374: 02 00 04 24           _li a0, 0x2
0023a378: d2 ab 08 0c           jal 0022af48
0023a37c: 04 00 05 24           _li a1, 0x4
0023a380: 05 00 04 24           li a0, 0x5
0023a384: 50 ac 08 0c           jal 0022b140
0023a388: 02 00 05 24           _li a1, 0x2
0023a38c: 16 00 01 3c           lui at, 0x16
0023a390: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023a394: 50 f3 a3 26           addiu v1, s5, -0xcb0
0023a398: 99 3e 01 3c           lui at, 0x3e99
0023a39c: 9a 99 21 34           ori at, at, 0x999a
0023a3a0: 00 08 81 44           mtc1 at, f1
0023a3a4: 64 01 62 c4           lwc1 f2, 0x164 ( v1 )
0023a3a8: 02 00 01 46           mul.S f0, f0, f1
0023a3ac: 34 10 00 46           c.lt.S f2, f0
0023a3b0: 00 00 00 00           nop 
0023a3b4: 0c 00 00 45           bc1f 0023a3e8
0023a3b8: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023a3bc: 9c 22 61 c4           lwc1 f1, 0x229c ( v1 )
0023a3c0: 59 3f 01 3c           lui at, 0x3f59
0023a3c4: 9a 99 21 34           ori at, at, 0x999a
0023a3c8: 00 00 81 44           mtc1 at, f0
0023a3cc: 00 00 00 00           nop 
0023a3d0: 34 00 01 46           c.lt.S f0, f1
0023a3d4: 00 00 00 00           nop 
0023a3d8: 03 00 00 45           bc1f 0023a3e8
0023a3dc: 01 00 02 24           _li v0, 0x1
0023a3e0: b8 03 62 a4           sh v0, 0x3b8 ( v1 )
0023a3e4: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023a3e8: 4a 84 08 0c           jal 00221128
0023a3ec: 88 01 0c c6           _lwc1 f12, 0x188 ( s0 )
0023a3f0: 56 3d 01 3c           lui at, 0x3d56
0023a3f4: 50 77 21 34           ori at, at, 0x7750
0023a3f8: 00 08 81 44           mtc1 at, f1
0023a3fc: 00 00 00 00           nop 
0023a400: 34 00 01 46           c.lt.S f0, f1
0023a404: 00 00 00 00           nop 
0023a408: 09 00 01 45           bc1t 0023a430
0023a40c: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023a410: a8 20 02 92           lbu v0, 0x20a8 ( s0 )
0023a414: 06 00 40 14           bne v0, zero, 0023a430
0023a418: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023a41c: 88 20 03 8e           lw v1, 0x2088 ( s0 )
0023a420: 01 00 02 24           li v0, 0x1
0023a424: 04 00 62 14           bne v1, v0, 0023a438
0023a428: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023a42c: 50 f3 a2 26           addiu v0, s5, -0xcb0
0023a430: b8 03 40 a4           sh zero, 0x3b8 ( v0 )
0023a434: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023a438: be 03 02 86           lh v0, 0x3be ( s0 )
0023a43c: 0e 00 40 10           beq v0, zero, 0023a478
0023a440: 00 00 00 00           _nop 
0023a444: 4a 84 08 0c           jal 00221128
0023a448: 88 01 0c c6           _lwc1 f12, 0x188 ( s0 )
0023a44c: 8e 3d 01 3c           lui at, 0x3d8e
0023a450: 35 fa 21 34           ori at, at, 0xfa35
0023a454: 00 08 81 44           mtc1 at, f1
0023a458: 00 00 00 00           nop 
0023a45c: 34 00 01 46           c.lt.S f0, f1
0023a460: 00 00 00 00           nop 
0023a464: 04 00 03 45           bc1tl 0023a478
0023a468: be 03 00 a6           _sh zero, 0x3be ( s0 )
0023a46c: a8 20 02 92           lbu v0, 0x20a8 ( s0 )
0023a470: 01 00 40 54           bnel v0, zero, 0023a478
0023a474: be 03 00 a6           _sh zero, 0x3be ( s0 )
0023a478: a4 c8 08 0c           jal 00232290
0023a47c: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023a480: 00 68 80 44           clear f13
0023a484: 30 09 00 c6           lwc1 f0, 0x930 ( s0 )
0023a488: 34 68 00 46           c.lt.S f13, f0
0023a48c: 00 00 00 00           nop 
0023a490: 18 00 00 45           bc1f 0023a4f4
0023a494: 50 f3 a4 26           _addiu a0, s5, -0xcb0
0023a498: 33 3f 01 3c           lui at, 0x3f33
0023a49c: 33 33 21 34           ori at, at, 0x3333
0023a4a0: 00 a0 81 44           mtc1 at, f20
0023a4a4: 20 09 11 26           addiu s1, s0, 0x920
0023a4a8: 14 ce 08 0c           jal 00233850
0023a4ac: 06 a3 00 46           _mov.S f12, f20
0023a4b0: 20 09 02 7a           lq v0, 0x920 ( s0 )
0023a4b4: 2d 20 a0 03           move a0, sp
0023a4b8: 3a ce 08 0c           jal 002338e8
0023a4bc: 00 00 a2 7f           _sq v0, 0x0 ( sp )
0023a4c0: 90 01 01 c6           lwc1 f1, 0x190 ( s0 )
0023a4c4: 16 00 01 3c           lui at, 0x16
0023a4c8: 6c ed 22 c4           lwc1 f2, -0x1294 ( at )
0023a4cc: 40 08 00 46           add.S f1, f1, f0
0023a4d0: 82 10 14 46           mul.S f2, f2, f20
0023a4d4: 34 08 02 46           c.lt.S f1, f2
0023a4d8: 00 00 00 00           nop 
0023a4dc: 02 00 00 45           bc1f 0023a4e8
0023a4e0: 90 01 01 e6           _swc1 f1, 0x190 ( s0 )
0023a4e4: 90 01 02 e6           swc1 f2, 0x190 ( s0 )
0023a4e8: 5c 84 08 0c           jal 00221170
0023a4ec: 2d 20 20 02           _move a0, s1
0023a4f0: 50 f3 a4 26           addiu a0, s5, -0xcb0
0023a4f4: 80 3f 01 3c           lui at, 0x3f80
0023a4f8: 00 a0 81 44           mtc1 at, f20
0023a4fc: 88 20 83 8c           lw v1, 0x2088 ( a0 )
0023a500: 01 00 02 24           li v0, 0x1
0023a504: 18 00 62 14           bne v1, v0, 0023a568
0023a508: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023a50c: be 03 82 84           lh v0, 0x3be ( a0 )
0023a510: 15 00 40 14           bne v0, zero, 0023a568
0023a514: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023a518: 16 00 01 3c           lui at, 0x16
0023a51c: 64 ed 21 c4           lwc1 f1, -0x129c ( at )
0023a520: 2d 20 00 00           move a0, zero
0023a524: 03 3c 01 3c           lui at, 0x3c03
0023a528: 6f 12 21 34           ori at, at, 0x126f
0023a52c: 00 60 81 44           mtc1 at, f12
0023a530: 19 3e 01 3c           lui at, 0x3e19
0023a534: 9a 99 21 34           ori at, at, 0x999a
0023a538: 00 68 81 44           mtc1 at, f13
0023a53c: 16 00 01 3c           lui at, 0x16
0023a540: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023a544: 02 0b 0c 46           mul.S f12, f1, f12
0023a548: 1f 41 01 3c           lui at, 0x411f
0023a54c: 8d 2c 21 34           ori at, at, 0x2c8d
0023a550: 00 70 81 44           mtc1 at, f14
0023a554: 42 0b 0d 46           mul.S f13, f1, f13
0023a558: 24 c9 08 0c           jal 00232490
0023a55c: 82 03 0e 46           _mul.S f14, f0, f14
0023a560: 43 00 00 10           b 0023a670
0023a564: 00 00 00 00           _nop 
0023a568: a8 20 43 90           lbu v1, 0x20a8 ( v0 )
0023a56c: 9c 22 43 c4           lwc1 f3, 0x229c ( v0 )
0023a570: 0c 00 60 10           beq v1, zero, 0023a5a4
0023a574: 88 01 42 c4           _lwc1 f2, 0x188 ( v0 )
0023a578: 0c 3f 01 3c           lui at, 0x3f0c
0023a57c: cd cc 21 34           ori at, at, 0xcccd
0023a580: 00 00 81 44           mtc1 at, f0
0023a584: 80 3f 01 3c           lui at, 0x3f80
0023a588: 00 08 81 44           mtc1 at, f1
0023a58c: 02 10 00 46           mul.S f0, f2, f0
0023a590: 00 10 80 44           clear f2
0023a594: 01 0d 00 46           sub.S f20, f1, f0
0023a598: 34 a0 02 46           c.lt.S f20, f2
0023a59c: 0e 00 00 10           b 0023a5d8
0023a5a0: 00 00 00 00           _nop 
0023a5a4: 4c 3f 01 3c           lui at, 0x3f4c
0023a5a8: cd cc 21 34           ori at, at, 0xcccd
0023a5ac: 00 00 81 44           mtc1 at, f0
0023a5b0: 00 00 00 00           nop 
0023a5b4: 34 18 00 46           c.lt.S f3, f0
0023a5b8: 00 00 00 00           nop 
0023a5bc: 0a 00 00 45           bc1f 0023a5e8
0023a5c0: 18 00 02 3c           _lui v0, 0x18
0023a5c4: 06 3f 01 3c           lui at, 0x3f06
0023a5c8: 92 0a 21 34           ori at, at, 0xa92
0023a5cc: 00 00 81 44           mtc1 at, f0
0023a5d0: 00 00 00 00           nop 
0023a5d4: 34 00 02 46           c.lt.S f0, f2
0023a5d8: 00 00 00 00           nop 
0023a5dc: 02 00 00 45           bc1f 0023a5e8
0023a5e0: 18 00 02 3c           _lui v0, 0x18
0023a5e4: 00 a0 80 44           clear f20
0023a5e8: 44 c2 40 c4           lwc1 f0, -0x3dbc ( v0 )
0023a5ec: 34 00 03 46           c.lt.S f0, f3
0023a5f0: 00 00 00 00           nop 
0023a5f4: 05 00 00 45           bc1f 0023a60c
0023a5f8: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023a5fc: 66 c9 08 0c           jal 00232598
0023a600: 00 00 00 00           _nop 
0023a604: 1a 00 00 10           b 0023a670
0023a608: 00 00 00 00           _nop 
0023a60c: 16 00 01 3c           lui at, 0x16
0023a610: 64 ed 23 c4           lwc1 f3, -0x129c ( at )
0023a614: 9c 22 40 c4           lwc1 f0, 0x229c ( v0 )
0023a618: 2d 20 00 00           move a0, zero
0023a61c: b3 3e 01 3c           lui at, 0x3eb3
0023a620: 33 33 21 34           ori at, at, 0x3333
0023a624: 00 08 81 44           mtc1 at, f1
0023a628: a3 3b 01 3c           lui at, 0x3ba3
0023a62c: 0a d7 21 34           ori at, at, 0xd70a
0023a630: 00 60 81 44           mtc1 at, f12
0023a634: 16 00 01 3c           lui at, 0x16
0023a638: 6c ed 2e c4           lwc1 f14, -0x1294 ( at )
0023a63c: 00 00 01 46           add.S f0, f0, f1
0023a640: 96 40 01 3c           lui at, 0x4096
0023a644: e4 cb 21 34           ori at, at, 0xcbe4
0023a648: 00 10 81 44           mtc1 at, f2
0023a64c: 02 1b 0c 46           mul.S f12, f3, f12
0023a650: cc 3d 01 3c           lui at, 0x3dcc
0023a654: cd cc 21 34           ori at, at, 0xcccd
0023a658: 00 68 81 44           mtc1 at, f13
0023a65c: 82 73 02 46           mul.S f14, f14, f2
0023a660: 42 1b 0d 46           mul.S f13, f3, f13
0023a664: 02 63 00 46           mul.S f12, f12, f0
0023a668: 24 c9 08 0c           jal 00232490
0023a66c: 82 73 00 46           _mul.S f14, f14, f0
0023a670: 8e d5 08 0c           jal 00235638
0023a674: 00 00 00 00           _nop 
0023a678: 98 d7 08 0c           jal 00235e60
0023a67c: 00 00 00 00           _nop 
0023a680: 16 00 01 3c           lui at, 0x16
0023a684: 70 ed 23 c4           lwc1 f3, -0x1290 ( at )
0023a688: 50 f3 a3 26           addiu v1, s5, -0xcb0
0023a68c: f0 40 01 3c           lui at, 0x40f0
0023a690: 00 00 81 44           mtc1 at, f0
0023a694: 08 41 01 3c           lui at, 0x4108
0023a698: 00 08 81 44           mtc1 at, f1
0023a69c: 02 18 00 46           mul.S f0, f3, f0
0023a6a0: be 03 62 84           lh v0, 0x3be ( v1 )
0023a6a4: 42 1b 01 46           mul.S f13, f3, f1
0023a6a8: 1a 00 40 10           beq v0, zero, 0023a714
0023a6ac: 02 03 14 46           _mul.S f12, f0, f20
0023a6b0: 88 01 61 c4           lwc1 f1, 0x188 ( v1 )
0023a6b4: 27 40 01 3c           lui at, 0x4027
0023a6b8: 36 8d 21 34           ori at, at, 0x8d36
0023a6bc: 00 00 81 44           mtc1 at, f0
0023a6c0: 80 3f 01 3c           lui at, 0x3f80
0023a6c4: 00 20 81 44           mtc1 at, f4
0023a6c8: 81 00 01 46           sub.S f2, f0, f1
0023a6cc: 34 20 02 46           c.lt.S f4, f2
0023a6d0: 00 00 00 00           nop 
0023a6d4: 01 00 03 45           bc1tl 0023a6dc
0023a6d8: 86 20 00 46           _mov.S f2, f4
0023a6dc: 4c 3e 01 3c           lui at, 0x3e4c
0023a6e0: cd cc 21 34           ori at, at, 0xcccd
0023a6e4: 00 00 81 44           mtc1 at, f0
0023a6e8: 00 00 00 00           nop 
0023a6ec: 34 10 00 46           c.lt.S f2, f0
0023a6f0: 00 00 00 00           nop 
0023a6f4: 01 00 03 45           bc1tl 0023a6fc
0023a6f8: 86 00 00 46           _mov.S f2, f0
0023a6fc: 90 01 60 c4           lwc1 f0, 0x190 ( v1 )
0023a700: 88 41 01 3c           lui at, 0x4188
0023a704: 00 08 81 44           mtc1 at, f1
0023a708: 02 00 02 46           mul.S f0, f0, f2
0023a70c: 42 1b 01 46           mul.S f13, f3, f1
0023a710: 90 01 60 e4           swc1 f0, 0x190 ( v1 )
0023a714: ba c9 08 0c           jal 002326e8
0023a718: 00 00 00 00           _nop 
0023a71c: 50 f3 a3 26           addiu v1, s5, -0xcb0
0023a720: b8 03 62 84           lh v0, 0x3b8 ( v1 )
0023a724: 08 00 40 10           beq v0, zero, 0023a748
0023a728: 00 00 00 00           _nop 
0023a72c: 08 03 62 84           lh v0, 0x308 ( v1 )
0023a730: 05 00 40 14           bne v0, zero, 0023a748
0023a734: 00 00 00 00           _nop 
0023a738: ce c9 08 0c           jal 00232738
0023a73c: 80 01 6c c4           _lwc1 f12, 0x180 ( v1 )
0023a740: 07 00 00 10           b 0023a760
0023a744: 01 00 04 24           _li a0, 0x1
0023a748: c3 47 01 3c           lui at, 0x47c3
0023a74c: 80 4f 21 34           ori at, at, 0x4f80
0023a750: 00 60 81 44           mtc1 at, f12
0023a754: ce c9 08 0c           jal 00232738
0023a758: 00 00 00 00           _nop 
0023a75c: 01 00 04 24           li a0, 0x1
0023a760: 5e ca 08 0c           jal 00232978
0023a764: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023a768: f4 01 02 86           lh v0, 0x1f4 ( s0 )
0023a76c: 09 00 40 50           beql v0, zero, 0023a794
0023a770: 0e 03 02 86           _lh v0, 0x30e ( s0 )
0023a774: a0 40 01 3c           lui at, 0x40a0
0023a778: 00 60 81 44           mtc1 at, f12
0023a77c: 4c 3e 01 3c           lui at, 0x3e4c
0023a780: cd cc 21 34           ori at, at, 0xcccd
0023a784: 00 68 81 44           mtc1 at, f13
0023a788: 9a da 08 0c           jal 00236a68
0023a78c: 00 00 00 00           _nop 
0023a790: 0e 03 02 86           lh v0, 0x30e ( s0 )
0023a794: 06 00 40 10           beq v0, zero, 0023a7b0
0023a798: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
0023a79c: 20 01 05 26           addiu a1, s0, 0x120
0023a7a0: c8 41 01 3c           lui at, 0x41c8
0023a7a4: 00 60 81 44           mtc1 at, f12
0023a7a8: d2 06 00 10           b 0023c2f4
0023a7ac: e0 00 04 26           _addiu a0, s0, 0xe0
0023a7b0: 16 00 01 3c           lui at, 0x16
0023a7b4: 70 ed 2c c4           lwc1 f12, -0x1290 ( at )
0023a7b8: e0 00 04 26           addiu a0, s0, 0xe0
0023a7bc: 58 42 01 3c           lui at, 0x4258
0023a7c0: 00 00 81 44           mtc1 at, f0
0023a7c4: fb 06 00 10           b 0023c3b4
0023a7c8: 2d 28 80 00           _move a1, a0
0023a7cc: 16 00 03 3c           lui v1, 0x16
0023a7d0: 84 ed 63 8c           lw v1, -0x127c ( v1 )
0023a7d4: 0f 00 02 24           li v0, 0xf
0023a7d8: 07 00 62 14           bne v1, v0, 0023a7f8
0023a7dc: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023a7e0: 02 00 04 24           li a0, 0x2
0023a7e4: 80 20 45 8c           lw a1, 0x2080 ( v0 )
0023a7e8: e6 d9 08 0c           jal 00236798
0023a7ec: 1d 00 06 24           _li a2, 0x1d
0023a7f0: 07 00 00 10           b 0023a810
0023a7f4: 84 81 83 8f           _lw v1, -0x7e7c ( gp )
0023a7f8: 02 00 04 24           li a0, 0x2
0023a7fc: 80 20 45 8c           lw a1, 0x2080 ( v0 )
0023a800: e6 d9 08 0c           jal 00236798
0023a804: 06 00 06 24           _li a2, 0x6
0023a808: 16 00 03 3c           lui v1, 0x16
0023a80c: 84 ed 63 8c           lw v1, -0x127c ( v1 )
0023a810: 0f 00 02 24           li v0, 0xf
0023a814: 4d 00 62 10           beq v1, v0, 0023a94c
0023a818: 04 00 04 24           _li a0, 0x4
0023a81c: 80 be 01 3c           lui at, 0xbe80
0023a820: 00 a8 81 44           mtc1 at, f21
0023a824: 50 ac 08 0c           jal 0022b140
0023a828: 02 00 05 24           _li a1, 0x2
0023a82c: 80 3e 01 3c           lui at, 0x3e80
0023a830: 00 a0 81 44           mtc1 at, f20
0023a834: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023a838: 06 ab 00 46           mov.S f12, f21
0023a83c: 33 3f 01 3c           lui at, 0x3f33
0023a840: 33 33 21 34           ori at, at, 0x3333
0023a844: 00 b0 81 44           mtc1 at, f22
0023a848: 33 bf 01 3c           lui at, 0xbf33
0023a84c: 33 33 21 34           ori at, at, 0x3333
0023a850: 00 b8 81 44           mtc1 at, f23
0023a854: 72 b2 09 0c           jal 0026c9c8
0023a858: 46 a3 00 46           _mov.S f13, f20
0023a85c: 80 00 01 c6           lwc1 f1, 0x80 ( s0 )
0023a860: 06 ab 00 46           mov.S f12, f21
0023a864: 46 a3 00 46           mov.S f13, f20
0023a868: 40 08 00 46           add.S f1, f1, f0
0023a86c: 72 b2 09 0c           jal 0026c9c8
0023a870: 00 00 a1 e7           _swc1 f1, 0x0 ( sp )
0023a874: 84 00 01 c6           lwc1 f1, 0x84 ( s0 )
0023a878: cc 3e 01 3c           lui at, 0x3ecc
0023a87c: cd cc 21 34           ori at, at, 0xcccd
0023a880: 00 68 81 44           mtc1 at, f13
0023a884: 40 08 00 46           add.S f1, f1, f0
0023a888: cc bd 01 3c           lui at, 0xbdcc
0023a88c: cd cc 21 34           ori at, at, 0xcccd
0023a890: 00 60 81 44           mtc1 at, f12
0023a894: 72 b2 09 0c           jal 0026c9c8
0023a898: 04 00 a1 e7           _swc1 f1, 0x4 ( sp )
0023a89c: 88 00 01 c6           lwc1 f1, 0x88 ( s0 )
0023a8a0: 10 00 b1 27           addiu s1, sp, 0x10
0023a8a4: 66 3f 01 3c           lui at, 0x3f66
0023a8a8: 66 66 21 34           ori at, at, 0x6666
0023a8ac: 00 60 81 44           mtc1 at, f12
0023a8b0: 00 01 05 26           addiu a1, s0, 0x100
0023a8b4: 40 08 00 46           add.S f1, f1, f0
0023a8b8: 2d 20 20 02           move a0, s1
0023a8bc: 84 84 08 0c           jal 00221210
0023a8c0: 08 00 a1 e7           _swc1 f1, 0x8 ( sp )
0023a8c4: 16 00 01 3c           lui at, 0x16
0023a8c8: 6c ed 2c c4           lwc1 f12, -0x1294 ( at )
0023a8cc: 42 63 16 46           mul.S f13, f12, f22
0023a8d0: 72 b2 09 0c           jal 0026c9c8
0023a8d4: 02 63 17 46           _mul.S f12, f12, f23
0023a8d8: 10 00 a1 c7           lwc1 f1, 0x10 ( sp )
0023a8dc: 16 00 01 3c           lui at, 0x16
0023a8e0: 6c ed 2c c4           lwc1 f12, -0x1294 ( at )
0023a8e4: 40 08 00 46           add.S f1, f1, f0
0023a8e8: 42 63 16 46           mul.S f13, f12, f22
0023a8ec: 02 63 17 46           mul.S f12, f12, f23
0023a8f0: 72 b2 09 0c           jal 0026c9c8
0023a8f4: 10 00 a1 e7           _swc1 f1, 0x10 ( sp )
0023a8f8: 14 00 a1 c7           lwc1 f1, 0x14 ( sp )
0023a8fc: 16 00 01 3c           lui at, 0x16
0023a900: 6c ed 2c c4           lwc1 f12, -0x1294 ( at )
0023a904: 40 08 00 46           add.S f1, f1, f0
0023a908: 40 63 0c 46           add.S f13, f12, f12
0023a90c: 72 b2 09 0c           jal 0026c9c8
0023a910: 14 00 a1 e7           _swc1 f1, 0x14 ( sp )
0023a914: 18 00 a1 c7           lwc1 f1, 0x18 ( sp )
0023a918: 13 47 01 3c           lui at, 0x4713
0023a91c: 00 a8 21 34           ori at, at, 0xa800
0023a920: 00 60 81 44           mtc1 at, f12
0023a924: 40 08 00 46           add.S f1, f1, f0
0023a928: 93 47 01 3c           lui at, 0x4793
0023a92c: 00 a8 21 34           ori at, at, 0xa800
0023a930: 00 68 81 44           mtc1 at, f13
0023a934: 72 b2 09 0c           jal 0026c9c8
0023a938: 18 00 a1 e7           _swc1 f1, 0x18 ( sp )
0023a93c: 2d 28 20 02           move a1, s1
0023a940: 06 03 00 46           mov.S f12, f0
0023a944: 2c 1b 0a 0c           jal 00286cb0
0023a948: 2d 20 a0 03           _move a0, sp
0023a94c: 14 00 02 3c           lui v0, 0x14
0023a950: 40 f4 50 24           addiu s0, v0, -0xbc0
0023a954: ba 84 08 0c           jal 002212e8
0023a958: 2d 20 00 02           _move a0, s0
0023a95c: 06 05 00 46           mov.S f20, f0
0023a960: 00 3f 01 3c           lui at, 0x3f00
0023a964: 00 08 81 44           mtc1 at, f1
0023a968: 16 00 01 3c           lui at, 0x16
0023a96c: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023a970: 02 00 01 46           mul.S f0, f0, f1
0023a974: 34 00 14 46           c.lt.S f0, f20
0023a978: 00 00 00 00           nop 
0023a97c: 07 00 00 45           bc1f 0023a99c
0023a980: 10 ff 02 26           _addiu v0, s0, -0xf0
0023a984: 10 ff 10 26           addiu s0, s0, -0xf0
0023a988: f0 00 0c c6           lwc1 f12, 0xf0 ( s0 )
0023a98c: f0 85 08 0c           jal 002217c0
0023a990: f4 00 0d c6           _lwc1 f13, 0xf4 ( s0 )
0023a994: 03 00 00 10           b 0023a9a4
0023a998: 80 01 00 e6           _swc1 f0, 0x180 ( s0 )
0023a99c: 98 00 40 c4           lwc1 f0, 0x98 ( v0 )
0023a9a0: 80 01 40 e4           swc1 f0, 0x180 ( v0 )
0023a9a4: 00 3e 01 3c           lui at, 0x3e00
0023a9a8: 00 60 81 44           mtc1 at, f12
0023a9ac: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023a9b0: 16 00 01 3c           lui at, 0x16
0023a9b4: 64 ed 2d c4           lwc1 f13, -0x129c ( at )
0023a9b8: 2d 20 00 00           move a0, zero
0023a9bc: 02 a3 0c 46           mul.S f12, f20, f12
0023a9c0: 16 00 01 3c           lui at, 0x16
0023a9c4: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023a9c8: 4c 3e 01 3c           lui at, 0x3e4c
0023a9cc: cd cc 21 34           ori at, at, 0xcccd
0023a9d0: 00 a8 81 44           mtc1 at, f21
0023a9d4: 86 40 01 3c           lui at, 0x4086
0023a9d8: 92 0a 21 34           ori at, at, 0xa92
0023a9dc: 00 70 81 44           mtc1 at, f14
0023a9e0: 02 63 0d 46           mul.S f12, f12, f13
0023a9e4: 98 00 14 c6           lwc1 f20, 0x98 ( s0 )
0023a9e8: 82 03 0e 46           mul.S f14, f0, f14
0023a9ec: 24 c9 08 0c           jal 00232490
0023a9f0: 42 6b 15 46           _mul.S f13, f13, f21
0023a9f4: 98 00 0c c6           lwc1 f12, 0x98 ( s0 )
0023a9f8: 40 88 08 0c           jal 00222100
0023a9fc: 46 a3 00 46           _mov.S f13, f20
0023aa00: 06 05 00 46           mov.S f20, f0
0023aa04: 5c 84 08 0c           jal 00221170
0023aa08: e0 00 04 26           _addiu a0, s0, 0xe0
0023aa0c: 16 00 01 3c           lui at, 0x16
0023aa10: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
0023aa14: a0 40 01 3c           lui at, 0x40a0
0023aa18: 00 60 81 44           mtc1 at, f12
0023aa1c: 9e d9 08 0c           jal 00236678
0023aa20: 02 03 0c 46           _mul.S f12, f0, f12
0023aa24: 16 00 01 3c           lui at, 0x16
0023aa28: 70 ed 23 c4           lwc1 f3, -0x1290 ( at )
0023aa2c: 48 42 01 3c           lui at, 0x4248
0023aa30: 00 10 81 44           mtc1 at, f2
0023aa34: 08 01 01 c6           lwc1 f1, 0x108 ( s0 )
0023aa38: 82 18 02 46           mul.S f2, f3, f2
0023aa3c: 20 c2 01 3c           lui at, 0xc220
0023aa40: 00 00 81 44           mtc1 at, f0
0023aa44: 00 00 00 00           nop 
0023aa48: c2 18 00 46           mul.S f3, f3, f0
0023aa4c: 41 08 02 46           sub.S f1, f1, f2
0023aa50: 34 18 01 46           c.lt.S f3, f1
0023aa54: 00 00 00 00           nop 
0023aa58: 02 00 00 45           bc1f 0023aa64
0023aa5c: e8 00 01 e6           _swc1 f1, 0xe8 ( s0 )
0023aa60: e8 00 03 e6           swc1 f3, 0xe8 ( s0 )
0023aa64: 16 00 01 3c           lui at, 0x16
0023aa68: 6c ed 22 c4           lwc1 f2, -0x1294 ( at )
0023aa6c: b2 3f 01 3c           lui at, 0x3fb2
0023aa70: c2 b8 21 34           ori at, at, 0xb8c2
0023aa74: 00 00 81 44           mtc1 at, f0
0023aa78: 00 00 00 00           nop 
0023aa7c: 02 10 00 46           mul.S f0, f2, f0
0023aa80: 34 00 14 46           c.lt.S f0, f20
0023aa84: 00 00 00 00           nop 
0023aa88: 01 00 03 45           bc1tl 0023aa90
0023aa8c: 06 05 00 46           _mov.S f20, f0
0023aa90: 10 41 01 3c           lui at, 0x4110
0023aa94: 00 00 81 44           mtc1 at, f0
0023aa98: 90 00 04 26           addiu a0, s0, 0x90
0023aa9c: 00 3f 01 3c           lui at, 0x3f00
0023aaa0: 00 60 81 44           mtc1 at, f12
0023aaa4: e4 09 05 26           addiu a1, s0, 0x9e4
0023aaa8: 02 a5 00 46           mul.S f20, f20, f0
0023aaac: 9c 3f 01 3c           lui at, 0x3f9c
0023aab0: aa 61 21 34           ori at, at, 0x61aa
0023aab4: 00 78 81 44           mtc1 at, f15
0023aab8: e5 3b 01 3c           lui at, 0x3be5
0023aabc: 42 60 21 34           ori at, at, 0x6042
0023aac0: 00 68 81 44           mtc1 at, f13
0023aac4: 2d 30 00 00           move a2, zero
0023aac8: c2 13 0f 46           mul.S f15, f2, f15
0023aacc: 2e 3e 01 3c           lui at, 0x3e2e
0023aad0: 7b 14 21 34           ori at, at, 0x147b
0023aad4: 00 70 81 44           mtc1 at, f14
0023aad8: d6 c2 09 0c           jal 00270b58
0023aadc: 02 a3 0c 46           _mul.S f12, f20, f12
0023aae0: 8c 83 08 0c           jal 00220e30
0023aae4: 64 00 04 24           _li a0, 0x64
0023aae8: 98 01 03 8e           lw v1, 0x198 ( s0 )
0023aaec: 2a 10 43 00           slt v0, v0, v1
0023aaf0: 15 00 40 10           beq v0, zero, 0023ab48
0023aaf4: 64 81 81 c7           _lwc1 f1, -0x7e9c ( gp )
0023aaf8: e8 09 05 26           addiu a1, s0, 0x9e8
0023aafc: d4 09 0c c6           lwc1 f12, 0x9d4 ( s0 )
0023ab00: 94 00 04 26           addiu a0, s0, 0x94
0023ab04: 0f 3d 01 3c           lui at, 0x3d0f
0023ab08: 29 5c 21 34           ori at, at, 0x5c29
0023ab0c: 00 68 81 44           mtc1 at, f13
0023ab10: 2d 30 00 00           move a2, zero
0023ab14: 99 3e 01 3c           lui at, 0x3e99
0023ab18: 9a 99 21 34           ori at, at, 0x999a
0023ab1c: 00 70 81 44           mtc1 at, f14
0023ab20: 07 63 00 46           neg.S f12, f12
0023ab24: 16 00 01 3c           lui at, 0x16
0023ab28: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023ab2c: 42 0b 0d 46           mul.S f13, f1, f13
0023ab30: f5 3f 01 3c           lui at, 0x3ff5
0023ab34: 0b be 21 34           ori at, at, 0xbe0b
0023ab38: 00 78 81 44           mtc1 at, f15
0023ab3c: 82 0b 0e 46           mul.S f14, f1, f14
0023ab40: d6 c2 09 0c           jal 00270b58
0023ab44: c2 03 0f 46           _mul.S f15, f0, f15
0023ab48: 13 3c 01 3c           lui at, 0x3c13
0023ab4c: bc 74 21 34           ori at, at, 0x74bc
0023ab50: 00 60 81 44           mtc1 at, f12
0023ab54: 61 3e 01 3c           lui at, 0x3e61
0023ab58: ae 47 21 34           ori at, at, 0x47ae
0023ab5c: 00 68 81 44           mtc1 at, f13
0023ab60: 78 ad 08 0c           jal 0022b5e0
0023ab64: 00 00 00 00           _nop 
0023ab68: 23 3d 01 3c           lui at, 0x3d23
0023ab6c: 0a d7 21 34           ori at, at, 0xd70a
0023ab70: 00 60 81 44           mtc1 at, f12
0023ab74: 7e ad 08 0c           jal 0022b5f8
0023ab78: 46 ab 00 46           _mov.S f13, f21
0023ab7c: a3 3c 01 3c           lui at, 0x3ca3
0023ab80: 0a d7 21 34           ori at, at, 0xd70a
0023ab84: 00 60 81 44           mtc1 at, f12
0023ab88: 84 ad 08 0c           jal 0022b610
0023ab8c: 46 ab 00 46           _mov.S f13, f21
0023ab90: 06 40 01 3c           lui at, 0x4006
0023ab94: 66 66 21 34           ori at, at, 0x6666
0023ab98: 00 00 81 44           mtc1 at, f0
0023ab9c: 18 00 02 3c           lui v0, 0x18
0023aba0: 60 40 01 3c           lui at, 0x4060
0023aba4: 00 08 81 44           mtc1 at, f1
0023aba8: 00 ab 42 24           addiu v0, v0, -0x5500
0023abac: 02 a0 00 46           mul.S f0, f20, f0
0023abb0: 42 a0 01 46           mul.S f1, f20, f1
0023abb4: 18 01 40 e4           swc1 f0, 0x118 ( v0 )
0023abb8: 0d 06 00 10           b 0023c3f0
0023abbc: 10 01 41 e4           _swc1 f1, 0x110 ( v0 )
0023abc0: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023abc4: 49 40 01 3c           lui at, 0x4049
0023abc8: db 0f 21 34           ori at, at, 0xfdb
0023abcc: 00 68 81 44           mtc1 at, f13
0023abd0: e4 04 0c c6           lwc1 f12, 0x4e4 ( s0 )
0023abd4: fe 87 08 0c           jal 00221ff8
0023abd8: e0 00 11 26           _addiu s1, s0, 0xe0
0023abdc: 16 00 01 3c           lui at, 0x16
0023abe0: 64 ed 21 c4           lwc1 f1, -0x129c ( at )
0023abe4: 2d 20 00 00           move a0, zero
0023abe8: 16 00 01 3c           lui at, 0x16
0023abec: 6c ed 22 c4           lwc1 f2, -0x1294 ( at )
0023abf0: 23 3d 01 3c           lui at, 0x3d23
0023abf4: 0a d7 21 34           ori at, at, 0xd70a
0023abf8: 00 60 81 44           mtc1 at, f12
0023abfc: 4c 3e 01 3c           lui at, 0x3e4c
0023ac00: cd cc 21 34           ori at, at, 0xcccd
0023ac04: 00 68 81 44           mtc1 at, f13
0023ac08: c9 40 01 3c           lui at, 0x40c9
0023ac0c: db 0f 21 34           ori at, at, 0xfdb
0023ac10: 00 70 81 44           mtc1 at, f14
0023ac14: 02 0b 0c 46           mul.S f12, f1, f12
0023ac18: 42 0b 0d 46           mul.S f13, f1, f13
0023ac1c: 80 01 00 e6           swc1 f0, 0x180 ( s0 )
0023ac20: 24 c9 08 0c           jal 00232490
0023ac24: 82 13 0e 46           _mul.S f14, f2, f14
0023ac28: 16 00 01 3c           lui at, 0x16
0023ac2c: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023ac30: 94 00 04 26           addiu a0, s0, 0x94
0023ac34: 96 40 01 3c           lui at, 0x4096
0023ac38: e4 cb 21 34           ori at, at, 0xcbe4
0023ac3c: 00 68 81 44           mtc1 at, f13
0023ac40: 2d 28 00 00           move a1, zero
0023ac44: 00 60 80 44           clear f12
0023ac48: b0 c2 09 0c           jal 00270ac0
0023ac4c: 42 03 0d 46           _mul.S f13, f0, f13
0023ac50: 2d 20 20 02           move a0, s1
0023ac54: d0 04 05 26           addiu a1, s0, 0x4d0
0023ac58: 6e 84 08 0c           jal 002211b8
0023ac5c: 80 00 06 26           _addiu a2, s0, 0x80
0023ac60: 16 00 01 3c           lui at, 0x16
0023ac64: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023ac68: 2d 20 20 02           move a0, s1
0023ac6c: 80 40 01 3c           lui at, 0x4080
0023ac70: 00 60 81 44           mtc1 at, f12
0023ac74: 7c d1 09 0c           jal 002745f0
0023ac78: 02 03 0c 46           _mul.S f12, f0, f12
0023ac7c: 16 00 01 3c           lui at, 0x16
0023ac80: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023ac84: f0 04 04 26           addiu a0, s0, 0x4f0
0023ac88: 40 40 01 3c           lui at, 0x4040
0023ac8c: 00 68 81 44           mtc1 at, f13
0023ac90: 88 00 0c c6           lwc1 f12, 0x88 ( s0 )
0023ac94: ca c1 09 0c           jal 00270728
0023ac98: 42 03 0d 46           _mul.S f13, f0, f13
0023ac9c: d5 05 00 10           b 0023c3f4
0023aca0: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023aca4: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023aca8: 20 00 a4 27           addiu a0, sp, 0x20
0023acac: e0 00 00 ae           sw zero, 0xe0 ( s0 )
0023acb0: 80 00 03 26           addiu v1, s0, 0x80
0023acb4: e4 00 00 ae           sw zero, 0xe4 ( s0 )
0023acb8: e8 00 00 ae           sw zero, 0xe8 ( s0 )
0023acbc: 00 00 62 78           lq v0, 0x0 ( v1 )
0023acc0: 00 00 82 7c           sq v0, 0x0 ( a0 )
0023acc4: 84 20 03 8e           lw v1, 0x2084 ( s0 )
0023acc8: 1a 00 02 24           li v0, 0x1a
0023accc: c9 bf 01 3c           lui at, 0xbfc9
0023acd0: db 0f 21 34           ori at, at, 0xfdb
0023acd4: 00 a0 81 44           mtc1 at, f20
0023acd8: 04 00 62 14           bne v1, v0, 0023acec
0023acdc: 2d 98 80 00           _move s3, a0
0023ace0: c9 3f 01 3c           lui at, 0x3fc9
0023ace4: db 0f 21 34           ori at, at, 0xfdb
0023ace8: 00 a0 81 44           mtc1 at, f20
0023acec: 98 00 0c c6           lwc1 f12, 0x98 ( s0 )
0023acf0: 99 3e 01 3c           lui at, 0x3e99
0023acf4: 9a 99 21 34           ori at, at, 0x999a
0023acf8: 00 a8 81 44           mtc1 at, f21
0023acfc: fe 87 08 0c           jal 00221ff8
0023ad00: 46 a3 00 46           _mov.S f13, f20
0023ad04: be 85 08 0c           jal 002216f8
0023ad08: 06 03 00 46           _mov.S f12, f0
0023ad0c: 02 00 15 46           mul.S f0, f0, f21
0023ad10: 98 00 0c c6           lwc1 f12, 0x98 ( s0 )
0023ad14: 46 a3 00 46           mov.S f13, f20
0023ad18: fe 87 08 0c           jal 00221ff8
0023ad1c: 40 00 a0 e7           _swc1 f0, 0x40 ( sp )
0023ad20: c4 85 08 0c           jal 00221710
0023ad24: 06 03 00 46           _mov.S f12, f0
0023ad28: 02 00 15 46           mul.S f0, f0, f21
0023ad2c: 48 00 a0 af           sw zero, 0x48 ( sp )
0023ad30: 44 00 a0 e7           swc1 f0, 0x44 ( sp )
0023ad34: 30 00 b0 27           addiu s0, sp, 0x30
0023ad38: 2d 28 60 02           move a1, s3
0023ad3c: 2d 20 00 02           move a0, s0
0023ad40: 62 84 08 0c           jal 00221188
0023ad44: 40 00 a6 27           _addiu a2, sp, 0x40
0023ad48: 24 b4 08 0c           jal 0022d090
0023ad4c: 50 f3 b2 26           _addiu s2, s5, -0xcb0
0023ad50: e8 04 42 8e           lw v0, 0x4e8 ( s2 )
0023ad54: a6 05 40 10           beq v0, zero, 0023c3f0
0023ad58: d0 04 51 26           _addiu s1, s2, 0x4d0
0023ad5c: 00 00 22 7a           lq v0, 0x0 ( s1 )
0023ad60: 00 00 a2 7f           sq v0, 0x0 ( sp )
0023ad64: 49 40 01 3c           lui at, 0x4049
0023ad68: db 0f 21 34           ori at, at, 0xfdb
0023ad6c: 00 a0 81 44           mtc1 at, f20
0023ad70: 80 00 54 26           addiu s4, s2, 0x80
0023ad74: e4 04 4c c6           lwc1 f12, 0x4e4 ( s2 )
0023ad78: fe 87 08 0c           jal 00221ff8
0023ad7c: 46 a3 00 46           _mov.S f13, f20
0023ad80: 46 05 00 46           mov.S f21, f0
0023ad84: 00 00 02 7a           lq v0, 0x0 ( s0 )
0023ad88: 00 00 82 7e           sq v0, 0x0 ( s4 )
0023ad8c: 24 b4 08 0c           jal 0022d090
0023ad90: 00 00 00 00           _nop 
0023ad94: 00 00 62 7a           lq v0, 0x0 ( s3 )
0023ad98: 00 00 82 7e           sq v0, 0x0 ( s4 )
0023ad9c: e8 04 43 8e           lw v1, 0x4e8 ( s2 )
0023ada0: 93 05 60 10           beq v1, zero, 0023c3f0
0023ada4: 10 00 b3 27           _addiu s3, sp, 0x10
0023ada8: 00 00 22 7a           lq v0, 0x0 ( s1 )
0023adac: 00 00 62 7e           sq v0, 0x0 ( s3 )
0023adb0: e4 04 4c c6           lwc1 f12, 0x4e4 ( s2 )
0023adb4: fe 87 08 0c           jal 00221ff8
0023adb8: 46 a3 00 46           _mov.S f13, f20
0023adbc: 06 05 00 46           mov.S f20, f0
0023adc0: 06 ab 00 46           mov.S f12, f21
0023adc4: 40 88 08 0c           jal 00222100
0023adc8: 46 a3 00 46           _mov.S f13, f20
0023adcc: 06 3f 01 3c           lui at, 0x3f06
0023add0: 92 0a 21 34           ori at, at, 0xa92
0023add4: 00 08 81 44           mtc1 at, f1
0023add8: 00 00 00 00           nop 
0023addc: 34 08 00 46           c.lt.S f1, f0
0023ade0: 00 00 00 00           nop 
0023ade4: 83 05 01 45           bc1t 0023c3f4
0023ade8: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023adec: 46 a3 00 46           mov.S f13, f20
0023adf0: 00 3f 01 3c           lui at, 0x3f00
0023adf4: 00 a0 81 44           mtc1 at, f20
0023adf8: 10 88 08 0c           jal 00222040
0023adfc: 06 ab 00 46           _mov.S f12, f21
0023ae00: 46 ab 00 46           mov.S f13, f21
0023ae04: e0 00 51 26           addiu s1, s2, 0xe0
0023ae08: fe 87 08 0c           jal 00221ff8
0023ae0c: 02 03 14 46           _mul.S f12, f0, f20
0023ae10: 50 00 b0 27           addiu s0, sp, 0x50
0023ae14: 2d 28 a0 03           move a1, sp
0023ae18: 46 05 00 46           mov.S f21, f0
0023ae1c: 2d 30 60 02           move a2, s3
0023ae20: 62 84 08 0c           jal 00221188
0023ae24: 2d 20 00 02           _move a0, s0
0023ae28: 2d 28 00 02           move a1, s0
0023ae2c: 06 a3 00 46           mov.S f12, f20
0023ae30: 84 84 08 0c           jal 00221210
0023ae34: 2d 20 00 02           _move a0, s0
0023ae38: 16 00 01 3c           lui at, 0x16
0023ae3c: 64 ed 20 c4           lwc1 f0, -0x129c ( at )
0023ae40: 2d 20 00 00           move a0, zero
0023ae44: 16 00 01 3c           lui at, 0x16
0023ae48: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
0023ae4c: 23 3d 01 3c           lui at, 0x3d23
0023ae50: 0a d7 21 34           ori at, at, 0xd70a
0023ae54: 00 60 81 44           mtc1 at, f12
0023ae58: 4c 3e 01 3c           lui at, 0x3e4c
0023ae5c: cd cc 21 34           ori at, at, 0xcccd
0023ae60: 00 68 81 44           mtc1 at, f13
0023ae64: c9 40 01 3c           lui at, 0x40c9
0023ae68: db 0f 21 34           ori at, at, 0xfdb
0023ae6c: 00 70 81 44           mtc1 at, f14
0023ae70: 02 03 0c 46           mul.S f12, f0, f12
0023ae74: 42 03 0d 46           mul.S f13, f0, f13
0023ae78: 80 01 55 e6           swc1 f21, 0x180 ( s2 )
0023ae7c: 24 c9 08 0c           jal 00232490
0023ae80: 82 0b 0e 46           _mul.S f14, f1, f14
0023ae84: 90 01 42 c6           lwc1 f2, 0x190 ( s2 )
0023ae88: 70 00 a4 27           addiu a0, sp, 0x70
0023ae8c: 16 00 01 3c           lui at, 0x16
0023ae90: 70 ed 21 c4           lwc1 f1, -0x1290 ( at )
0023ae94: 16 00 01 3c           lui at, 0x16
0023ae98: 6c ed 2c c4           lwc1 f12, -0x1294 ( at )
0023ae9c: a0 40 01 3c           lui at, 0x40a0
0023aea0: 00 68 81 44           mtc1 at, f13
0023aea4: 02 13 0c 46           mul.S f12, f2, f12
0023aea8: 64 01 40 c6           lwc1 f0, 0x164 ( s2 )
0023aeac: 42 0b 0d 46           mul.S f13, f1, f13
0023aeb0: ca c1 09 0c           jal 00270728
0023aeb4: 70 00 a0 e7           _swc1 f0, 0x70 ( sp )
0023aeb8: 2d 28 00 02           move a1, s0
0023aebc: 2d 20 20 02           move a0, s1
0023aec0: 6e 84 08 0c           jal 002211b8
0023aec4: 2d 30 80 02           _move a2, s4
0023aec8: 58 88 08 0c           jal 00222160
0023aecc: a8 0a 4c c6           _lwc1 f12, 0xaa8 ( s2 )
0023aed0: 1c 00 03 3c           lui v1, 0x1c
0023aed4: 80 10 02 00           sll v0, v0, 0x2
0023aed8: 30 41 63 24           addiu v1, v1, 0x4130
0023aedc: 2d 20 20 02           move a0, s1
0023aee0: 21 10 43 00           addu v0, v0, v1
0023aee4: 2d 28 80 00           move a1, a0
0023aee8: 00 00 4c c4           lwc1 f12, 0x0 ( v0 )
0023aeec: 18 85 08 0c           jal 00221460
0023aef0: 02 63 14 46           _mul.S f12, f12, f20
0023aef4: 3f 05 00 10           b 0023c3f4
0023aef8: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023aefc: 16 00 01 3c           lui at, 0x16
0023af00: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
0023af04: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023af08: b0 40 01 3c           lui at, 0x40b0
0023af0c: 00 10 81 44           mtc1 at, f2
0023af10: 16 00 01 3c           lui at, 0x16
0023af14: 70 ed 23 c4           lwc1 f3, -0x1290 ( at )
0023af18: c8 41 01 3c           lui at, 0x41c8
0023af1c: 00 60 81 44           mtc1 at, f12
0023af20: 42 08 02 46           mul.S f1, f1, f2
0023af24: ec 02 00 c6           lwc1 f0, 0x2ec ( s0 )
0023af28: 02 1b 0c 46           mul.S f12, f3, f12
0023af2c: 80 01 00 e6           swc1 f0, 0x180 ( s0 )
0023af30: d6 d0 08 0c           jal 00234358
0023af34: 90 01 01 e6           _swc1 f1, 0x190 ( s0 )
0023af38: 16 00 01 3c           lui at, 0x16
0023af3c: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
0023af40: 20 01 05 26           addiu a1, s0, 0x120
0023af44: 90 41 01 3c           lui at, 0x4190
0023af48: 00 60 81 44           mtc1 at, f12
0023af4c: 19 05 00 10           b 0023c3b4
0023af50: e0 00 04 26           _addiu a0, s0, 0xe0
0023af54: a4 c8 08 0c           jal 00232290
0023af58: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023af5c: c4 01 02 8e           lw v0, 0x1c4 ( s0 )
0023af60: 03 00 40 14           bne v0, zero, 0023af70
0023af64: 00 00 00 00           _nop 
0023af68: d0 d2 08 0c           jal 00234b40
0023af6c: 00 00 00 00           _nop 
0023af70: 8e d5 08 0c           jal 00235638
0023af74: e0 00 11 26           _addiu s1, s0, 0xe0
0023af78: 16 00 01 3c           lui at, 0x16
0023af7c: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023af80: 00 68 80 44           clear f13
0023af84: 33 3f 01 3c           lui at, 0x3f33
0023af88: 33 33 21 34           ori at, at, 0x3333
0023af8c: 00 60 81 44           mtc1 at, f12
0023af90: 14 ce 08 0c           jal 00233850
0023af94: 42 03 0d 46           _mul.S f13, f0, f13
0023af98: 26 00 00 10           b 0023b034
0023af9c: 40 09 0c c6           _lwc1 f12, 0x940 ( s0 )
0023afa0: 16 00 01 3c           lui at, 0x16
0023afa4: 70 ed 2d c4           lwc1 f13, -0x1290 ( at )
0023afa8: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023afac: 0b 41 01 3c           lui at, 0x410b
0023afb0: 58 a0 21 34           ori at, at, 0xa058
0023afb4: 00 a0 81 44           mtc1 at, f20
0023afb8: 01 00 02 24           li v0, 0x1
0023afbc: 50 09 0c c6           lwc1 f12, 0x950 ( s0 )
0023afc0: 48 09 04 26           addiu a0, s0, 0x948
0023afc4: 42 6b 14 46           mul.S f13, f13, f20
0023afc8: ac 20 02 a2           sb v0, 0x20ac ( s0 )
0023afcc: ca c1 09 0c           jal 00270728
0023afd0: e0 00 11 26           _addiu s1, s0, 0xe0
0023afd4: 16 00 01 3c           lui at, 0x16
0023afd8: 70 ed 2d c4           lwc1 f13, -0x1290 ( at )
0023afdc: 4c 09 04 26           addiu a0, s0, 0x94c
0023afe0: 54 09 0c c6           lwc1 f12, 0x954 ( s0 )
0023afe4: ca c1 09 0c           jal 00270728
0023afe8: 42 6b 14 46           _mul.S f13, f13, f20
0023afec: 4c 09 0d c6           lwc1 f13, 0x94c ( s0 )
0023aff0: 00 70 80 44           clear f14
0023aff4: 36 aa 08 0c           jal 0022a8d8
0023aff8: 48 09 0c c6           _lwc1 f12, 0x948 ( s0 )
0023affc: c6 84 08 0c           jal 00221318
0023b000: 2d 20 20 02           _move a0, s1
0023b004: cc bd 01 3c           lui at, 0xbdcc
0023b008: d0 cc 21 34           ori at, at, 0xccd0
0023b00c: 00 08 81 44           mtc1 at, f1
0023b010: 2d 20 20 02           move a0, s1
0023b014: 16 00 01 3c           lui at, 0x16
0023b018: 60 ed 2c c4           lwc1 f12, -0x12a0 ( at )
0023b01c: 2d 28 20 02           move a1, s1
0023b020: 02 63 01 46           mul.S f12, f12, f1
0023b024: 02 63 00 46           mul.S f12, f12, f0
0023b028: 44 85 08 0c           jal 00221510
0023b02c: 00 63 00 46           _add.S f12, f12, f0
0023b030: 40 09 0c c6           lwc1 f12, 0x940 ( s0 )
0023b034: 2d 20 20 02           move a0, s1
0023b038: da 22 09 0c           jal 00248b68
0023b03c: 2d 28 20 02           _move a1, s1
0023b040: 44 24 09 0c           jal 00249110
0023b044: 2d 20 20 02           _move a0, s1
0023b048: 16 00 01 3c           lui at, 0x16
0023b04c: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
0023b050: 48 42 01 3c           lui at, 0x4248
0023b054: 00 10 81 44           mtc1 at, f2
0023b058: 00 00 00 00           nop 
0023b05c: 42 08 02 46           mul.S f1, f1, f2
0023b060: 07 0b 00 46           neg.S f12, f1
0023b064: 34 00 0c 46           c.lt.S f0, f12
0023b068: 00 00 00 00           nop 
0023b06c: e0 04 00 45           bc1f 0023c3f0
0023b070: 2d 20 20 02           _move a0, s1
0023b074: 6e 24 09 0c           jal 002491b8
0023b078: 2d 28 80 00           _move a1, a0
0023b07c: dd 04 00 10           b 0023c3f4
0023b080: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023b084: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023b088: 04 00 04 24           li a0, 0x4
0023b08c: 80 20 05 8e           lw a1, 0x2080 ( s0 )
0023b090: 12 00 06 24           li a2, 0x12
0023b094: e6 d9 08 0c           jal 00236798
0023b098: 01 00 12 24           _li s2, 0x1
0023b09c: dc 02 01 c6           lwc1 f1, 0x2dc ( s0 )
0023b0a0: 33 3f 01 3c           lui at, 0x3f33
0023b0a4: 33 33 21 34           ori at, at, 0x3333
0023b0a8: 00 00 81 44           mtc1 at, f0
0023b0ac: 00 00 00 00           nop 
0023b0b0: 34 00 01 46           c.lt.S f0, f1
0023b0b4: 00 00 00 00           nop 
0023b0b8: 01 00 02 45           bc1fl 0023b0c0
0023b0bc: 2d 90 00 00           _move s2, zero
0023b0c0: 16 00 01 3c           lui at, 0x16
0023b0c4: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023b0c8: 80 40 01 3c           lui at, 0x4080
0023b0cc: 00 08 81 44           mtc1 at, f1
0023b0d0: b8 40 01 3c           lui at, 0x40b8
0023b0d4: 00 10 81 44           mtc1 at, f2
0023b0d8: 42 05 01 46           mul.S f21, f0, f1
0023b0dc: 02 00 40 12           beq s2, zero, 0023b0e8
0023b0e0: 02 00 02 46           _mul.S f0, f0, f2
0023b0e4: 06 a8 00 46           mov.S f0, f21
0023b0e8: 9c 22 0c c6           lwc1 f12, 0x229c ( s0 )
0023b0ec: 2d 20 00 00           move a0, zero
0023b0f0: 14 00 13 3c           lui s3, 0x14
0023b0f4: dc c7 08 0c           jal 00231f70
0023b0f8: 02 63 00 46           _mul.S f12, f12, f0
0023b0fc: 9c 22 02 c6           lwc1 f2, 0x229c ( s0 )
0023b100: 4c 3e 01 3c           lui at, 0x3e4c
0023b104: cd cc 21 34           ori at, at, 0xcccd
0023b108: 00 00 81 44           mtc1 at, f0
0023b10c: 00 00 00 00           nop 
0023b110: 34 00 02 46           c.lt.S f0, f2
0023b114: 00 00 00 00           nop 
0023b118: 17 00 00 45           bc1f 0023b178
0023b11c: 40 c9 63 26           _addiu v1, s3, -0x36c0
0023b120: a0 01 62 8c           lw v0, 0x1a0 ( v1 )
0023b124: 03 00 42 30           andi v0, v0, 0x3
0023b128: 18 00 40 14           bne v0, zero, 0023b18c
0023b12c: 64 81 81 c7           _lwc1 f1, -0x7e9c ( gp )
0023b130: 16 00 01 3c           lui at, 0x16
0023b134: 6c ed 2e c4           lwc1 f14, -0x1294 ( at )
0023b138: 2d 20 00 00           move a0, zero
0023b13c: bd 40 01 3c           lui at, 0x40bd
0023b140: 4e e4 21 34           ori at, at, 0xe44e
0023b144: 00 00 81 44           mtc1 at, f0
0023b148: 00 00 00 00           nop 
0023b14c: 82 73 00 46           mul.S f14, f14, f0
0023b150: dd 3c 01 3c           lui at, 0x3cdd
0023b154: 1b 2f 21 34           ori at, at, 0x2f1b
0023b158: 00 60 81 44           mtc1 at, f12
0023b15c: 99 3e 01 3c           lui at, 0x3e99
0023b160: 9a 99 21 34           ori at, at, 0x999a
0023b164: 00 68 81 44           mtc1 at, f13
0023b168: 02 0b 0c 46           mul.S f12, f1, f12
0023b16c: 42 0b 0d 46           mul.S f13, f1, f13
0023b170: 24 c9 08 0c           jal 00232490
0023b174: 82 73 02 46           _mul.S f14, f14, f2
0023b178: 40 c9 63 26           addiu v1, s3, -0x36c0
0023b17c: a0 01 62 8c           lw v0, 0x1a0 ( v1 )
0023b180: 03 00 42 30           andi v0, v0, 0x3
0023b184: 17 00 40 10           beq v0, zero, 0023b1e4
0023b188: 64 81 81 c7           _lwc1 f1, -0x7e9c ( gp )
0023b18c: 16 00 02 3c           lui v0, 0x16
0023b190: 16 00 01 3c           lui at, 0x16
0023b194: 6c ed 22 c4           lwc1 f2, -0x1294 ( at )
0023b198: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023b19c: 8b 3c 01 3c           lui at, 0x3c8b
0023b1a0: 96 43 21 34           ori at, at, 0x4396
0023b1a4: 00 60 81 44           mtc1 at, f12
0023b1a8: 2d 20 00 00           move a0, zero
0023b1ac: 99 3e 01 3c           lui at, 0x3e99
0023b1b0: 9a 99 21 34           ori at, at, 0x999a
0023b1b4: 00 68 81 44           mtc1 at, f13
0023b1b8: 96 40 01 3c           lui at, 0x4096
0023b1bc: e4 cb 21 34           ori at, at, 0xcbe4
0023b1c0: 00 70 81 44           mtc1 at, f14
0023b1c4: 02 0b 0c 46           mul.S f12, f1, f12
0023b1c8: 58 72 40 c4           lwc1 f0, 0x7258 ( v0 )
0023b1cc: 42 0b 0d 46           mul.S f13, f1, f13
0023b1d0: 82 13 0e 46           mul.S f14, f2, f14
0023b1d4: 80 01 14 c6           lwc1 f20, 0x180 ( s0 )
0023b1d8: 24 c9 08 0c           jal 00232490
0023b1dc: 80 01 00 e6           _swc1 f0, 0x180 ( s0 )
0023b1e0: 80 01 14 e6           swc1 f20, 0x180 ( s0 )
0023b1e4: 50 f3 b1 26           addiu s1, s5, -0xcb0
0023b1e8: 4c 3e 01 3c           lui at, 0x3e4c
0023b1ec: cd cc 21 34           ori at, at, 0xcccd
0023b1f0: 00 10 81 44           mtc1 at, f2
0023b1f4: 9c 22 21 c6           lwc1 f1, 0x229c ( s1 )
0023b1f8: 16 00 01 3c           lui at, 0x16
0023b1fc: 70 ed 23 c4           lwc1 f3, -0x1290 ( at )
0023b200: e0 40 01 3c           lui at, 0x40e0
0023b204: 00 00 81 44           mtc1 at, f0
0023b208: 34 08 02 46           c.lt.S f1, f2
0023b20c: 00 00 00 00           nop 
0023b210: 05 00 00 45           bc1f 0023b228
0023b214: 02 1b 00 46           _mul.S f12, f3, f0
0023b218: 60 40 01 3c           lui at, 0x4060
0023b21c: 00 00 81 44           mtc1 at, f0
0023b220: 00 00 00 00           nop 
0023b224: 02 1b 00 46           mul.S f12, f3, f0
0023b228: d6 d0 08 0c           jal 00234358
0023b22c: 00 00 00 00           _nop 
0023b230: 8e d5 08 0c           jal 00235638
0023b234: 00 00 00 00           _nop 
0023b238: 5e ca 08 0c           jal 00232978
0023b23c: 01 00 04 24           _li a0, 0x1
0023b240: 0e 00 40 12           beq s2, zero, 0023b27c
0023b244: e0 00 30 26           _addiu s0, s1, 0xe0
0023b248: 2d 20 00 02           move a0, s0
0023b24c: da 23 09 0c           jal 00248f68
0023b250: 2d 28 00 02           _move a1, s0
0023b254: 38 3f 01 3c           lui at, 0x3f38
0023b258: ec 51 21 34           ori at, at, 0x51ec
0023b25c: 00 60 81 44           mtc1 at, f12
0023b260: 2d 20 00 02           move a0, s0
0023b264: 2d 28 80 00           move a1, a0
0023b268: da 22 09 0c           jal 00248b68
0023b26c: 02 ab 0c 46           _mul.S f12, f21, f12
0023b270: e8 00 20 c6           lwc1 f0, 0xe8 ( s1 )
0023b274: 5e 04 00 10           b 0023c3f0
0023b278: 04 03 20 e6           _swc1 f0, 0x304 ( s1 )
0023b27c: 16 00 01 3c           lui at, 0x16
0023b280: 64 ed 22 c4           lwc1 f2, -0x129c ( at )
0023b284: 04 03 25 26           addiu a1, s1, 0x304
0023b288: d8 02 21 c6           lwc1 f1, 0x2d8 ( s1 )
0023b28c: 88 00 24 26           addiu a0, s1, 0x88
0023b290: 2e 3e 01 3c           lui at, 0x3e2e
0023b294: 7b 14 21 34           ori at, at, 0x147b
0023b298: 00 60 81 44           mtc1 at, f12
0023b29c: a3 3c 01 3c           lui at, 0x3ca3
0023b2a0: 0a d7 21 34           ori at, at, 0xd70a
0023b2a4: 00 68 81 44           mtc1 at, f13
0023b2a8: b3 3e 01 3c           lui at, 0x3eb3
0023b2ac: 33 33 21 34           ori at, at, 0x3333
0023b2b0: 00 70 81 44           mtc1 at, f14
0023b2b4: 00 0b 0c 46           add.S f12, f1, f12
0023b2b8: 16 00 01 3c           lui at, 0x16
0023b2bc: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023b2c0: 42 13 0d 46           mul.S f13, f2, f13
0023b2c4: 20 40 01 3c           lui at, 0x4020
0023b2c8: 00 78 81 44           mtc1 at, f15
0023b2cc: 82 13 0e 46           mul.S f14, f2, f14
0023b2d0: e0 c1 09 0c           jal 00270780
0023b2d4: c2 03 0f 46           _mul.S f15, f0, f15
0023b2d8: 46 04 00 10           b 0023c3f4
0023b2dc: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023b2e0: 76 b7 08 0c           jal 0022ddd8
0023b2e4: 03 00 04 24           _li a0, 0x3
0023b2e8: 02 00 03 24           li v1, 0x2
0023b2ec: 1b 00 43 14           bne v0, v1, 0023b35c
0023b2f0: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023b2f4: ff ff 02 24           li v0, -0x1
0023b2f8: 28 22 66 8c           lw a2, 0x2228 ( v1 )
0023b2fc: 0e 00 c2 10           beq a2, v0, 0023b338
0023b300: 70 00 04 24           _li a0, 0x70
0023b304: 14 00 02 3c           lui v0, 0x14
0023b308: 18 20 c4 00           mult a0, a2, a0
0023b30c: 50 e5 42 24           addiu v0, v0, -0x1ab0
0023b310: 80 20 65 8c           lw a1, 0x2080 ( v1 )
0023b314: 21 20 82 00           addu a0, a0, v0
0023b318: 88 00 83 8c           lw v1, 0x88 ( a0 )
0023b31c: 07 00 65 14           bne v1, a1, 0023b33c
0023b320: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023b324: 74 00 82 90           lbu v0, 0x74 ( a0 )
0023b328: 04 00 40 10           beq v0, zero, 0023b33c
0023b32c: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023b330: d2 84 0a 0c           jal 002a1348
0023b334: 2d 20 c0 00           _move a0, a2
0023b338: 50 f3 a2 26           addiu v0, s5, -0xcb0
0023b33c: ff ff 03 24           li v1, -0x1
0023b340: 80 20 45 8c           lw a1, 0x2080 ( v0 )
0023b344: 03 00 04 24           li a0, 0x3
0023b348: 28 22 43 ac           sw v1, 0x2228 ( v0 )
0023b34c: e6 d9 08 0c           jal 00236798
0023b350: 02 00 06 24           _li a2, 0x2
0023b354: 1b 00 00 10           b 0023b3c4
0023b358: 6c 81 81 c7           _lwc1 f1, -0x7e94 ( gp )
0023b35c: ff ff 02 24           li v0, -0x1
0023b360: 24 22 66 8c           lw a2, 0x2224 ( v1 )
0023b364: 0e 00 c2 10           beq a2, v0, 0023b3a0
0023b368: 70 00 04 24           _li a0, 0x70
0023b36c: 14 00 02 3c           lui v0, 0x14
0023b370: 18 20 c4 00           mult a0, a2, a0
0023b374: 50 e5 42 24           addiu v0, v0, -0x1ab0
0023b378: 80 20 65 8c           lw a1, 0x2080 ( v1 )
0023b37c: 21 20 82 00           addu a0, a0, v0
0023b380: 88 00 83 8c           lw v1, 0x88 ( a0 )
0023b384: 07 00 65 14           bne v1, a1, 0023b3a4
0023b388: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023b38c: 74 00 82 90           lbu v0, 0x74 ( a0 )
0023b390: 04 00 40 10           beq v0, zero, 0023b3a4
0023b394: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023b398: d2 84 0a 0c           jal 002a1348
0023b39c: 2d 20 c0 00           _move a0, a2
0023b3a0: 50 f3 a2 26           addiu v0, s5, -0xcb0
0023b3a4: ff ff 03 24           li v1, -0x1
0023b3a8: 80 20 45 8c           lw a1, 0x2080 ( v0 )
0023b3ac: 04 00 04 24           li a0, 0x4
0023b3b0: 24 22 43 ac           sw v1, 0x2224 ( v0 )
0023b3b4: e6 d9 08 0c           jal 00236798
0023b3b8: 12 00 06 24           _li a2, 0x12
0023b3bc: 16 00 01 3c           lui at, 0x16
0023b3c0: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
0023b3c4: 50 f3 b1 26           addiu s1, s5, -0xcb0
0023b3c8: 40 40 01 3c           lui at, 0x4040
0023b3cc: 00 00 81 44           mtc1 at, f0
0023b3d0: 03 00 03 24           li v1, 0x3
0023b3d4: a8 11 22 8e           lw v0, 0x11a8 ( s1 )
0023b3d8: 05 00 43 14           bne v0, v1, 0023b3f0
0023b3dc: 02 0d 00 46           _mul.S f20, f1, f0
0023b3e0: a0 40 01 3c           lui at, 0x40a0
0023b3e4: 00 00 81 44           mtc1 at, f0
0023b3e8: 00 00 00 00           nop 
0023b3ec: 02 0d 00 46           mul.S f20, f1, f0
0023b3f0: 06 a3 00 46           mov.S f12, f20
0023b3f4: dc c7 08 0c           jal 00231f70
0023b3f8: 2d 20 00 00           _move a0, zero
0023b3fc: e0 00 30 26           addiu s0, s1, 0xe0
0023b400: 16 00 01 3c           lui at, 0x16
0023b404: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
0023b408: 2d 20 00 00           move a0, zero
0023b40c: 16 00 01 3c           lui at, 0x16
0023b410: 64 ed 20 c4           lwc1 f0, -0x129c ( at )
0023b414: cc 3c 01 3c           lui at, 0x3ccc
0023b418: cd cc 21 34           ori at, at, 0xcccd
0023b41c: 00 60 81 44           mtc1 at, f12
0023b420: 99 3e 01 3c           lui at, 0x3e99
0023b424: 9a 99 21 34           ori at, at, 0x999a
0023b428: 00 68 81 44           mtc1 at, f13
0023b42c: 49 41 01 3c           lui at, 0x4149
0023b430: db 0f 21 34           ori at, at, 0xfdb
0023b434: 00 70 81 44           mtc1 at, f14
0023b438: 02 03 0c 46           mul.S f12, f0, f12
0023b43c: 42 03 0d 46           mul.S f13, f0, f13
0023b440: 24 c9 08 0c           jal 00232490
0023b444: 82 0b 0e 46           _mul.S f14, f1, f14
0023b448: 16 00 01 3c           lui at, 0x16
0023b44c: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
0023b450: 70 41 01 3c           lui at, 0x4170
0023b454: 00 60 81 44           mtc1 at, f12
0023b458: e0 40 01 3c           lui at, 0x40e0
0023b45c: 00 68 81 44           mtc1 at, f13
0023b460: 02 03 0c 46           mul.S f12, f0, f12
0023b464: ba c9 08 0c           jal 002326e8
0023b468: 42 03 0d 46           _mul.S f13, f0, f13
0023b46c: c3 47 01 3c           lui at, 0x47c3
0023b470: 80 4f 21 34           ori at, at, 0x4f80
0023b474: 00 60 81 44           mtc1 at, f12
0023b478: ce c9 08 0c           jal 00232738
0023b47c: 00 00 00 00           _nop 
0023b480: 8e d5 08 0c           jal 00235638
0023b484: 00 00 00 00           _nop 
0023b488: 2d 20 00 02           move a0, s0
0023b48c: da 23 09 0c           jal 00248f68
0023b490: 2d 28 00 02           _move a1, s0
0023b494: 38 3f 01 3c           lui at, 0x3f38
0023b498: ec 51 21 34           ori at, at, 0x51ec
0023b49c: 00 60 81 44           mtc1 at, f12
0023b4a0: 2d 20 00 02           move a0, s0
0023b4a4: 2d 28 80 00           move a1, a0
0023b4a8: da 22 09 0c           jal 00248b68
0023b4ac: 02 a3 0c 46           _mul.S f12, f20, f12
0023b4b0: 88 00 2c c6           lwc1 f12, 0x88 ( s1 )
0023b4b4: 10 04 20 c6           lwc1 f0, 0x410 ( s1 )
0023b4b8: 34 60 00 46           c.lt.S f12, f0
0023b4bc: 00 00 00 00           nop 
0023b4c0: bf 01 00 45           bc1f 0023bbc0
0023b4c4: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
0023b4c8: 10 04 24 26           addiu a0, s1, 0x410
0023b4cc: 80 40 01 3c           lui at, 0x4080
0023b4d0: 00 68 81 44           mtc1 at, f13
0023b4d4: ca c1 09 0c           jal 00270728
0023b4d8: 42 03 0d 46           _mul.S f13, f0, f13
0023b4dc: b8 01 00 10           b 0023bbc0
0023b4e0: 00 00 00 00           _nop 
0023b4e4: 50 f3 a4 26           addiu a0, s5, -0xcb0
0023b4e8: 1c 00 03 24           li v1, 0x1c
0023b4ec: 84 20 82 8c           lw v0, 0x2084 ( a0 )
0023b4f0: 11 00 43 14           bne v0, v1, 0023b538
0023b4f4: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023b4f8: d8 22 82 84           lh v0, 0x22d8 ( a0 )
0023b4fc: 0f 00 40 54           bnel v0, zero, 0023b53c
0023b500: a8 04 62 84           _lh v0, 0x4a8 ( v1 )
0023b504: a8 11 83 8c           lw v1, 0x11a8 ( a0 )
0023b508: 03 00 02 24           li v0, 0x3
0023b50c: 0a 00 62 14           bne v1, v0, 0023b538
0023b510: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023b514: 20 41 01 3c           lui at, 0x4120
0023b518: 00 60 81 44           mtc1 at, f12
0023b51c: c6 c7 08 0c           jal 00231f18
0023b520: 00 00 00 00           _nop 
0023b524: 03 00 40 10           beq v0, zero, 0023b534
0023b528: 04 00 04 24           _li a0, 0x4
0023b52c: ce d9 08 0c           jal 00236738
0023b530: 2d 28 00 00           _move a1, zero
0023b534: 50 f3 a3 26           addiu v1, s5, -0xcb0
0023b538: a8 04 62 84           lh v0, 0x4a8 ( v1 )
0023b53c: 07 00 40 10           beq v0, zero, 0023b55c
0023b540: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023b544: e2 12 62 90           lbu v0, 0x12e2 ( v1 )
0023b548: 05 00 40 50           beql v0, zero, 0023b560
0023b54c: 18 04 02 8e           _lw v0, 0x418 ( s0 )
0023b550: 94 01 60 c4           lwc1 f0, 0x194 ( v1 )
0023b554: 0e 00 00 10           b 0023b590
0023b558: 90 01 60 e4           _swc1 f0, 0x190 ( v1 )
0023b55c: 18 04 02 8e           lw v0, 0x418 ( s0 )
0023b560: 07 00 40 10           beq v0, zero, 0023b580
0023b564: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
0023b568: 2d 20 00 00           move a0, zero
0023b56c: b6 40 01 3c           lui at, 0x40b6
0023b570: 66 66 21 34           ori at, at, 0x6666
0023b574: 00 60 81 44           mtc1 at, f12
0023b578: dc c7 08 0c           jal 00231f70
0023b57c: 02 03 0c 46           _mul.S f12, f0, f12
0023b580: 24 04 0c c6           lwc1 f12, 0x424 ( s0 )
0023b584: dc c7 08 0c           jal 00231f70
0023b588: 2d 20 00 00           _move a0, zero
0023b58c: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023b590: 12 00 03 24           li v1, 0x12
0023b594: 84 20 02 8e           lw v0, 0x2084 ( s0 )
0023b598: 2e 00 43 54           bnel v0, v1, 0023b654
0023b59c: 98 01 06 8e           _lw a2, 0x198 ( s0 )
0023b5a0: 8c 83 08 0c           jal 00220e30
0023b5a4: 14 00 04 24           _li a0, 0x14
0023b5a8: 98 01 03 8e           lw v1, 0x198 ( s0 )
0023b5ac: 16 00 62 14           bne v1, v0, 0023b608
0023b5b0: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023b5b4: 03 00 04 24           li a0, 0x3
0023b5b8: 10 00 05 24           li a1, 0x10
0023b5bc: ea ac 08 0c           jal 0022b3a8
0023b5c0: 01 00 06 24           _li a2, 0x1
0023b5c4: 16 00 04 3c           lui a0, 0x16
0023b5c8: d0 12 84 8c           lw a0, 0x12d0 ( a0 )
0023b5cc: 0e 00 80 10           beq a0, zero, 0023b608
0023b5d0: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023b5d4: 84 00 0d c6           lwc1 f13, 0x84 ( s0 )
0023b5d8: 2d 30 00 00           move a2, zero
0023b5dc: 16 00 05 3c           lui a1, 0x16
0023b5e0: d8 12 a5 8c           lw a1, 0x12d8 ( a1 )
0023b5e4: cc 3e 01 3c           lui at, 0x3ecc
0023b5e8: cd cc 21 34           ori at, at, 0xcccd
0023b5ec: 00 70 81 44           mtc1 at, f14
0023b5f0: b3 3e 01 3c           lui at, 0x3eb3
0023b5f4: 33 33 21 34           ori at, at, 0x3333
0023b5f8: 00 78 81 44           mtc1 at, f15
0023b5fc: aa e0 0a 0c           jal 002b82a8
0023b600: 80 00 0c c6           _lwc1 f12, 0x80 ( s0 )
0023b604: 50 f3 a2 26           addiu v0, s5, -0xcb0
0023b608: 80 40 01 3c           lui at, 0x4080
0023b60c: 00 00 81 44           mtc1 at, f0
0023b610: a8 0a 41 c4           lwc1 f1, 0xaa8 ( v0 )
0023b614: 36 00 01 46           c.le.S f0, f1
0023b618: 00 00 00 00           nop 
0023b61c: 0c 00 00 45           bc1f 0023b650
0023b620: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023b624: e0 40 01 3c           lui at, 0x40e0
0023b628: 00 00 81 44           mtc1 at, f0
0023b62c: 00 00 00 00           nop 
0023b630: 36 08 00 46           c.le.S f1, f0
0023b634: 00 00 00 00           nop 
0023b638: 06 00 02 45           bc1fl 0023b654
0023b63c: 98 01 06 8e           _lw a2, 0x198 ( s0 )
0023b640: 07 00 04 24           li a0, 0x7
0023b644: 50 ac 08 0c           jal 0022b140
0023b648: 2d 28 00 00           _move a1, zero
0023b64c: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023b650: 98 01 06 8e           lw a2, 0x198 ( s0 )
0023b654: 20 04 05 8e           lw a1, 0x420 ( s0 )
0023b658: 06 00 c5 54           bnel a2, a1, 0023b674
0023b65c: 18 04 02 8e           _lw v0, 0x418 ( s0 )
0023b660: 00 04 04 26           addiu a0, s0, 0x400
0023b664: 80 00 03 26           addiu v1, s0, 0x80
0023b668: 00 00 62 78           lq v0, 0x0 ( v1 )
0023b66c: 00 00 82 7c           sq v0, 0x0 ( a0 )
0023b670: 18 04 02 8e           lw v0, 0x418 ( s0 )
0023b674: 11 00 40 54           bnel v0, zero, 0023b6bc
0023b678: 64 81 80 c7           _lwc1 f0, -0x7e9c ( gp )
0023b67c: 2a 10 c5 00           slt v0, a2, a1
0023b680: ab 00 40 10           beq v0, zero, 0023b930
0023b684: 0b 00 02 24           _li v0, 0xb
0023b688: 84 20 03 8e           lw v1, 0x2084 ( s0 )
0023b68c: a8 00 62 10           beq v1, v0, 0023b930
0023b690: 10 00 02 24           _li v0, 0x10
0023b694: a6 00 62 10           beq v1, v0, 0023b930
0023b698: 0c 00 02 24           _li v0, 0xc
0023b69c: a4 00 62 10           beq v1, v0, 0023b930
0023b6a0: 11 00 02 24           _li v0, 0x11
0023b6a4: a2 00 62 10           beq v1, v0, 0023b930
0023b6a8: 1c 00 02 24           _li v0, 0x1c
0023b6ac: a0 00 62 10           beq v1, v0, 0023b930
0023b6b0: 4c 00 02 24           _li v0, 0x4c
0023b6b4: 9e 00 62 10           beq v1, v0, 0023b930
0023b6b8: 64 81 80 c7           _lwc1 f0, -0x7e9c ( gp )
0023b6bc: 2d 20 00 00           move a0, zero
0023b6c0: 16 00 01 3c           lui at, 0x16
0023b6c4: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
0023b6c8: 75 3c 01 3c           lui at, 0x3c75
0023b6cc: 8f c2 21 34           ori at, at, 0xc28f
0023b6d0: 00 60 81 44           mtc1 at, f12
0023b6d4: 4c 3e 01 3c           lui at, 0x3e4c
0023b6d8: cd cc 21 34           ori at, at, 0xcccd
0023b6dc: 00 68 81 44           mtc1 at, f13
0023b6e0: 70 41 01 3c           lui at, 0x4170
0023b6e4: 45 28 21 34           ori at, at, 0x2845
0023b6e8: 00 70 81 44           mtc1 at, f14
0023b6ec: 02 03 0c 46           mul.S f12, f0, f12
0023b6f0: 42 03 0d 46           mul.S f13, f0, f13
0023b6f4: 24 c9 08 0c           jal 00232490
0023b6f8: 82 0b 0e 46           _mul.S f14, f1, f14
0023b6fc: 18 04 02 8e           lw v0, 0x418 ( s0 )
0023b700: 02 00 42 28           slti v0, v0, 0x2
0023b704: 07 00 40 14           bne v0, zero, 0023b724
0023b708: 94 01 14 c6           _lwc1 f20, 0x194 ( s0 )
0023b70c: cc 3e 01 3c           lui at, 0x3ecc
0023b710: cd cc 21 34           ori at, at, 0xcccd
0023b714: 00 00 81 44           mtc1 at, f0
0023b718: 00 00 00 00           nop 
0023b71c: 02 a0 00 46           mul.S f0, f20, f0
0023b720: 94 01 00 e6           swc1 f0, 0x194 ( s0 )
0023b724: c3 47 01 3c           lui at, 0x47c3
0023b728: 80 4f 21 34           ori at, at, 0x4f80
0023b72c: 00 60 81 44           mtc1 at, f12
0023b730: ce c9 08 0c           jal 00232738
0023b734: 00 00 00 00           _nop 
0023b738: 18 04 03 8e           lw v1, 0x418 ( s0 )
0023b73c: 01 00 02 24           li v0, 0x1
0023b740: 04 00 62 10           beq v1, v0, 0023b754
0023b744: 94 01 14 e6           _swc1 f20, 0x194 ( s0 )
0023b748: 80 04 0c c6           lwc1 f12, 0x480 ( s0 )
0023b74c: ba c9 08 0c           jal 002326e8
0023b750: 84 04 0d c6           _lwc1 f13, 0x484 ( s0 )
0023b754: 08 03 02 86           lh v0, 0x308 ( s0 )
0023b758: 01 00 40 54           bnel v0, zero, 0023b760
0023b75c: 94 01 00 ae           _sw zero, 0x194 ( s0 )
0023b760: 18 04 02 8e           lw v0, 0x418 ( s0 )
0023b764: 0d 00 40 10           beq v0, zero, 0023b79c
0023b768: 14 00 02 3c           _lui v0, 0x14
0023b76c: 14 cb 43 8c           lw v1, -0x34ec ( v0 )
0023b770: 05 00 60 10           beq v1, zero, 0023b788
0023b774: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023b778: 0a 03 02 86           lh v0, 0x30a ( s0 )
0023b77c: 02 00 40 54           bnel v0, zero, 0023b788
0023b780: 94 01 00 ae           _sw zero, 0x194 ( s0 )
0023b784: 50 f3 a3 26           addiu v1, s5, -0xcb0
0023b788: 18 04 62 8c           lw v0, 0x418 ( v1 )
0023b78c: 05 00 40 50           beql v0, zero, 0023b7a4
0023b790: 6c 81 8d c7           _lwc1 f13, -0x7e94 ( gp )
0023b794: 9e d9 08 0c           jal 00236678
0023b798: 84 04 6c c4           _lwc1 f12, 0x484 ( v1 )
0023b79c: 16 00 01 3c           lui at, 0x16
0023b7a0: 6c ed 2d c4           lwc1 f13, -0x1294 ( at )
0023b7a4: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023b7a8: 00 3f 01 3c           lui at, 0x3f00
0023b7ac: 00 60 81 44           mtc1 at, f12
0023b7b0: 14 ce 08 0c           jal 00233850
0023b7b4: 40 6b 0d 46           _add.S f13, f13, f13
0023b7b8: 84 20 03 8e           lw v1, 0x2084 ( s0 )
0023b7bc: 09 00 02 24           li v0, 0x9
0023b7c0: 14 00 62 54           bnel v1, v0, 0023b814
0023b7c4: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023b7c8: 8c 83 08 0c           jal 00220e30
0023b7cc: 04 00 04 24           _li a0, 0x4
0023b7d0: 20 04 03 8e           lw v1, 0x420 ( s0 )
0023b7d4: 98 01 04 8e           lw a0, 0x198 ( s0 )
0023b7d8: 21 18 62 00           addu v1, v1, v0
0023b7dc: 2a 18 83 00           slt v1, a0, v1
0023b7e0: 0b 00 60 10           beq v1, zero, 0023b810
0023b7e4: 70 81 8c c7           _lwc1 f12, -0x7e90 ( gp )
0023b7e8: 00 08 84 44           mtc1 a0, f1
0023b7ec: 00 00 00 00           nop 
0023b7f0: 60 08 80 46           cvt.s.W f1, f1
0023b7f4: 80 41 01 3c           lui at, 0x4180
0023b7f8: 00 00 81 44           mtc1 at, f0
0023b7fc: e0 00 04 26           addiu a0, s0, 0xe0
0023b800: 2d 28 80 00           move a1, a0
0023b804: 02 63 00 46           mul.S f12, f12, f0
0023b808: 68 23 09 0c           jal 00248da0
0023b80c: 02 63 01 46           _mul.S f12, f12, f1
0023b810: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023b814: 0a 00 03 24           li v1, 0xa
0023b818: 84 20 02 8e           lw v0, 0x2084 ( s0 )
0023b81c: 12 00 43 14           bne v0, v1, 0023b868
0023b820: 0a 00 04 24           _li a0, 0xa
0023b824: 8c 83 08 0c           jal 00220e30
0023b828: 22 00 04 24           _li a0, 0x22
0023b82c: 98 01 03 8e           lw v1, 0x198 ( s0 )
0023b830: 2a 10 62 00           slt v0, v1, v0
0023b834: 0b 00 40 10           beq v0, zero, 0023b864
0023b838: 70 81 8c c7           _lwc1 f12, -0x7e90 ( gp )
0023b83c: 00 08 83 44           mtc1 v1, f1
0023b840: 00 00 00 00           nop 
0023b844: 60 08 80 46           cvt.s.W f1, f1
0023b848: 54 42 01 3c           lui at, 0x4254
0023b84c: 00 00 81 44           mtc1 at, f0
0023b850: e0 00 04 26           addiu a0, s0, 0xe0
0023b854: 2d 28 80 00           move a1, a0
0023b858: 02 63 00 46           mul.S f12, f12, f0
0023b85c: 68 23 09 0c           jal 00248da0
0023b860: 02 63 01 46           _mul.S f12, f12, f1
0023b864: 0a 00 04 24           li a0, 0xa
0023b868: 8c 83 08 0c           jal 00220e30
0023b86c: 50 f3 b1 26           _addiu s1, s5, -0xcb0
0023b870: 98 01 23 8e           lw v1, 0x198 ( s1 )
0023b874: 2a 18 62 00           slt v1, v1, v0
0023b878: 47 00 60 10           beq v1, zero, 0023b998
0023b87c: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023b880: 9c 22 21 c6           lwc1 f1, 0x229c ( s1 )
0023b884: 4c 3e 01 3c           lui at, 0x3e4c
0023b888: cd cc 21 34           ori at, at, 0xcccd
0023b88c: 00 00 81 44           mtc1 at, f0
0023b890: 00 00 00 00           nop 
0023b894: 34 00 01 46           c.lt.S f0, f1
0023b898: 00 00 00 00           nop 
0023b89c: 3e 00 00 45           bc1f 0023b998
0023b8a0: 80 00 23 26           _addiu v1, s1, 0x80
0023b8a4: 00 00 62 78           lq v0, 0x0 ( v1 )
0023b8a8: 00 00 a2 7f           sq v0, 0x0 ( sp )
0023b8ac: 00 3f 01 3c           lui at, 0x3f00
0023b8b0: 00 60 81 44           mtc1 at, f12
0023b8b4: 2d 20 a0 03           move a0, sp
0023b8b8: aa 23 09 0c           jal 00248ea8
0023b8bc: 2d 28 a0 03           _move a1, sp
0023b8c0: 10 00 b0 27           addiu s0, sp, 0x10
0023b8c4: 00 00 a2 7b           lq v0, 0x0 ( sp )
0023b8c8: 00 00 02 7e           sq v0, 0x0 ( s0 )
0023b8cc: 59 3f 01 3c           lui at, 0x3f59
0023b8d0: 9a 99 21 34           ori at, at, 0x999a
0023b8d4: 00 a0 81 44           mtc1 at, f20
0023b8d8: be 85 08 0c           jal 002216f8
0023b8dc: 98 00 2c c6           _lwc1 f12, 0x98 ( s1 )
0023b8e0: 02 00 14 46           mul.S f0, f0, f20
0023b8e4: 10 00 a1 c7           lwc1 f1, 0x10 ( sp )
0023b8e8: 98 00 2c c6           lwc1 f12, 0x98 ( s1 )
0023b8ec: 40 08 00 46           add.S f1, f1, f0
0023b8f0: c4 85 08 0c           jal 00221710
0023b8f4: 10 00 a1 e7           _swc1 f1, 0x10 ( sp )
0023b8f8: 02 00 14 46           mul.S f0, f0, f20
0023b8fc: 14 00 a1 c7           lwc1 f1, 0x14 ( sp )
0023b900: 80 20 27 8e           lw a3, 0x2080 ( s1 )
0023b904: 2d 28 00 02           move a1, s0
0023b908: 2d 20 a0 03           move a0, sp
0023b90c: 04 00 06 24           li a2, 0x4
0023b910: 40 08 00 46           add.S f1, f1, f0
0023b914: 2d 40 00 00           move t0, zero
0023b918: 1c 46 08 0c           jal 00211870
0023b91c: 14 00 a1 e7           _swc1 f1, 0x14 ( sp )
0023b920: 1c 00 40 10           beq v0, zero, 0023b994
0023b924: 01 00 02 24           _li v0, 0x1
0023b928: 1a 00 00 10           b 0023b994
0023b92c: a4 04 22 a6           _sh v0, 0x4a4 ( s1 )
0023b930: d0 d2 08 0c           jal 00234b40
0023b934: 00 00 00 00           _nop 
0023b938: 50 f3 a4 26           addiu a0, s5, -0xcb0
0023b93c: 12 00 03 24           li v1, 0x12
0023b940: 84 20 82 8c           lw v0, 0x2084 ( a0 )
0023b944: 14 00 43 14           bne v0, v1, 0023b998
0023b948: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023b94c: e0 00 90 24           addiu s0, a0, 0xe0
0023b950: c6 84 08 0c           jal 00221318
0023b954: 2d 20 00 02           _move a0, s0
0023b958: 06 03 00 46           mov.S f12, f0
0023b95c: 16 00 01 3c           lui at, 0x16
0023b960: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
0023b964: 6c 40 01 3c           lui at, 0x406c
0023b968: cd cc 21 34           ori at, at, 0xcccd
0023b96c: 00 00 81 44           mtc1 at, f0
0023b970: 00 00 00 00           nop 
0023b974: 42 08 00 46           mul.S f1, f1, f0
0023b978: 34 08 0c 46           c.lt.S f1, f12
0023b97c: 00 00 00 00           nop 
0023b980: 01 00 03 45           bc1tl 0023b988
0023b984: 06 0b 00 46           _mov.S f12, f1
0023b988: 2d 20 00 02           move a0, s0
0023b98c: 18 85 08 0c           jal 00221460
0023b990: 2d 28 80 00           _move a1, a0
0023b994: 50 f3 a2 26           addiu v0, s5, -0xcb0
0023b998: d8 02 42 c4           lwc1 f2, 0x2d8 ( v0 )
0023b99c: 10 04 43 c4           lwc1 f3, 0x410 ( v0 )
0023b9a0: 34 18 02 46           c.lt.S f3, f2
0023b9a4: 00 00 00 00           nop 
0023b9a8: 0b 00 00 45           bc1f 0023b9d8
0023b9ac: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
0023b9b0: c0 40 01 3c           lui at, 0x40c0
0023b9b4: 00 08 81 44           mtc1 at, f1
0023b9b8: 00 00 00 00           nop 
0023b9bc: 02 00 01 46           mul.S f0, f0, f1
0023b9c0: 00 18 00 46           add.S f0, f3, f0
0023b9c4: 34 10 00 46           c.lt.S f2, f0
0023b9c8: 00 00 00 00           nop 
0023b9cc: 02 00 00 45           bc1f 0023b9d8
0023b9d0: 10 04 40 e4           _swc1 f0, 0x410 ( v0 )
0023b9d4: 10 04 42 e4           swc1 f2, 0x410 ( v0 )
0023b9d8: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023b9dc: 88 00 01 c6           lwc1 f1, 0x88 ( s0 )
0023b9e0: 10 04 00 c6           lwc1 f0, 0x410 ( s0 )
0023b9e4: 34 08 00 46           c.lt.S f1, f0
0023b9e8: 00 00 00 00           nop 
0023b9ec: 01 00 03 45           bc1tl 0023b9f4
0023b9f0: 10 04 01 e6           _swc1 f1, 0x410 ( s0 )
0023b9f4: 98 01 03 8e           lw v1, 0x198 ( s0 )
0023b9f8: 20 04 02 8e           lw v0, 0x420 ( s0 )
0023b9fc: 2a 10 43 00           slt v0, v0, v1
0023ba00: 1d 00 40 50           beql v0, zero, 0023ba78
0023ba04: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023ba08: 44 24 09 0c           jal 00249110
0023ba0c: e0 00 04 26           _addiu a0, s0, 0xe0
0023ba10: 83 3a 01 3c           lui at, 0x3a83
0023ba14: 6f 12 21 34           ori at, at, 0x126f
0023ba18: 00 08 81 44           mtc1 at, f1
0023ba1c: 00 00 00 00           nop 
0023ba20: 34 00 01 46           c.lt.S f0, f1
0023ba24: 00 00 00 00           nop 
0023ba28: 13 00 02 45           bc1fl 0023ba78
0023ba2c: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023ba30: 1c 04 02 86           lh v0, 0x41c ( s0 )
0023ba34: 07 00 40 50           beql v0, zero, 0023ba54
0023ba38: f8 03 01 c6           _lwc1 f1, 0x3f8 ( s0 )
0023ba3c: 98 01 03 8e           lw v1, 0x198 ( s0 )
0023ba40: d4 03 02 8e           lw v0, 0x3d4 ( s0 )
0023ba44: 2a 10 43 00           slt v0, v0, v1
0023ba48: 0b 00 40 50           beql v0, zero, 0023ba78
0023ba4c: 50 f3 b0 26           _addiu s0, s5, -0xcb0
0023ba50: f8 03 01 c6           lwc1 f1, 0x3f8 ( s0 )
0023ba54: 01 00 02 24           li v0, 0x1
0023ba58: 00 00 80 44           clear f0
0023ba5c: 00 00 00 00           nop 
0023ba60: 32 08 00 46           c.eq.S f1, f0
0023ba64: 00 00 00 00           nop 
0023ba68: 02 00 01 45           bc1t 0023ba74
0023ba6c: 1e 04 02 a6           _sh v0, 0x41e ( s0 )
0023ba70: a0 04 01 e6           swc1 f1, 0x4a0 ( s0 )
0023ba74: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023ba78: a4 20 02 92           lbu v0, 0x20a4 ( s0 )
0023ba7c: 04 00 40 54           bnel v0, zero, 0023ba90
0023ba80: 84 20 03 8e           _lw v1, 0x2084 ( s0 )
0023ba84: 8e d5 08 0c           jal 00235638
0023ba88: 00 00 00 00           _nop 
0023ba8c: 84 20 03 8e           lw v1, 0x2084 ( s0 )
0023ba90: 10 00 02 24           li v0, 0x10
0023ba94: 03 00 62 10           beq v1, v0, 0023baa4
0023ba98: 0d 00 02 24           _li v0, 0xd
0023ba9c: 09 00 62 14           bne v1, v0, 0023bac4
0023baa0: 50 f3 b1 26           _addiu s1, s5, -0xcb0
0023baa4: 8c 83 08 0c           jal 00220e30
0023baa8: 0c 00 04 24           _li a0, 0xc
0023baac: 98 01 03 8e           lw v1, 0x198 ( s0 )
0023bab0: 70 16 04 26           addiu a0, s0, 0x1670
0023bab4: 2a 10 43 00           slt v0, v0, v1
0023bab8: 42 dd 09 0c           jal 00277508
0023babc: 40 28 02 00           _sll a1, v0, 0x1
0023bac0: 50 f3 b1 26           addiu s1, s5, -0xcb0
0023bac4: 10 00 03 24           li v1, 0x10
0023bac8: 84 20 22 8e           lw v0, 0x2084 ( s1 )
0023bacc: 3a 00 43 14           bne v0, v1, 0023bbb8
0023bad0: 00 00 00 00           _nop 
0023bad4: 8c 83 08 0c           jal 00220e30
0023bad8: 08 00 04 24           _li a0, 0x8
0023badc: 98 01 23 8e           lw v1, 0x198 ( s1 )
0023bae0: 2a 10 43 00           slt v0, v0, v1
0023bae4: 34 00 40 10           beq v0, zero, 0023bbb8
0023bae8: 00 00 00 00           _nop 
0023baec: a8 0a 21 c6           lwc1 f1, 0xaa8 ( s1 )
0023baf0: e0 41 01 3c           lui at, 0x41e0
0023baf4: 00 00 81 44           mtc1 at, f0
0023baf8: 00 00 00 00           nop 
0023bafc: 34 08 00 46           c.lt.S f1, f0
0023bb00: 00 00 00 00           nop 
0023bb04: 2c 00 00 45           bc1f 0023bbb8
0023bb08: 00 00 00 00           _nop 
0023bb0c: 4c 3f 01 3c           lui at, 0x3f4c
0023bb10: cd cc 21 34           ori at, at, 0xcccd
0023bb14: 00 60 81 44           mtc1 at, f12
0023bb18: 00 68 80 44           clear f13
0023bb1c: 99 3e 01 3c           lui at, 0x3e99
0023bb20: 9a 99 21 34           ori at, at, 0x999a
0023bb24: 00 70 81 44           mtc1 at, f14
0023bb28: 3e 23 09 0c           jal 00248cf8
0023bb2c: 2d 20 a0 03           _move a0, sp
0023bb30: 66 3f 01 3c           lui at, 0x3f66
0023bb34: 66 66 21 34           ori at, at, 0x6666
0023bb38: 00 60 81 44           mtc1 at, f12
0023bb3c: 2d 20 a0 03           move a0, sp
0023bb40: 80 20 26 8e           lw a2, 0x2080 ( s1 )
0023bb44: 2d 28 00 00           move a1, zero
0023bb48: 1a 51 08 0c           jal 00214468
0023bb4c: 2d 38 00 00           _move a3, zero
0023bb50: 2d 80 40 00           move s0, v0
0023bb54: 18 00 00 12           beq s0, zero, 0023bbb8
0023bb58: 10 00 a4 27           _addiu a0, sp, 0x10
0023bb5c: e0 40 01 3c           lui at, 0x40e0
0023bb60: 00 60 81 44           mtc1 at, f12
0023bb64: 2d 98 80 00           move s3, a0
0023bb68: 84 84 08 0c           jal 00221210
0023bb6c: 00 01 25 26           _addiu a1, s1, 0x100
0023bb70: 11 00 00 1a           blez s0, 0023bbb8
0023bb74: 18 00 02 3c           _lui v0, 0x18
0023bb78: 2d 90 20 02           move s2, s1
0023bb7c: 80 83 51 24           addiu s1, v0, -0x7c80
0023bb80: 9e cc 09 0c           jal 00273278
0023bb84: 00 00 24 8e           _lw a0, 0x0 ( s1 )
0023bb88: 08 00 40 10           beq v0, zero, 0023bbac
0023bb8c: 01 00 06 3c           _lui a2, 0x1
0023bb90: 00 00 24 8e           lw a0, 0x0 ( s1 )
0023bb94: 80 20 45 8e           lw a1, 0x2080 ( s2 )
0023bb98: 80 00 47 26           addiu a3, s2, 0x80
0023bb9c: 80 3f 01 3c           lui at, 0x3f80
0023bba0: 00 60 81 44           mtc1 at, f12
0023bba4: aa ba 09 0c           jal 0026eaa8
0023bba8: 2d 40 60 02           _move t0, s3
0023bbac: ff ff 10 26           addiu s0, s0, -0x1
0023bbb0: f3 ff 00 16           bne s0, zero, 0023bb80
0023bbb4: 04 00 31 26           _addiu s1, s1, 0x4
0023bbb8: 7c d1 08 0c           jal 002345f0
0023bbbc: 00 00 00 00           _nop 
0023bbc0: 68 b2 08 0c           jal 0022c9a0
0023bbc4: 00 00 00 00           _nop 
0023bbc8: 0a 02 00 10           b 0023c3f4
0023bbcc: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023bbd0: 14 00 04 3c           lui a0, 0x14
0023bbd4: 30 f4 84 24           addiu a0, a0, -0xbd0
0023bbd8: c6 84 08 0c           jal 00221318
0023bbdc: 20 ff 90 24           _addiu s0, a0, -0xe0
0023bbe0: 06 05 00 46           mov.S f20, f0
0023bbe4: 16 00 01 3c           lui at, 0x16
0023bbe8: 70 ed 21 c4           lwc1 f1, -0x1290 ( at )
0023bbec: 80 40 01 3c           lui at, 0x4080
0023bbf0: 00 00 81 44           mtc1 at, f0
0023bbf4: 0e 03 02 86           lh v0, 0x30e ( s0 )
0023bbf8: 0b 00 40 14           bne v0, zero, 0023bc28
0023bbfc: 42 0d 00 46           _mul.S f21, f1, f0
0023bc00: 8c 83 08 0c           jal 00220e30
0023bc04: 0a 00 04 24           _li a0, 0xa
0023bc08: 98 01 03 8e           lw v1, 0x198 ( s0 )
0023bc0c: 2a 10 43 00           slt v0, v0, v1
0023bc10: 05 00 40 10           beq v0, zero, 0023bc28
0023bc14: 70 81 81 c7           _lwc1 f1, -0x7e90 ( gp )
0023bc18: 20 41 01 3c           lui at, 0x4120
0023bc1c: 00 00 81 44           mtc1 at, f0
0023bc20: 00 00 00 00           nop 
0023bc24: 42 0d 00 46           mul.S f21, f1, f0
0023bc28: 01 a5 15 46           sub.S f20, f20, f21
0023bc2c: 00 68 80 44           clear f13
0023bc30: 00 00 00 00           nop 
0023bc34: 34 a0 0d 46           c.lt.S f20, f13
0023bc38: 00 00 00 00           nop 
0023bc3c: 01 00 03 45           bc1tl 0023bc44
0023bc40: 06 6d 00 46           _mov.S f20, f13
0023bc44: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023bc48: e7 12 02 92           lbu v0, 0x12e7 ( s0 )
0023bc4c: 06 00 40 10           beq v0, zero, 0023bc68
0023bc50: e0 00 10 26           _addiu s0, s0, 0xe0
0023bc54: 6c 40 01 3c           lui at, 0x406c
0023bc58: cd cc 21 34           ori at, at, 0xcccd
0023bc5c: 00 60 81 44           mtc1 at, f12
0023bc60: 9a da 08 0c           jal 00236a68
0023bc64: 00 00 00 00           _nop 
0023bc68: 06 a3 00 46           mov.S f12, f20
0023bc6c: 2d 20 00 02           move a0, s0
0023bc70: 18 85 08 0c           jal 00221460
0023bc74: 2d 28 00 02           _move a1, s0
0023bc78: d3 01 00 10           b 0023c3c8
0023bc7c: 2d 20 00 02           _move a0, s0
0023bc80: 14 00 06 3c           lui a2, 0x14
0023bc84: 2d 20 a0 03           move a0, sp
0023bc88: 90 09 c6 24           addiu a2, a2, 0x990
0023bc8c: 2d 28 c0 00           move a1, a2
0023bc90: c0 e9 d0 24           addiu s0, a2, -0x1640
0023bc94: 6e 84 08 0c           jal 002211b8
0023bc98: 40 ea c6 24           _addiu a2, a2, -0x15c0
0023bc9c: 00 00 ac c7           lwc1 f12, 0x0 ( sp )
0023bca0: f0 85 08 0c           jal 002217c0
0023bca4: 04 00 ad c7           _lwc1 f13, 0x4 ( sp )
0023bca8: 80 01 00 e6           swc1 f0, 0x180 ( s0 )
0023bcac: c6 84 08 0c           jal 00221318
0023bcb0: 2d 20 a0 03           _move a0, sp
0023bcb4: 06 05 00 46           mov.S f20, f0
0023bcb8: 4c 3e 01 3c           lui at, 0x3e4c
0023bcbc: cd cc 21 34           ori at, at, 0xcccd
0023bcc0: 00 00 81 44           mtc1 at, f0
0023bcc4: 00 00 00 00           nop 
0023bcc8: 34 00 14 46           c.lt.S f0, f20
0023bccc: 00 00 00 00           nop 
0023bcd0: 28 00 00 45           bc1f 0023bd74
0023bcd4: 00 00 ac c7           _lwc1 f12, 0x0 ( sp )
0023bcd8: 80 3f 01 3c           lui at, 0x3f80
0023bcdc: 00 00 81 44           mtc1 at, f0
0023bce0: 04 00 ad c7           lwc1 f13, 0x4 ( sp )
0023bce4: f0 85 08 0c           jal 002217c0
0023bce8: 9c 22 00 e6           _swc1 f0, 0x229c ( s0 )
0023bcec: 18 00 02 3c           lui v0, 0x18
0023bcf0: 90 01 14 e6           swc1 f20, 0x190 ( s0 )
0023bcf4: 80 01 00 e6           swc1 f0, 0x180 ( s0 )
0023bcf8: 38 c2 42 24           addiu v0, v0, -0x3dc8
0023bcfc: 0c 00 40 c4           lwc1 f0, 0xc ( v0 )
0023bd00: 34 a0 00 46           c.lt.S f20, f0
0023bd04: 00 00 00 00           nop 
0023bd08: 02 00 02 45           bc1fl 0023bd14
0023bd0c: 18 00 40 c4           _lwc1 f0, 0x18 ( v0 )
0023bd10: 08 00 40 c4           lwc1 f0, 0x8 ( v0 )
0023bd14: 16 00 01 3c           lui at, 0x16
0023bd18: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
0023bd1c: 02 00 01 46           mul.S f0, f0, f1
0023bd20: 90 01 00 e6           swc1 f0, 0x190 ( s0 )
0023bd24: 50 f3 a4 26           addiu a0, s5, -0xcb0
0023bd28: 03 00 02 24           li v0, 0x3
0023bd2c: a4 20 83 90           lbu v1, 0x20a4 ( a0 )
0023bd30: 05 00 62 14           bne v1, v0, 0023bd48
0023bd34: 01 00 02 24           _li v0, 0x1
0023bd38: c0 3f 01 3c           lui at, 0x3fc0
0023bd3c: 00 08 81 44           mtc1 at, f1
0023bd40: 08 00 00 10           b 0023bd64
0023bd44: 6c 81 80 c7           _lwc1 f0, -0x7e94 ( gp )
0023bd48: 11 00 62 14           bne v1, v0, 0023bd90
0023bd4c: 50 f3 a5 26           _addiu a1, s5, -0xcb0
0023bd50: 16 00 01 3c           lui at, 0x16
0023bd54: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023bd58: 66 3f 01 3c           lui at, 0x3f66
0023bd5c: 66 66 21 34           ori at, at, 0x6666
0023bd60: 00 08 81 44           mtc1 at, f1
0023bd64: 00 00 00 00           nop 
0023bd68: 02 00 01 46           mul.S f0, f0, f1
0023bd6c: 07 00 00 10           b 0023bd8c
0023bd70: 90 01 80 e4           _swc1 f0, 0x190 ( a0 )
0023bd74: 00 3f 01 3c           lui at, 0x3f00
0023bd78: 00 00 81 44           mtc1 at, f0
0023bd7c: 4c 16 01 c6           lwc1 f1, 0x164c ( s0 )
0023bd80: 9c 22 00 e6           swc1 f0, 0x229c ( s0 )
0023bd84: 80 01 01 e6           swc1 f1, 0x180 ( s0 )
0023bd88: 90 01 00 ae           sw zero, 0x190 ( s0 )
0023bd8c: 50 f3 a5 26           addiu a1, s5, -0xcb0
0023bd90: 03 00 02 24           li v0, 0x3
0023bd94: a4 20 a3 90           lbu v1, 0x20a4 ( a1 )
0023bd98: 11 00 62 14           bne v1, v0, 0023bde0
0023bd9c: 01 00 04 24           _li a0, 0x1
0023bda0: 16 00 01 3c           lui at, 0x16
0023bda4: 64 ed 21 c4           lwc1 f1, -0x129c ( at )
0023bda8: 2d 20 00 00           move a0, zero
0023bdac: f5 3c 01 3c           lui at, 0x3cf5
0023bdb0: 8f c2 21 34           ori at, at, 0xc28f
0023bdb4: 00 60 81 44           mtc1 at, f12
0023bdb8: 99 3e 01 3c           lui at, 0x3e99
0023bdbc: 9a 99 21 34           ori at, at, 0x999a
0023bdc0: 00 68 81 44           mtc1 at, f13
0023bdc4: 16 00 01 3c           lui at, 0x16
0023bdc8: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023bdcc: b2 40 01 3c           lui at, 0x40b2
0023bdd0: c2 b8 21 34           ori at, at, 0xb8c2
0023bdd4: 00 70 81 44           mtc1 at, f14
0023bdd8: 23 00 00 10           b 0023be68
0023bddc: 02 0b 0c 46           _mul.S f12, f1, f12
0023bde0: 0f 00 64 14           bne v1, a0, 0023be20
0023bde4: 64 81 81 c7           _lwc1 f1, -0x7e9c ( gp )
0023bde8: 2d 20 00 00           move a0, zero
0023bdec: f5 3c 01 3c           lui at, 0x3cf5
0023bdf0: 8f c2 21 34           ori at, at, 0xc28f
0023bdf4: 00 60 81 44           mtc1 at, f12
0023bdf8: 99 3e 01 3c           lui at, 0x3e99
0023bdfc: 9a 99 21 34           ori at, at, 0x999a
0023be00: 00 68 81 44           mtc1 at, f13
0023be04: 16 00 01 3c           lui at, 0x16
0023be08: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023be0c: fb 40 01 3c           lui at, 0x40fb
0023be10: d1 53 21 34           ori at, at, 0x53d1
0023be14: 00 70 81 44           mtc1 at, f14
0023be18: 13 00 00 10           b 0023be68
0023be1c: 02 0b 0c 46           _mul.S f12, f1, f12
0023be20: 20 00 60 14           bne v1, zero, 0023bea4
0023be24: 70 81 81 c7           _lwc1 f1, -0x7e90 ( gp )
0023be28: 88 20 a2 8c           lw v0, 0x2088 ( a1 )
0023be2c: 13 00 44 14           bne v0, a0, 0023be7c
0023be30: 64 81 81 c7           _lwc1 f1, -0x7e9c ( gp )
0023be34: 2d 20 00 00           move a0, zero
0023be38: 83 3c 01 3c           lui at, 0x3c83
0023be3c: 6f 12 21 34           ori at, at, 0x126f
0023be40: 00 60 81 44           mtc1 at, f12
0023be44: 19 3e 01 3c           lui at, 0x3e19
0023be48: 9a 99 21 34           ori at, at, 0x999a
0023be4c: 00 68 81 44           mtc1 at, f13
0023be50: 16 00 01 3c           lui at, 0x16
0023be54: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023be58: 02 0b 0c 46           mul.S f12, f1, f12
0023be5c: 1f 41 01 3c           lui at, 0x411f
0023be60: 8d 2c 21 34           ori at, at, 0x2c8d
0023be64: 00 70 81 44           mtc1 at, f14
0023be68: 42 0b 0d 46           mul.S f13, f1, f13
0023be6c: 24 c9 08 0c           jal 00232490
0023be70: 82 03 0e 46           _mul.S f14, f0, f14
0023be74: 04 00 00 10           b 0023be88
0023be78: 50 f3 a2 26           _addiu v0, s5, -0xcb0
0023be7c: 66 c9 08 0c           jal 00232598
0023be80: 00 00 00 00           _nop 
0023be84: 50 f3 a2 26           addiu v0, s5, -0xcb0
0023be88: a4 20 43 90           lbu v1, 0x20a4 ( v0 )
0023be8c: 05 00 60 14           bne v1, zero, 0023bea4
0023be90: 70 81 81 c7           _lwc1 f1, -0x7e90 ( gp )
0023be94: 8e d5 08 0c           jal 00235638
0023be98: 00 00 00 00           _nop 
0023be9c: 16 00 01 3c           lui at, 0x16
0023bea0: 70 ed 21 c4           lwc1 f1, -0x1290 ( at )
0023bea4: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023bea8: f0 40 01 3c           lui at, 0x40f0
0023beac: 00 00 81 44           mtc1 at, f0
0023beb0: 08 41 01 3c           lui at, 0x4108
0023beb4: 00 68 81 44           mtc1 at, f13
0023beb8: 02 08 00 46           mul.S f0, f1, f0
0023bebc: 80 3f 01 3c           lui at, 0x3f80
0023bec0: 00 60 81 44           mtc1 at, f12
0023bec4: 42 0b 0d 46           mul.S f13, f1, f13
0023bec8: ba c9 08 0c           jal 002326e8
0023becc: 02 03 0c 46           _mul.S f12, f0, f12
0023bed0: c3 47 01 3c           lui at, 0x47c3
0023bed4: 80 4f 21 34           ori at, at, 0x4f80
0023bed8: 00 60 81 44           mtc1 at, f12
0023bedc: ce c9 08 0c           jal 00232738
0023bee0: 00 00 00 00           _nop 
0023bee4: a4 20 02 92           lbu v0, 0x20a4 ( s0 )
0023bee8: 04 00 40 54           bnel v0, zero, 0023befc
0023beec: 0e 03 02 86           _lh v0, 0x30e ( s0 )
0023bef0: 5e ca 08 0c           jal 00232978
0023bef4: 01 00 04 24           _li a0, 0x1
0023bef8: 0e 03 02 86           lh v0, 0x30e ( s0 )
0023befc: 06 00 40 10           beq v0, zero, 0023bf18
0023bf00: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
0023bf04: 00 01 05 26           addiu a1, s0, 0x100
0023bf08: c8 41 01 3c           lui at, 0x41c8
0023bf0c: 00 60 81 44           mtc1 at, f12
0023bf10: f8 00 00 10           b 0023c2f4
0023bf14: e0 00 04 26           _addiu a0, s0, 0xe0
0023bf18: 16 00 01 3c           lui at, 0x16
0023bf1c: 70 ed 2c c4           lwc1 f12, -0x1290 ( at )
0023bf20: e0 00 04 26           addiu a0, s0, 0xe0
0023bf24: 58 42 01 3c           lui at, 0x4258
0023bf28: 00 00 81 44           mtc1 at, f0
0023bf2c: 21 01 00 10           b 0023c3b4
0023bf30: 2d 28 80 00           _move a1, a0
0023bf34: 14 00 02 3c           lui v0, 0x14
0023bf38: 2d 20 a0 03           move a0, sp
0023bf3c: 90 09 51 24           addiu s1, v0, 0x990
0023bf40: 2d 28 20 02           move a1, s1
0023bf44: 6e 84 08 0c           jal 002211b8
0023bf48: 40 ea 26 26           _addiu a2, s1, -0x15c0
0023bf4c: 10 eb 30 26           addiu s0, s1, -0x14f0
0023bf50: 2d 20 a0 03           move a0, sp
0023bf54: aa 84 08 0c           jal 002212a8
0023bf58: 2d 28 00 02           _move a1, s0
0023bf5c: 00 08 80 44           clear f1
0023bf60: 00 00 00 00           nop 
0023bf64: 34 00 01 46           c.lt.S f0, f1
0023bf68: 00 00 00 00           nop 
0023bf6c: 04 00 02 45           bc1fl 0023bf80
0023bf70: a0 ea 30 26           _addiu s0, s1, -0x1560
0023bf74: 5c 84 08 0c           jal 00221170
0023bf78: 2d 20 00 02           _move a0, s0
0023bf7c: a0 ea 30 26           addiu s0, s1, -0x1560
0023bf80: 5c 84 08 0c           jal 00221170
0023bf84: 2d 20 00 02           _move a0, s0
0023bf88: 16 00 01 3c           lui at, 0x16
0023bf8c: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
0023bf90: 40 41 01 3c           lui at, 0x4140
0023bf94: 00 60 81 44           mtc1 at, f12
0023bf98: 9e d9 08 0c           jal 00236678
0023bf9c: 02 03 0c 46           _mul.S f12, f0, f12
0023bfa0: 5e ca 08 0c           jal 00232978
0023bfa4: 2d 20 00 00           _move a0, zero
0023bfa8: ce ec 22 86           lh v0, -0x1332 ( s1 )
0023bfac: 06 00 40 10           beq v0, zero, 0023bfc8
0023bfb0: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
0023bfb4: 2d 20 00 02           move a0, s0
0023bfb8: c8 41 01 3c           lui at, 0x41c8
0023bfbc: 00 60 81 44           mtc1 at, f12
0023bfc0: cc 00 00 10           b 0023c2f4
0023bfc4: c0 ea 25 26           _addiu a1, s1, -0x1540
0023bfc8: 2d 20 00 02           move a0, s0
0023bfcc: 58 42 01 3c           lui at, 0x4258
0023bfd0: 00 60 81 44           mtc1 at, f12
0023bfd4: f7 00 00 10           b 0023c3b4
0023bfd8: 2d 28 80 00           _move a1, a0
0023bfdc: 14 00 04 3c           lui a0, 0x14
0023bfe0: 5c 84 08 0c           jal 00221170
0023bfe4: 30 f4 84 24           _addiu a0, a0, -0xbd0
0023bfe8: 02 01 00 10           b 0023c3f4
0023bfec: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023bff0: 00 a0 80 44           clear f20
0023bff4: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023bff8: 6c 40 01 3c           lui at, 0x406c
0023bffc: cd cc 21 34           ori at, at, 0xcccd
0023c000: 00 60 81 44           mtc1 at, f12
0023c004: e0 00 11 26           addiu s1, s0, 0xe0
0023c008: 49 41 01 3c           lui at, 0x4149
0023c00c: 9a 99 21 34           ori at, at, 0x999a
0023c010: 00 a8 81 44           mtc1 at, f21
0023c014: 9a da 08 0c           jal 00236a68
0023c018: 46 a3 00 46           _mov.S f13, f20
0023c01c: 80 3f 01 3c           lui at, 0x3f80
0023c020: 00 60 81 44           mtc1 at, f12
0023c024: dc c7 08 0c           jal 00231f70
0023c028: 2d 20 00 00           _move a0, zero
0023c02c: 16 00 01 3c           lui at, 0x16
0023c030: 70 ed 2d c4           lwc1 f13, -0x1290 ( at )
0023c034: 06 a3 00 46           mov.S f12, f20
0023c038: 90 01 14 e6           swc1 f20, 0x190 ( s0 )
0023c03c: ba c9 08 0c           jal 002326e8
0023c040: 42 6b 15 46           _mul.S f13, f13, f21
0023c044: 5c 84 08 0c           jal 00221170
0023c048: 2d 20 20 02           _move a0, s1
0023c04c: 16 00 01 3c           lui at, 0x16
0023c050: 70 ed 2c c4           lwc1 f12, -0x1290 ( at )
0023c054: 9e d9 08 0c           jal 00236678
0023c058: 02 63 15 46           _mul.S f12, f12, f21
0023c05c: 5e ca 08 0c           jal 00232978
0023c060: 2d 20 00 00           _move a0, zero
0023c064: 0e 03 02 86           lh v0, 0x30e ( s0 )
0023c068: 06 00 40 10           beq v0, zero, 0023c084
0023c06c: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
0023c070: 2d 20 20 02           move a0, s1
0023c074: c8 41 01 3c           lui at, 0x41c8
0023c078: 00 60 81 44           mtc1 at, f12
0023c07c: 9d 00 00 10           b 0023c2f4
0023c080: 20 01 05 26           _addiu a1, s0, 0x120
0023c084: 2d 20 20 02           move a0, s1
0023c088: 58 42 01 3c           lui at, 0x4258
0023c08c: 00 60 81 44           mtc1 at, f12
0023c090: c8 00 00 10           b 0023c3b4
0023c094: 2d 28 80 00           _move a1, a0
0023c098: 16 00 01 3c           lui at, 0x16
0023c09c: 6c ed 21 c4           lwc1 f1, -0x1294 ( at )
0023c0a0: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023c0a4: b0 40 01 3c           lui at, 0x40b0
0023c0a8: 00 10 81 44           mtc1 at, f2
0023c0ac: 16 00 01 3c           lui at, 0x16
0023c0b0: 70 ed 23 c4           lwc1 f3, -0x1290 ( at )
0023c0b4: c8 41 01 3c           lui at, 0x41c8
0023c0b8: 00 60 81 44           mtc1 at, f12
0023c0bc: 42 08 02 46           mul.S f1, f1, f2
0023c0c0: ec 02 00 c6           lwc1 f0, 0x2ec ( s0 )
0023c0c4: 02 1b 0c 46           mul.S f12, f3, f12
0023c0c8: 80 01 00 e6           swc1 f0, 0x180 ( s0 )
0023c0cc: d6 d0 08 0c           jal 00234358
0023c0d0: 90 01 01 e6           _swc1 f1, 0x190 ( s0 )
0023c0d4: 16 00 01 3c           lui at, 0x16
0023c0d8: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
0023c0dc: 20 01 05 26           addiu a1, s0, 0x120
0023c0e0: 90 41 01 3c           lui at, 0x4190
0023c0e4: 00 60 81 44           mtc1 at, f12
0023c0e8: b2 00 00 10           b 0023c3b4
0023c0ec: e0 00 04 26           _addiu a0, s0, 0xe0
0023c0f0: 16 00 01 3c           lui at, 0x16
0023c0f4: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023c0f8: 2d 20 00 00           move a0, zero
0023c0fc: c0 3f 01 3c           lui at, 0x3fc0
0023c100: 00 60 81 44           mtc1 at, f12
0023c104: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023c108: dc c7 08 0c           jal 00231f70
0023c10c: 02 03 0c 46           _mul.S f12, f0, f12
0023c110: c4 01 02 8e           lw v0, 0x1c4 ( s0 )
0023c114: 05 00 40 14           bne v0, zero, 0023c12c
0023c118: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
0023c11c: d0 d2 08 0c           jal 00234b40
0023c120: 00 00 00 00           _nop 
0023c124: 16 00 01 3c           lui at, 0x16
0023c128: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
0023c12c: e0 00 04 26           addiu a0, s0, 0xe0
0023c130: a8 41 01 3c           lui at, 0x41a8
0023c134: 00 60 81 44           mtc1 at, f12
0023c138: 2d 28 80 00           move a1, a0
0023c13c: da 22 09 0c           jal 00248b68
0023c140: 02 03 0c 46           _mul.S f12, f0, f12
0023c144: 16 00 01 3c           lui at, 0x16
0023c148: 6c ed 22 c4           lwc1 f2, -0x1294 ( at )
0023c14c: 70 c1 01 3c           lui at, 0xc170
0023c150: 00 00 81 44           mtc1 at, f0
0023c154: e8 00 01 c6           lwc1 f1, 0xe8 ( s0 )
0023c158: 82 10 00 46           mul.S f2, f2, f0
0023c15c: 34 08 02 46           c.lt.S f1, f2
0023c160: 00 00 00 00           nop 
0023c164: a2 00 03 45           bc1tl 0023c3f0
0023c168: e8 00 02 e6           _swc1 f2, 0xe8 ( s0 )
0023c16c: a1 00 00 10           b 0023c3f4
0023c170: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023c174: 50 f3 b0 26           addiu s0, s5, -0xcb0
0023c178: c0 3f 01 3c           lui at, 0x3fc0
0023c17c: 00 a0 81 44           mtc1 at, f20
0023c180: 98 00 0c c6           lwc1 f12, 0x98 ( s0 )
0023c184: 40 88 08 0c           jal 00222100
0023c188: 80 01 0d c6           _lwc1 f13, 0x180 ( s0 )
0023c18c: 16 00 01 3c           lui at, 0x16
0023c190: 6c ed 2c c4           lwc1 f12, -0x1294 ( at )
0023c194: 46 05 00 46           mov.S f21, f0
0023c198: 2d 20 00 00           move a0, zero
0023c19c: dc c7 08 0c           jal 00231f70
0023c1a0: 02 63 14 46           _mul.S f12, f12, f20
0023c1a4: 16 00 01 3c           lui at, 0x16
0023c1a8: 6c ed 20 c4           lwc1 f0, -0x1294 ( at )
0023c1ac: 0c 3f 01 3c           lui at, 0x3f0c
0023c1b0: cd cc 21 34           ori at, at, 0xcccd
0023c1b4: 00 10 81 44           mtc1 at, f2
0023c1b8: 02 00 14 46           mul.S f0, f0, f20
0023c1bc: 90 01 01 c6           lwc1 f1, 0x190 ( s0 )
0023c1c0: 02 00 02 46           mul.S f0, f0, f2
0023c1c4: 34 08 00 46           c.lt.S f1, f0
0023c1c8: 00 00 00 00           nop 
0023c1cc: 01 00 03 45           bc1tl 0023c1d4
0023c1d0: 90 01 00 e6           _swc1 f0, 0x190 ( s0 )
0023c1d4: 99 3e 01 3c           lui at, 0x3e99
0023c1d8: 9a 99 21 34           ori at, at, 0x999a
0023c1dc: 00 00 81 44           mtc1 at, f0
0023c1e0: 80 3f 01 3c           lui at, 0x3f80
0023c1e4: 00 a0 81 44           mtc1 at, f20
0023c1e8: 02 a8 00 46           mul.S f0, f21, f0
0023c1ec: 9c 22 02 c6           lwc1 f2, 0x229c ( s0 )
0023c1f0: 00 18 80 44           clear f3
0023c1f4: b3 3e 01 3c           lui at, 0x3eb3
0023c1f8: 33 33 21 34           ori at, at, 0x3333
0023c1fc: 00 08 81 44           mtc1 at, f1
0023c200: 01 a5 00 46           sub.S f20, f20, f0
0023c204: 34 a0 03 46           c.lt.S f20, f3
0023c208: 00 00 00 00           nop 
0023c20c: 02 00 00 45           bc1f 0023c218
0023c210: 80 10 01 46           _add.S f2, f2, f1
0023c214: 06 1d 00 46           mov.S f20, f3
0023c218: 16 00 01 3c           lui at, 0x16
0023c21c: 64 ed 21 c4           lwc1 f1, -0x129c ( at )
0023c220: 2d 20 00 00           move a0, zero
0023c224: 11 40 01 3c           lui at, 0x4011
0023c228: 1e 36 21 34           ori at, at, 0x361e
0023c22c: 00 00 81 44           mtc1 at, f0
0023c230: 16 00 01 3c           lui at, 0x16
0023c234: 6c ed 2e c4           lwc1 f14, -0x1294 ( at )
0023c238: 0f 3d 01 3c           lui at, 0x3d0f
0023c23c: 29 5c 21 34           ori at, at, 0x5c29
0023c240: 00 60 81 44           mtc1 at, f12
0023c244: 82 73 00 46           mul.S f14, f14, f0
0023c248: cc 3d 01 3c           lui at, 0x3dcc
0023c24c: cd cc 21 34           ori at, at, 0xcccd
0023c250: 00 68 81 44           mtc1 at, f13
0023c254: 02 0b 0c 46           mul.S f12, f1, f12
0023c258: 42 0b 0d 46           mul.S f13, f1, f13
0023c25c: 82 73 02 46           mul.S f14, f14, f2
0023c260: 24 c9 08 0c           jal 00232490
0023c264: 02 63 02 46           _mul.S f12, f12, f2
0023c268: 16 00 01 3c           lui at, 0x16
0023c26c: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
0023c270: f0 40 01 3c           lui at, 0x40f0
0023c274: 00 60 81 44           mtc1 at, f12
0023c278: 08 41 01 3c           lui at, 0x4108
0023c27c: 00 68 81 44           mtc1 at, f13
0023c280: 02 03 0c 46           mul.S f12, f0, f12
0023c284: 42 03 0d 46           mul.S f13, f0, f13
0023c288: ba c9 08 0c           jal 002326e8
0023c28c: 02 63 14 46           _mul.S f12, f12, f20
0023c290: b8 03 02 86           lh v0, 0x3b8 ( s0 )
0023c294: 08 00 40 10           beq v0, zero, 0023c2b8
0023c298: 00 00 00 00           _nop 
0023c29c: 08 03 02 86           lh v0, 0x308 ( s0 )
0023c2a0: 05 00 40 14           bne v0, zero, 0023c2b8
0023c2a4: 00 00 00 00           _nop 
0023c2a8: ce c9 08 0c           jal 00232738
0023c2ac: 80 01 0c c6           _lwc1 f12, 0x180 ( s0 )
0023c2b0: 06 00 00 10           b 0023c2cc
0023c2b4: 00 00 00 00           _nop 
0023c2b8: c3 47 01 3c           lui at, 0x47c3
0023c2bc: 80 4f 21 34           ori at, at, 0x4f80
0023c2c0: 00 60 81 44           mtc1 at, f12
0023c2c4: ce c9 08 0c           jal 00232738
0023c2c8: 00 00 00 00           _nop 
0023c2cc: 5e ca 08 0c           jal 00232978
0023c2d0: 01 00 04 24           _li a0, 0x1
0023c2d4: 50 f3 a4 26           addiu a0, s5, -0xcb0
0023c2d8: 0e 03 82 84           lh v0, 0x30e ( a0 )
0023c2dc: 0b 00 40 10           beq v0, zero, 0023c30c
0023c2e0: 70 81 80 c7           _lwc1 f0, -0x7e90 ( gp )
0023c2e4: 20 01 85 24           addiu a1, a0, 0x120
0023c2e8: c8 41 01 3c           lui at, 0x41c8
0023c2ec: 00 60 81 44           mtc1 at, f12
0023c2f0: e0 00 84 24           addiu a0, a0, 0xe0
0023c2f4: da 22 09 0c           jal 00248b68
0023c2f8: 02 03 0c 46           _mul.S f12, f0, f12
0023c2fc: 08 ca 08 0c           jal 00232820
0023c300: 00 00 00 00           _nop 
0023c304: 3b 00 00 10           b 0023c3f4
0023c308: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023c30c: 16 00 01 3c           lui at, 0x16
0023c310: 70 ed 2c c4           lwc1 f12, -0x1290 ( at )
0023c314: e0 00 84 24           addiu a0, a0, 0xe0
0023c318: 58 42 01 3c           lui at, 0x4258
0023c31c: 00 00 81 44           mtc1 at, f0
0023c320: 24 00 00 10           b 0023c3b4
0023c324: 2d 28 80 00           _move a1, a0
0023c328: 14 00 10 3c           lui s0, 0x14
0023c32c: 30 f4 11 26           addiu s1, s0, -0xbd0
0023c330: c6 84 08 0c           jal 00221318
0023c334: 2d 20 20 02           _move a0, s1
0023c338: 2e 02 22 86           lh v0, 0x22e ( s1 )
0023c33c: 06 00 40 10           beq v0, zero, 0023c358
0023c340: 06 03 00 46           _mov.S f12, f0
0023c344: 23 bc 01 3c           lui at, 0xbc23
0023c348: 00 d7 21 34           ori at, at, 0xd700
0023c34c: 00 08 81 44           mtc1 at, f1
0023c350: 06 00 00 10           b 0023c36c
0023c354: 60 81 80 c7           _lwc1 f0, -0x7ea0 ( gp )
0023c358: 16 00 01 3c           lui at, 0x16
0023c35c: 60 ed 20 c4           lwc1 f0, -0x12a0 ( at )
0023c360: a3 bd 01 3c           lui at, 0xbda3
0023c364: 08 d7 21 34           ori at, at, 0xd708
0023c368: 00 08 81 44           mtc1 at, f1
0023c36c: 00 00 00 00           nop 
0023c370: 02 00 01 46           mul.S f0, f0, f1
0023c374: 02 00 0c 46           mul.S f0, f0, f12
0023c378: 00 03 0c 46           add.S f12, f0, f12
0023c37c: 30 f4 10 26           addiu s0, s0, -0xbd0
0023c380: 2d 20 00 02           move a0, s0
0023c384: 44 85 08 0c           jal 00221510
0023c388: 2d 28 00 02           _move a1, s0
0023c38c: 20 ff 03 26           addiu v1, s0, -0xe0
0023c390: 0e 03 62 84           lh v0, 0x30e ( v1 )
0023c394: 0b 00 40 10           beq v0, zero, 0023c3c4
0023c398: e8 00 60 ac           _sw zero, 0xe8 ( v1 )
0023c39c: 16 00 01 3c           lui at, 0x16
0023c3a0: 70 ed 20 c4           lwc1 f0, -0x1290 ( at )
0023c3a4: 2d 20 00 02           move a0, s0
0023c3a8: c0 41 01 3c           lui at, 0x41c0
0023c3ac: 00 60 81 44           mtc1 at, f12
0023c3b0: 30 00 85 24           addiu a1, a0, 0x30
0023c3b4: da 22 09 0c           jal 00248b68
0023c3b8: 02 03 0c 46           _mul.S f12, f0, f12
0023c3bc: 0d 00 00 10           b 0023c3f4
0023c3c0: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023c3c4: 2d 20 00 02           move a0, s0
0023c3c8: 83 3b 01 3c           lui at, 0x3b83
0023c3cc: 6f 12 21 34           ori at, at, 0x126f
0023c3d0: 00 60 81 44           mtc1 at, f12
0023c3d4: da 22 09 0c           jal 00248b68
0023c3d8: 2d 28 80 00           _move a1, a0
0023c3dc: 05 00 00 10           b 0023c3f4
0023c3e0: 50 f3 a3 26           _addiu v1, s5, -0xcb0
0023c3e4: 14 00 04 3c           lui a0, 0x14
0023c3e8: 5c 84 08 0c           jal 00221170
0023c3ec: 30 f4 84 24           _addiu a0, a0, -0xbd0
0023c3f0: 50 f3 a3 26           addiu v1, s5, -0xcb0
0023c3f4: 74 00 a4 8f           lw a0, 0x74 ( sp )
0023c3f8: 88 20 62 8c           lw v0, 0x2088 ( v1 )
0023c3fc: 01 00 82 54           bnel a0, v0, 0023c404
0023c400: a0 01 60 ac           _sw zero, 0x1a0 ( v1 )
0023c404: 53 00 c2 93           lbu v0, 0x53 ( s8 )
0023c408: 78 00 a4 8f           lw a0, 0x78 ( sp )
0023c40c: 01 00 82 54           bnel a0, v0, 0023c414
0023c410: a4 01 60 ac           _sw zero, 0x1a4 ( v1 )
0023c414: 10 01 bf 7b           lq ra, 0x110 ( sp )
0023c418: 00 01 be 7b           lq s8, 0x100 ( sp )
0023c41c: f0 00 b7 7b           lq s7, 0xf0 ( sp )
0023c420: e0 00 b6 7b           lq s6, 0xe0 ( sp )
0023c424: d0 00 b5 7b           lq s5, 0xd0 ( sp )
0023c428: c0 00 b4 7b           lq s4, 0xc0 ( sp )
0023c42c: b0 00 b3 7b           lq s3, 0xb0 ( sp )
0023c430: a0 00 b2 7b           lq s2, 0xa0 ( sp )
0023c434: 90 00 b1 7b           lq s1, 0x90 ( sp )
0023c438: 80 00 b0 7b           lq s0, 0x80 ( sp )
0023c43c: 38 01 b7 c7           lwc1 f23, 0x138 ( sp )
0023c440: 30 01 b6 c7           lwc1 f22, 0x130 ( sp )
0023c444: 28 01 b5 c7           lwc1 f21, 0x128 ( sp )
0023c448: 20 01 b4 c7           lwc1 f20, 0x120 ( sp )
0023c44c: 08 00 e0 03           jr ra
0023c450: 40 01 bd 27           _addiu sp, sp, 0x140