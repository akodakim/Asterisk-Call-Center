/*
 * Copyright (C) 2004-2005 by Objective Systems, Inc.
 *
 * This software is furnished under an open source license and may be 
 * used and copied only in accordance with the terms of this license. 
 * The text of the license may generally be found in the root 
 * directory of this installation in the COPYING file.  It 
 * can also be viewed online at the following URL:
 *
 *   http://www.obj-sys.com/open/license.html
 *
 * Any redistributions of this file including modified versions must 
 * maintain this copyright notice.
 *
 *****************************************************************************/
/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 5.72, Date: 22-Mar-2005.
 */
#include "ooasn1.h"
#include "H235-SECURITY-MESSAGES.h"

/**************************************************************/
/*                                                            */
/*  ChallengeString                                           */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ChallengeString (OOCTXT* pctxt, H235ChallengeString* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 8, 128, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeOctetString (pctxt, pvalue->numocts, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  TimeStamp                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235TimeStamp (OOCTXT* pctxt, H235TimeStamp value)
{
   int stat = ASN_OK;

   stat = encodeConsUnsigned (pctxt, value, 1U, ASN1UINT_MAX);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  RandomVal                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235RandomVal (OOCTXT* pctxt, H235RandomVal value)
{
   int stat = ASN_OK;

   stat = encodeUnconsInteger (pctxt, value);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Password                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235Password (OOCTXT* pctxt, H235Password value)
{
   static Asn1SizeCnst lsize1 = { 0, 1, 128, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeBMPString (pctxt, value, 0);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  EncodedPwdCertToken                                       */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235EncodedPwdCertToken (OOCTXT* pctxt, H235EncodedPwdCertToken value)
{
   int stat = ASN_OK;

   stat = encodeOpenType (pctxt, value.numocts, value.data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  NonStandardParameter                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235NonStandardParameter (OOCTXT* pctxt, H235NonStandardParameter* pvalue)
{
   int stat = ASN_OK;

   /* encode nonStandardIdentifier */

   stat = encodeObjectIdentifier (pctxt, &pvalue->nonStandardIdentifier);
   if (stat != ASN_OK) return stat;

   /* encode data */

   stat = encodeOctetString (pctxt, pvalue->data.numocts, pvalue->data.data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  AuthenticationBES                                         */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235AuthenticationBES (OOCTXT* pctxt, H235AuthenticationBES* pvalue)
{
   int stat = ASN_OK;
   ASN1BOOL extbit;

   /* extension bit */

   extbit = (ASN1BOOL)(pvalue->t > 2);

   encodeBit (pctxt, extbit);

   if (!extbit) {

      /* Encode choice index value */

      stat = encodeConsUnsigned (pctxt, pvalue->t - 1, 0, 1);
      if (stat != ASN_OK) return stat;

      /* Encode root element data value */

      switch (pvalue->t)
      {
         /* default_ */
         case 1:
            /* NULL */
            break;

         /* radius */
         case 2:
            /* NULL */
            break;

         default:
            return ASN_E_INVOPT;
      }
   }
   else {
      /* Encode extension choice index value */

      stat = encodeSmallNonNegWholeNumber (pctxt, pvalue->t - 3);
      if (stat != ASN_OK) return stat;

      /* Encode extension element data value */

   }

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  AuthenticationMechanism                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235AuthenticationMechanism (OOCTXT* pctxt, H235AuthenticationMechanism* pvalue)
{
   int stat = ASN_OK;
   OOCTXT lctxt;
   ASN1OpenType openType;
   ASN1BOOL extbit;

   /* extension bit */

   extbit = (ASN1BOOL)(pvalue->t > 7);

   encodeBit (pctxt, extbit);

   if (!extbit) {

      /* Encode choice index value */

      stat = encodeConsUnsigned (pctxt, pvalue->t - 1, 0, 6);
      if (stat != ASN_OK) return stat;

      /* Encode root element data value */

      switch (pvalue->t)
      {
         /* dhExch */
         case 1:
            /* NULL */
            break;

         /* pwdSymEnc */
         case 2:
            /* NULL */
            break;

         /* pwdHash */
         case 3:
            /* NULL */
            break;

         /* certSign */
         case 4:
            /* NULL */
            break;

         /* ipsec */
         case 5:
            /* NULL */
            break;

         /* tls */
         case 6:
            /* NULL */
            break;

         /* nonStandard */
         case 7:
            stat = asn1PE_H235NonStandardParameter (pctxt, pvalue->u.nonStandard);
            if (stat != ASN_OK) return stat;
            break;

         default:
            return ASN_E_INVOPT;
      }
   }
   else {
      /* Encode extension choice index value */

      stat = encodeSmallNonNegWholeNumber (pctxt, pvalue->t - 8);
      if (stat != ASN_OK) return stat;

      /* Encode extension element data value */

      initContext (&lctxt);
      stat = setPERBuffer (&lctxt, 0, 0, TRUE);
      if (stat != ASN_OK) return freeContext (&lctxt), stat;

      switch (pvalue->t)
      {
         /* authenticationBES */
         case 8:
            stat = asn1PE_H235AuthenticationBES (&lctxt, pvalue->u.authenticationBES);
            if (stat != ASN_OK) return freeContext (&lctxt), stat;
            openType.data = encodeGetMsgPtr (&lctxt, (int*)&openType.numocts);
            break;

         default:
            ;
      }

      stat = encodeByteAlign (pctxt);
      if (stat != ASN_OK) return freeContext (&lctxt), stat;

      stat = encodeOpenType (pctxt, openType.numocts, openType.data);
      if (stat != ASN_OK) return freeContext (&lctxt), stat;

      freeContext (&lctxt);
   }

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  DHset_halfkey                                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235DHset_halfkey (OOCTXT* pctxt, H235DHset_halfkey* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 0, 2048, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeBitString (pctxt, pvalue->numbits, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  DHset_modSize                                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235DHset_modSize (OOCTXT* pctxt, H235DHset_modSize* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 0, 2048, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeBitString (pctxt, pvalue->numbits, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  DHset_generator                                           */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235DHset_generator (OOCTXT* pctxt, H235DHset_generator* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 0, 2048, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeBitString (pctxt, pvalue->numbits, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  DHset                                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235DHset (OOCTXT* pctxt, H235DHset* pvalue)
{
   int stat = ASN_OK;
   ASN1BOOL extbit;

   /* extension bit */

   extbit = 0;

   encodeBit (pctxt, extbit);

   /* encode halfkey */

   stat = asn1PE_H235DHset_halfkey (pctxt, &pvalue->halfkey);
   if (stat != ASN_OK) return stat;

   /* encode modSize */

   stat = asn1PE_H235DHset_modSize (pctxt, &pvalue->modSize);
   if (stat != ASN_OK) return stat;

   /* encode generator */

   stat = asn1PE_H235DHset_generator (pctxt, &pvalue->generator);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  TypedCertificate                                          */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235TypedCertificate (OOCTXT* pctxt, H235TypedCertificate* pvalue)
{
   int stat = ASN_OK;
   ASN1BOOL extbit;

   /* extension bit */

   extbit = 0;

   encodeBit (pctxt, extbit);

   /* encode type */

   stat = encodeObjectIdentifier (pctxt, &pvalue->type);
   if (stat != ASN_OK) return stat;

   /* encode certificate */

   stat = encodeOctetString (pctxt, pvalue->certificate.numocts, pvalue->certificate.data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Identifier                                                */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235Identifier (OOCTXT* pctxt, H235Identifier value)
{
   static Asn1SizeCnst lsize1 = { 0, 1, 128, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeBMPString (pctxt, value, 0);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ECpoint_x                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ECpoint_x (OOCTXT* pctxt, H235ECpoint_x* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 0, 511, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeBitString (pctxt, pvalue->numbits, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ECpoint_y                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ECpoint_y (OOCTXT* pctxt, H235ECpoint_y* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 0, 511, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeBitString (pctxt, pvalue->numbits, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ECpoint                                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ECpoint (OOCTXT* pctxt, H235ECpoint* pvalue)
{
   int stat = ASN_OK;
   ASN1BOOL extbit;

   /* extension bit */

   extbit = 0;

   encodeBit (pctxt, extbit);

   encodeBit (pctxt, (ASN1BOOL)pvalue->m.xPresent);

   encodeBit (pctxt, (ASN1BOOL)pvalue->m.yPresent);

   /* encode x */

   if (pvalue->m.xPresent) {
      stat = asn1PE_H235ECpoint_x (pctxt, &pvalue->x);
      if (stat != ASN_OK) return stat;
   }

   /* encode y */

   if (pvalue->m.yPresent) {
      stat = asn1PE_H235ECpoint_y (pctxt, &pvalue->y);
      if (stat != ASN_OK) return stat;
   }

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ECKASDH_eckasdhp_modulus                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ECKASDH_eckasdhp_modulus (OOCTXT* pctxt, H235ECKASDH_eckasdhp_modulus* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 0, 511, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeBitString (pctxt, pvalue->numbits, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ECKASDH_eckasdhp_weierstrassA                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ECKASDH_eckasdhp_weierstrassA (OOCTXT* pctxt, H235ECKASDH_eckasdhp_weierstrassA* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 0, 511, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeBitString (pctxt, pvalue->numbits, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ECKASDH_eckasdhp_weierstrassB                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ECKASDH_eckasdhp_weierstrassB (OOCTXT* pctxt, H235ECKASDH_eckasdhp_weierstrassB* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 0, 511, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeBitString (pctxt, pvalue->numbits, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ECKASDH_eckasdhp                                          */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ECKASDH_eckasdhp (OOCTXT* pctxt, H235ECKASDH_eckasdhp* pvalue)
{
   int stat = ASN_OK;

   /* encode public_key */

   stat = asn1PE_H235ECpoint (pctxt, &pvalue->public_key);
   if (stat != ASN_OK) return stat;

   /* encode modulus */

   stat = asn1PE_H235ECKASDH_eckasdhp_modulus (pctxt, &pvalue->modulus);
   if (stat != ASN_OK) return stat;

   /* encode base */

   stat = asn1PE_H235ECpoint (pctxt, &pvalue->base);
   if (stat != ASN_OK) return stat;

   /* encode weierstrassA */

   stat = asn1PE_H235ECKASDH_eckasdhp_weierstrassA (pctxt, &pvalue->weierstrassA);
   if (stat != ASN_OK) return stat;

   /* encode weierstrassB */

   stat = asn1PE_H235ECKASDH_eckasdhp_weierstrassB (pctxt, &pvalue->weierstrassB);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ECKASDH_eckasdh2_fieldSize                                */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ECKASDH_eckasdh2_fieldSize (OOCTXT* pctxt, H235ECKASDH_eckasdh2_fieldSize* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 0, 511, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeBitString (pctxt, pvalue->numbits, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ECKASDH_eckasdh2_weierstrassA                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ECKASDH_eckasdh2_weierstrassA (OOCTXT* pctxt, H235ECKASDH_eckasdh2_weierstrassA* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 0, 511, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeBitString (pctxt, pvalue->numbits, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ECKASDH_eckasdh2_weierstrassB                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ECKASDH_eckasdh2_weierstrassB (OOCTXT* pctxt, H235ECKASDH_eckasdh2_weierstrassB* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 0, 511, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeBitString (pctxt, pvalue->numbits, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ECKASDH_eckasdh2                                          */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ECKASDH_eckasdh2 (OOCTXT* pctxt, H235ECKASDH_eckasdh2* pvalue)
{
   int stat = ASN_OK;

   /* encode public_key */

   stat = asn1PE_H235ECpoint (pctxt, &pvalue->public_key);
   if (stat != ASN_OK) return stat;

   /* encode fieldSize */

   stat = asn1PE_H235ECKASDH_eckasdh2_fieldSize (pctxt, &pvalue->fieldSize);
   if (stat != ASN_OK) return stat;

   /* encode base */

   stat = asn1PE_H235ECpoint (pctxt, &pvalue->base);
   if (stat != ASN_OK) return stat;

   /* encode weierstrassA */

   stat = asn1PE_H235ECKASDH_eckasdh2_weierstrassA (pctxt, &pvalue->weierstrassA);
   if (stat != ASN_OK) return stat;

   /* encode weierstrassB */

   stat = asn1PE_H235ECKASDH_eckasdh2_weierstrassB (pctxt, &pvalue->weierstrassB);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ECKASDH                                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ECKASDH (OOCTXT* pctxt, H235ECKASDH* pvalue)
{
   int stat = ASN_OK;
   ASN1BOOL extbit;

   /* extension bit */

   extbit = (ASN1BOOL)(pvalue->t > 2);

   encodeBit (pctxt, extbit);

   if (!extbit) {

      /* Encode choice index value */

      stat = encodeConsUnsigned (pctxt, pvalue->t - 1, 0, 1);
      if (stat != ASN_OK) return stat;

      /* Encode root element data value */

      switch (pvalue->t)
      {
         /* eckasdhp */
         case 1:
            stat = asn1PE_H235ECKASDH_eckasdhp (pctxt, pvalue->u.eckasdhp);
            if (stat != ASN_OK) return stat;
            break;

         /* eckasdh2 */
         case 2:
            stat = asn1PE_H235ECKASDH_eckasdh2 (pctxt, pvalue->u.eckasdh2);
            if (stat != ASN_OK) return stat;
            break;

         default:
            return ASN_E_INVOPT;
      }
   }
   else {
      /* Encode extension choice index value */

      stat = encodeSmallNonNegWholeNumber (pctxt, pvalue->t - 3);
      if (stat != ASN_OK) return stat;

      /* Encode extension element data value */

   }

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ClearToken                                                */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ClearToken (OOCTXT* pctxt, H235ClearToken* pvalue)
{
   int stat = ASN_OK;
   ASN1BOOL extbit;
   ASN1OpenType openType;
   OOCTXT lctxt;

   /* extension bit */

   extbit = (ASN1BOOL)(pvalue->m.eckasdhkeyPresent ||
   pvalue->m.sendersIDPresent);

   encodeBit (pctxt, extbit);

   encodeBit (pctxt, (ASN1BOOL)pvalue->m.timeStampPresent);

   encodeBit (pctxt, (ASN1BOOL)pvalue->m.passwordPresent);

   encodeBit (pctxt, (ASN1BOOL)pvalue->m.dhkeyPresent);

   encodeBit (pctxt, (ASN1BOOL)pvalue->m.challengePresent);

   encodeBit (pctxt, (ASN1BOOL)pvalue->m.randomPresent);

   encodeBit (pctxt, (ASN1BOOL)pvalue->m.certificatePresent);

   encodeBit (pctxt, (ASN1BOOL)pvalue->m.generalIDPresent);

   encodeBit (pctxt, (ASN1BOOL)pvalue->m.nonStandardPresent);

   /* encode tokenOID */

   stat = encodeObjectIdentifier (pctxt, &pvalue->tokenOID);
   if (stat != ASN_OK) return stat;

   /* encode timeStamp */

   if (pvalue->m.timeStampPresent) {
      stat = asn1PE_H235TimeStamp (pctxt, pvalue->timeStamp);
      if (stat != ASN_OK) return stat;
   }

   /* encode password */

   if (pvalue->m.passwordPresent) {
      stat = asn1PE_H235Password (pctxt, pvalue->password);
      if (stat != ASN_OK) return stat;
   }

   /* encode dhkey */

   if (pvalue->m.dhkeyPresent) {
      stat = asn1PE_H235DHset (pctxt, &pvalue->dhkey);
      if (stat != ASN_OK) return stat;
   }

   /* encode challenge */

   if (pvalue->m.challengePresent) {
      stat = asn1PE_H235ChallengeString (pctxt, &pvalue->challenge);
      if (stat != ASN_OK) return stat;
   }

   /* encode random */

   if (pvalue->m.randomPresent) {
      stat = asn1PE_H235RandomVal (pctxt, pvalue->random);
      if (stat != ASN_OK) return stat;
   }

   /* encode certificate */

   if (pvalue->m.certificatePresent) {
      stat = asn1PE_H235TypedCertificate (pctxt, &pvalue->certificate);
      if (stat != ASN_OK) return stat;
   }

   /* encode generalID */

   if (pvalue->m.generalIDPresent) {
      stat = asn1PE_H235Identifier (pctxt, pvalue->generalID);
      if (stat != ASN_OK) return stat;
   }

   /* encode nonStandard */

   if (pvalue->m.nonStandardPresent) {
      stat = asn1PE_H235NonStandardParameter (pctxt, &pvalue->nonStandard);
      if (stat != ASN_OK) return stat;
   }

   if (extbit) {

      /* encode extension optional bits length */

      stat = encodeSmallNonNegWholeNumber (pctxt, 1);
      if (stat != ASN_OK) return stat;

      /* encode optional bits */

      encodeBit (pctxt, (ASN1BOOL)pvalue->m.eckasdhkeyPresent);
      encodeBit (pctxt, (ASN1BOOL)pvalue->m.sendersIDPresent);
      /* encode extension elements */

      if (pvalue->m.eckasdhkeyPresent) {
         initContext (&lctxt);
         stat = setPERBuffer (&lctxt, 0, 0, TRUE);
         if (stat != ASN_OK) return freeContext (&lctxt), stat;

         stat = asn1PE_H235ECKASDH (&lctxt, &pvalue->eckasdhkey);
         if (stat != ASN_OK) return freeContext (&lctxt), stat;

         stat = encodeByteAlign (&lctxt);
         if (stat != ASN_OK) return freeContext (&lctxt), stat;

         openType.data = encodeGetMsgPtr (&lctxt, (int*)&openType.numocts);

         stat = encodeOpenType (pctxt, openType.numocts, openType.data);
         if (stat != ASN_OK) return freeContext (&lctxt), stat;

         freeContext (&lctxt);
      }

      if (pvalue->m.sendersIDPresent) {
         initContext (&lctxt);
         stat = setPERBuffer (&lctxt, 0, 0, TRUE);
         if (stat != ASN_OK) return freeContext (&lctxt), stat;

         stat = asn1PE_H235Identifier (&lctxt, pvalue->sendersID);
         if (stat != ASN_OK) return freeContext (&lctxt), stat;

         stat = encodeByteAlign (&lctxt);
         if (stat != ASN_OK) return freeContext (&lctxt), stat;

         openType.data = encodeGetMsgPtr (&lctxt, (int*)&openType.numocts);

         stat = encodeOpenType (pctxt, openType.numocts, openType.data);
         if (stat != ASN_OK) return freeContext (&lctxt), stat;

         freeContext (&lctxt);
      }

   }

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  IV8                                                       */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235IV8 (OOCTXT* pctxt, H235IV8* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 8, 8, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeOctetString (pctxt, pvalue->numocts, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  IV16                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235IV16 (OOCTXT* pctxt, H235IV16* pvalue)
{
   static Asn1SizeCnst lsize1 = { 0, 16, 16, 0 };
   int stat = ASN_OK;

   addSizeConstraint (pctxt, &lsize1);

   stat = encodeOctetString (pctxt, pvalue->numocts, pvalue->data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Params                                                    */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235Params (OOCTXT* pctxt, H235Params* pvalue)
{
   int stat = ASN_OK;
   ASN1BOOL extbit;
   ASN1OpenType openType;
   OOCTXT lctxt;

   /* extension bit */

   extbit = (ASN1BOOL)(pvalue->m.iv16Present);

   encodeBit (pctxt, extbit);

   encodeBit (pctxt, (ASN1BOOL)pvalue->m.ranIntPresent);

   encodeBit (pctxt, (ASN1BOOL)pvalue->m.iv8Present);

   /* encode ranInt */

   if (pvalue->m.ranIntPresent) {
      stat = encodeUnconsInteger (pctxt, pvalue->ranInt);
      if (stat != ASN_OK) return stat;
   }

   /* encode iv8 */

   if (pvalue->m.iv8Present) {
      stat = asn1PE_H235IV8 (pctxt, &pvalue->iv8);
      if (stat != ASN_OK) return stat;
   }

   if (extbit) {

      /* encode extension optional bits length */

      stat = encodeSmallNonNegWholeNumber (pctxt, 0);
      if (stat != ASN_OK) return stat;

      /* encode optional bits */

      encodeBit (pctxt, (ASN1BOOL)pvalue->m.iv16Present);
      /* encode extension elements */

      if (pvalue->m.iv16Present) {
         initContext (&lctxt);
         stat = setPERBuffer (&lctxt, 0, 0, TRUE);
         if (stat != ASN_OK) return freeContext (&lctxt), stat;

         stat = asn1PE_H235IV16 (&lctxt, &pvalue->iv16);
         if (stat != ASN_OK) return freeContext (&lctxt), stat;

         stat = encodeByteAlign (&lctxt);
         if (stat != ASN_OK) return freeContext (&lctxt), stat;

         openType.data = encodeGetMsgPtr (&lctxt, (int*)&openType.numocts);

         stat = encodeOpenType (pctxt, openType.numocts, openType.data);
         if (stat != ASN_OK) return freeContext (&lctxt), stat;

         freeContext (&lctxt);
      }

   }

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ENCRYPTED                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235ENCRYPTED (OOCTXT* pctxt, H235ENCRYPTED* pvalue)
{
   int stat = ASN_OK;

   /* encode algorithmOID */

   stat = encodeObjectIdentifier (pctxt, &pvalue->algorithmOID);
   if (stat != ASN_OK) return stat;

   /* encode paramS */

   stat = asn1PE_H235Params (pctxt, &pvalue->paramS);
   if (stat != ASN_OK) return stat;

   /* encode encryptedData */

   stat = encodeOctetString (pctxt, pvalue->encryptedData.numocts, pvalue->encryptedData.data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  CryptoToken_cryptoEncryptedToken                          */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235CryptoToken_cryptoEncryptedToken (OOCTXT* pctxt, H235CryptoToken_cryptoEncryptedToken* pvalue)
{
   int stat = ASN_OK;

   /* encode tokenOID */

   stat = encodeObjectIdentifier (pctxt, &pvalue->tokenOID);
   if (stat != ASN_OK) return stat;

   /* encode token */

   stat = asn1PE_H235ENCRYPTED (pctxt, &pvalue->token);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  EncodedGeneralToken                                       */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235EncodedGeneralToken (OOCTXT* pctxt, H235EncodedGeneralToken value)
{
   int stat = ASN_OK;

   stat = encodeOpenType (pctxt, value.numocts, value.data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  CryptoToken_cryptoSignedToken_token                       */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235CryptoToken_cryptoSignedToken_token (OOCTXT* pctxt, H235CryptoToken_cryptoSignedToken_token* pvalue)
{
   int stat = ASN_OK;

   /* encode toBeSigned */

   stat = asn1PE_H235EncodedGeneralToken (pctxt, pvalue->toBeSigned);
   if (stat != ASN_OK) return stat;

   /* encode algorithmOID */

   stat = encodeObjectIdentifier (pctxt, &pvalue->algorithmOID);
   if (stat != ASN_OK) return stat;

   /* encode paramS */

   stat = asn1PE_H235Params (pctxt, &pvalue->paramS);
   if (stat != ASN_OK) return stat;

   /* encode signature */

   stat = encodeBitString (pctxt, pvalue->signature.numbits, pvalue->signature.data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  CryptoToken_cryptoSignedToken                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235CryptoToken_cryptoSignedToken (OOCTXT* pctxt, H235CryptoToken_cryptoSignedToken* pvalue)
{
   int stat = ASN_OK;

   /* encode tokenOID */

   stat = encodeObjectIdentifier (pctxt, &pvalue->tokenOID);
   if (stat != ASN_OK) return stat;

   /* encode token */

   stat = asn1PE_H235CryptoToken_cryptoSignedToken_token (pctxt, &pvalue->token);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  HASHED                                                    */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235HASHED (OOCTXT* pctxt, H235HASHED* pvalue)
{
   int stat = ASN_OK;

   /* encode algorithmOID */

   stat = encodeObjectIdentifier (pctxt, &pvalue->algorithmOID);
   if (stat != ASN_OK) return stat;

   /* encode paramS */

   stat = asn1PE_H235Params (pctxt, &pvalue->paramS);
   if (stat != ASN_OK) return stat;

   /* encode hash */

   stat = encodeBitString (pctxt, pvalue->hash.numbits, pvalue->hash.data);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  CryptoToken_cryptoHashedToken                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235CryptoToken_cryptoHashedToken (OOCTXT* pctxt, H235CryptoToken_cryptoHashedToken* pvalue)
{
   int stat = ASN_OK;

   /* encode tokenOID */

   stat = encodeObjectIdentifier (pctxt, &pvalue->tokenOID);
   if (stat != ASN_OK) return stat;

   /* encode hashedVals */

   stat = asn1PE_H235ClearToken (pctxt, &pvalue->hashedVals);
   if (stat != ASN_OK) return stat;

   /* encode token */

   stat = asn1PE_H235HASHED (pctxt, &pvalue->token);
   if (stat != ASN_OK) return stat;

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  CryptoToken                                               */
/*                                                            */
/**************************************************************/

EXTERN int asn1PE_H235CryptoToken (OOCTXT* pctxt, H235CryptoToken* pvalue)
{
   int stat = ASN_OK;
   ASN1BOOL extbit;

   /* extension bit */

   extbit = (ASN1BOOL)(pvalue->t > 4);

   encodeBit (pctxt, extbit);

   if (!extbit) {

      /* Encode choice index value */

      stat = encodeConsUnsigned (pctxt, pvalue->t - 1, 0, 3);
      if (stat != ASN_OK) return stat;

      /* Encode root element data value */

      switch (pvalue->t)
      {
         /* cryptoEncryptedToken */
         case 1:
            stat = asn1PE_H235CryptoToken_cryptoEncryptedToken (pctxt, pvalue->u.cryptoEncryptedToken);
            if (stat != ASN_OK) return stat;
            break;

         /* cryptoSignedToken */
         case 2:
            stat = asn1PE_H235CryptoToken_cryptoSignedToken (pctxt, pvalue->u.cryptoSignedToken);
            if (stat != ASN_OK) return stat;
            break;

         /* cryptoHashedToken */
         case 3:
            stat = asn1PE_H235CryptoToken_cryptoHashedToken (pctxt, pvalue->u.cryptoHashedToken);
            if (stat != ASN_OK) return stat;
            break;

         /* cryptoPwdEncr */
         case 4:
            stat = asn1PE_H235ENCRYPTED (pctxt, pvalue->u.cryptoPwdEncr);
            if (stat != ASN_OK) return stat;
            break;

         default:
            return ASN_E_INVOPT;
      }
   }
   else {
      /* Encode extension choice index value */

      stat = encodeSmallNonNegWholeNumber (pctxt, pvalue->t - 5);
      if (stat != ASN_OK) return stat;

      /* Encode extension element data value */

   }

   return (stat);
}

