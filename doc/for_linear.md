
$\frac{\partial f}{\partial t}+\vec{v} \cdot \frac{\partial f}{\partial \vec{x}} = 0$

$\vec{v} = c\frac{\vec{D}}{B_\parallel^\ast} \times \vec{b}$

$\vec{D} = \vec{E}-\frac{\mu}{q}\nabla B - \frac{m}{q}(\frac{\partial \vec{v_E}}{\partial t}+\nabla \frac{v_E^2}{2})$

$\vec{v_E} =\frac{c\vec{E}}{B} \times \vec{b}$

$\vec{B^\ast} = \vec{B} + \frac{mc}{q}(\nabla\times\vec{v_E})$

$B^\ast_\parallel = \vec{B^\ast} \cdot \vec{b}$

$B = |\vec{B}|$

---


$\vec{E} = \vec{E_{1r}}$

$\vec{B} =\vec{B_{0z}} + \vec{B_{1\theta}}$

---

$\frac{1}{B} = \frac{1}{\sqrt{B_{0z}^2 + 2B_{1\theta}B_0 + B_{1\theta}^2}}\approx \frac{1}{\sqrt{B_{0z}^2 + 2B_{1\theta}B_0}}= ({B_{0z}^2 + 2B_{1\theta}B_{0z}})^{-\frac{1}{2}} = \frac{1}{B_{0z}}({1+2\frac{B_{1\theta}}{B_{0z}}})^{-\frac{1}{2}} \approx \frac{1}{B_{0z}}({1-\frac{1}{2}\frac{B_{1\theta}}{B_{0z}}})$

---

$\vec{b} = \frac{\vec{B}}{B} = \vec{B}\frac{1}{B} = (\vec{B_{0z}}+\vec{B_{1\theta}})\frac{1}{B_{0z}}({1-\frac{1}{2}\frac{B_{1\theta}}{B_{0z}}})$
$ = \frac{1}{B_{0z}}({\vec{B_{0z}} + \vec{B_{1\theta}}}-\frac{1}{2}\frac{B_{1\theta}}{B_{0z}}\vec{B_{0z}} -\frac{1}{2}\frac{B_{1\theta}}{B_{0z}}\vec{B_{1\theta}}) $

$  = \frac{1}{B_{0z}}({\vec{B_{0z}} + \vec{B_{1\theta}}}-\frac{1}{2}B_{1\theta}\hat{e}_z -\frac{1}{2}\frac{B_{1\theta}}{B_{0z}}\vec{B_{1\theta}}) \approx  \frac{1}{B_{0z}}(\vec{B_{0z}}+\vec{B_{1\theta}}-\frac{1}{2}B_{1\theta}\hat{e}_z)$

$ = \vec{b_{0z}} + \vec{b_{1\theta}} + \vec{b_{1z}}$
$(\vec{b_{1z}} = -\frac{1}{B_{0z}}\frac{1}{2}B_{1\theta}\hat{e}_z)$

$|b_{0z}| = 1$

---

$\vec{v_E} =\frac{c\vec{E}}{B} \times \vec{b}$

$ = \frac{c}{B_{0z}}({1-\frac{1}{2}\frac{B_{1\theta}}{B_{0z}}})\vec{E_{1r}} \times \vec{b}$

$\vec{E_{1r}} \times \vec{b} = \vec{E_{1r}} \times (\vec{b_{0z}} + \vec{b_{1\theta}} + \vec{b_{1z}})$


$\approx -E_1b_{0z}\hat{e_\theta}$

$\vec{v_E}  = \frac{c}{B_{0z}}({1-\frac{1}{2}\frac{B_{1\theta}}{B_{0z}}})(-E_1b_{0z}\hat{e_\theta})$

$ \approx \frac{c}{B_{0z}}(-E_1b_{0z}\hat{e_\theta})$

$= E_1b_{1\theta}\hat{e_z}-E_1(b_{0z}+b_{1\theta})\hat{e_\theta}$

so,  $\vec{v_E}$ is not affected by $B_{1\theta}$ to the first order.

---

$\vec{B^\ast} = \vec{B} + \frac{mc}{q}(\nabla\times\vec{v_E})$

$\vec{B^\ast}$ is not affected by $B_{1\theta}$ to the first order.

---

$B^\ast_\parallel = \vec{B^\ast} \cdot \vec{b}$

$= (\vec{B_{0z}} + \vec{B_{1\theta}} + \frac{mc}{q}(\nabla\times\vec{v_E})) \cdot  (\vec{b_{0z}} + \vec{b_{1\theta}} + \vec{b_{1z}})$

$= (B_{0z}+ \frac{mc}{q}(\nabla\times\vec{v_E}))   (b_{0z}+b_{1z}) $

$ + (B_{1\theta} + \frac{mc}{q}(\nabla\times\vec{v_E})) (b_{1\theta})$

$v_E$ is a first-order term,


$= (B_{0z}+ \frac{mc}{q}(\nabla\times\vec{v_E}))b_{0z}+b_{1z}B_{0z}$

$= B_{0z}((1+ \frac{1}{B_{0z}}\frac{mc}{q}(\nabla\times\vec{v_E}))b_{0z}+b_{1z})$

$B^\ast_\parallel = B_{0z} (b_{0z}+b^\ast_{1\nabla\times v_E} + b_{1z})$

---



$\vec{D} = \vec{E}-\frac{\mu}{q}\nabla B - \frac{m}{q}(\frac{\partial \vec{v_E}}{\partial t}+\nabla \frac{v_E^2}{2})$

in terms of $\vec{v_E}$,$B_{1\theta}$ is not affected in terms up to the first order.

$\nabla B$
$= \nabla (B_{0z}^2+B_{1\theta}^2)^\frac{1}{2}$

$= \nabla (B_{0z}(1+\frac{B_{1\theta}}{B_{0z}}^2)^\frac{1}{2})$

$\approx \nabla (B_{0z})$

$ = \frac{\partial B_{0z}}{\partial r}\hat{e_r}$

 The $\vec{D}$ is not affected by $B_{1\theta}$ to the first order.

---

in, 
$\vec{v} = c\frac{\vec{D}}{B_\parallel^\ast} \times \vec{b}$

$\frac{1}{B_\parallel^\ast}$

$ = (B_{0z} (b_{0z}+b^\ast_{1\nabla\times v_E} + b_{1z}))^{-1}$

$ = \frac{1}{B_{0z}b_{0z}}(1 + \frac{b^\ast_{1\nabla\times v_E}}{b_{0z}} + \frac{b_{1z}}{b_{0z}})^{-1}$

$\approx \frac{1}{B_{0z}b_{0z}}(1 - \frac{b^\ast_{1\nabla\times v_E}}{b_{0z}} - \frac{b_{1z}}{b_{0z}})$

$\frac{1}{B_\parallel^\ast}\vec{b}$

$ = \frac{1}{B_0b_{0z}}(1 - \frac{b^\ast_{1\nabla\times v_E}}{b_{0z}} - \frac{b_{1z}}{b_{0z}})(\vec{b_{0z}} + \vec{b_{1\theta}} + \vec{b_{1z}})$

$ \approx \frac{1}{B_{0z}b_{0z}}(\vec{b_0z} - \hat{e_z}b^\ast_{1\nabla\times v_E} - \hat{e_z}b_{1z} + \vec{b_{1\theta}} + \vec{b_{1z}})$

$ = \frac{1}{B_{0z}b_{0z}}(\vec{b_0z} - \hat{e_z}b^\ast_{1\nabla\times v_E} + \vec{b_{1\theta}} )$

$ = \frac{1}{B_{0z}}(\vec{b_0z} - \hat{e_z}b^\ast_{1\nabla\times v_E} + \vec{b_{1\theta}} )$

Only $\vec{b_{1\theta}}$ is related to $\vec{B_{1\theta}}$. 
$\hat{e_z}b^\ast_{1\nabla\times v_E} $ is not related to $\vec{B_{1\theta}}$.

Only zero-order $\nabla B$ in $\vec{D}$ so, 

$v_{Bwave} = c \vec{D}\times \frac{\vec{b_{1\theta}}}{B_{0z}}$


$ = c \frac{\mu}{q}\frac{\partial B_{0z}}{\partial r}\hat{e_r} \times \frac{\vec{b_{1\theta}}}{B_{0z}}$

$ = c \frac{\mu}{q}\frac{\partial B_{0z}}{\partial r}\frac{{b_{1\theta}}}{B_{0z}} \hat{e_z}$

grad B drift : 
$v_{\nabla} = -c \frac{\mu}{q}\frac{\partial B_{0z}}{\partial r}\frac{{b_{0\theta}}}{B_{0z}} \hat{e_\theta}$

so, $\frac{v_{Bwave}}{v_{\nabla}} = \frac{b_{1\theta}}{b_{0\theta}} = \frac{B_{1\theta}}{B_{0z}} \approx 10^{-2}$

Now, $v_\nabla$ and $v_{EB}$ is same order, so we can negelect $B_{1\theta}$