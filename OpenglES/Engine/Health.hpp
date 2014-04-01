
#pragma once

namespace Core {
    class Health
    {
        float m_Health;
    public:
        Health(float health);
        void ApplyDamage(float damage);
        void AppleHealth(float health);
        bool IsDead()const;
        ~Health(){};
        
    };
}