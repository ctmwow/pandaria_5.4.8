/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

enum FreezingPipeType
{
    NPC_FREEZING_PIPE_BUNNY_1 = 47423,
    NPC_FREEZING_PIPE_BUNNY_2 = 47424,
    NPC_FREEZING_PIPE_BUNNY_3 = 47425,
    NPC_FREEZING_PIPE_BUNNY_4 = 47426,
};

// I-Scream Cryocannon 88452
class spell_thousand_needles_i_scream_cryocannon : public SpellScript
{
    PrepareSpellScript(spell_thousand_needles_i_scream_cryocannon);

    void HandleEffectHit(SpellEffIndex /*effIndex*/)
    {
        if (Player* caster = GetCaster()->ToPlayer())
            if (Creature* credit = GetHitCreature())
                caster->KilledMonsterCredit(credit->GetEntry());
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([=](WorldObject* target) { return target->GetEntry() != NPC_FREEZING_PIPE_BUNNY_1 && target->GetEntry() != NPC_FREEZING_PIPE_BUNNY_2 && target->GetEntry() != NPC_FREEZING_PIPE_BUNNY_3 && target->GetEntry() != NPC_FREEZING_PIPE_BUNNY_4; });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_thousand_needles_i_scream_cryocannon::HandleEffectHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_thousand_needles_i_scream_cryocannon::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
    }
};

void AddSC_thousand_needles()
{
    register_spell_script(spell_thousand_needles_i_scream_cryocannon);
}
