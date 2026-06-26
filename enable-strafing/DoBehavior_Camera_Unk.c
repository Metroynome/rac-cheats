
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

