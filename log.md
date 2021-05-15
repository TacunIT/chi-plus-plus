---
layout:     pagina
class:      elenco
title:      Diario di bordo
permalink:  /log/
---

<section class="elenco post">
    {% for post in site.posts %}
        <div class="log">
            <a class="more" href="{{ post.url }}">
                <h3>{{ post.title }}</h3>
            </a>
            <p class="data">{{ post.date | date_to_string }}</p>
            <p class="tag"><label>tag</label> {{ post.tags | sort | join: ", " }}</p>
            {% if post.excerpt != "" %}
                {{ post.excerpt }}
                <a class="more" href="{{ post.url | relative_url}}">leggi tutto</a>
            {% else %}
                {{ post.content }}
            {% endif %}
        </div>
    {% endfor %}
</section>
