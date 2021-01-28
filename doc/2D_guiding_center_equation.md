# Guiding Center Equation

reference :: https://agupubs.onlinelibrary.wiley.com/doi/full/10.1029/2010JA015682

CGS

$\frac{\partial f}{\partial t}+\vec{v} \cdot \frac{\partial f}{\partial \vec{x}} = 0$

$\vec{v} = \frac{\vec{D}}{B_\parallel^\ast} \times \vec{b}$

$\vec{D} = \vec{E}-\frac{\mu}{q}\nabla \vec{B} - \frac{m}{q}(\frac{\partial \vec{v_E}}{\partial t}+\nabla \frac{v_E^2}{2})$

$\vec{v_E} =\frac{c}{B} \vec{E}\times \vec{b}$

$\vec{B^\ast} = \vec{B} + \frac{m}{q}(\nabla\times\vec{v_E})$

$B^\ast_\parallel = \vec{B^\ast} \cdot \vec{b}$

$B = |\vec{B}|$


$\vec{B}(\vec{m},\vec{r}) = \frac{\mu_0}{4\pi}\frac{3(\vec{m}\cdot \vec{\hat{r}})\vec{\hat{r}}-\vec{m}}{r^3}$

$\vec{\hat{r}}=\frac{\vec{r}}{r}$

Below We use cylindrical coordinates

$\vec{x} = (r,\theta,z)$

$\nabla f=\frac{\partial f}{\partial r}\vec{e_r} + \frac{1}{r}\frac{\partial f}{\partial \theta}\vec{e_\theta} + \frac{\partial f}{\partial z}\vec{e_z}$

$\nabla \cdot \vec{A}=\frac{1}{r}(\frac{\partial (rA_r)}{\partial r} + \frac{\partial A_\theta}{\partial \theta} + r\frac{\partial A_z}{\partial z})$

$\nabla \times \vec{A}=(\frac{1}{r}\frac{\partial A_z}{\partial \theta}-\frac{\partial A_\theta}{\partial z})\vec{e_r} + (\frac{\partial A_r}{\partial z}+\frac{\partial A_z}{\partial r})\vec{e_\theta} + \frac{1}{r}(\frac{\partial (rA_\theta)}{\partial r}-\frac{\partial A_r}{\partial \theta})\vec{e_z}$

Toroidal mode wave

ULF waves

$\vec{B}_{wave} = \vec{e _{\theta}}B_Asin(\omega(t-\frac{r\theta}{v}))$

$ =\vec{e_\theta} B_Asin(m\omega_d(t-\frac{r\theta}{v}))$

$=\vec{e_\theta} B_Asin(m2\pi(\frac{t}{T}-\frac{r\theta}{\lambda}))$

$\vec{E}_{wave} = \vec{e_r} E_Asin(m2\pi(\frac{t}{T}-\frac{r\theta}{\lambda})+\frac{\pi}{2})$


$\vec{B_0}= \frac{\mu_0}{4\pi}\frac{3(\vec{m}\cdot \vec{\hat{x}})\vec{\hat{x}}-\vec{m}}{|\vec{x}|^3}$

$\vec{m} = m\vec{e_z}$

$\vec{B_0} = \frac{\mu_0}{4\pi}\frac{3mz \vec{\hat{x}}-m \vec{e_z} }{|\vec{x}|^3}$


$\vec{E_0} = \vec{0}$

$\vec{E} = \vec{E_0}+\vec{E}_{wave} = \vec{E} _{wave}$

$\vec{B} = \vec{B_0}+\vec{B}_{wave}$





Apply to the fomula

$\vec{v_E} =\frac{\vec{E}}{B} \times \vec{b}$

$=\frac{\vec{E} _{wave}}{|B|^2}\times \vec{B}$

$\vec{B^\ast} = \vec{B} + \frac{m}{q}(\nabla\times\vec{v_E})$

$= \vec{B}+\frac{m}{q}(\nabla \times (\frac{\vec{E} _{wave}}{|B|^2}\times \vec{B}))$

$= \vec{B}+\frac{m}{q}((\nabla \cdot \vec{B})\frac{\vec{E} _{wave}}{|B|^2} - (\nabla \cdot \frac{\vec{E} _{wave}}{|B|^2}) \vec{B})$

$\vec{D} = \vec{E}-\frac{\mu}{q}\nabla \vec{B} - \frac{m}{q}(\frac{\partial \vec{v_E}}{\partial t}+\nabla \frac{v_E^2}{2})$

$= \vec{E}-\frac{\mu}{q}\nabla \vec{B} - \frac{m}{q}(\frac{\partial}{\partial t}(\frac{\vec{E} _{wave}}{|B|^2}\times \vec{B})+\frac{1}{2}\nabla|\frac{\vec{E} _{wave}}{|B|^2}\times \vec{B}|^2)$

Assumption $\vec{B}_{wave}<<\vec{B_0}$

$\vec{B} = \vec{B_0}$

$\vec{b} = \vec{e_z}$ (only in the case of no spatial differentiation)

$\vec{D} = \vec{E}-\frac{\mu}{q}\nabla \vec{B} - \frac{m}{q}(\frac{\partial\vec{E} _{wave}}{\partial t}\times\frac{ \vec{B}}{|B|^2}+\frac{1}{2}\nabla|\frac{\vec{E} _{wave}}{|B|^2}\times \vec{B}|^2)$


$\vec{v} = \frac{\vec{D}}{B_\parallel^\ast} \times \vec{b}$

$\vec{v} = \frac{ \vec{E}-\frac{\mu}{q}\nabla \vec{B} - \frac{m}{q}(\frac{\partial\vec{E} _{wave}}{\partial t}\times\frac{ \vec{B}}{|B|^2}+\frac{1}{2}\nabla|\frac{\vec{E} _{wave}}{|B|^2}\times \vec{B}|^2)++}{(\vec{B}+\frac{m}{q}((\nabla \cdot \vec{B})\frac{\vec{E} _{wave}}{|B|^2} - (\nabla \cdot \frac{\vec{E} _{wave}}{|B|^2}) \vec{B})\cdot \vec{e_z}} \times \vec{e_z}$